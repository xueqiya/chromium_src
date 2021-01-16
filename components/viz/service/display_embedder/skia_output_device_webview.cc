// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/viz/service/display_embedder/skia_output_device_webview.h"

#include <utility>

#include "gpu/command_buffer/common/swap_buffers_complete_params.h"
#include "gpu/command_buffer/service/gl_utils.h"
#include "gpu/command_buffer/service/shared_context_state.h"
#include "third_party/skia/include/core/SkSurface.h"
#include "third_party/skia/include/gpu/GrContext.h"
#include "ui/gl/gl_bindings.h"
#include "ui/gl/gl_surface.h"

namespace viz {

SkiaOutputDeviceWebView::SkiaOutputDeviceWebView(
    gpu::SharedContextState* context_state,
    scoped_refptr<gl::GLSurface> gl_surface,
    gpu::MemoryTracker* memory_tracker,
    DidSwapBufferCompleteCallback did_swap_buffer_complete_callback)
    : SkiaOutputDevice(/*need_swap_semaphore=*/false,
                       memory_tracker,
                       std::move(did_swap_buffer_complete_callback)),
      context_state_(context_state),
      gl_surface_(std::move(gl_surface)) {
  capabilities_.flipped_output_surface = gl_surface_->FlipsVertically();
  capabilities_.max_frames_pending = gl_surface_->GetBufferCount() - 1;

  DCHECK(context_state_->gr_context());
  DCHECK(context_state_->context());

  // Get alpha bits from the default frame buffer.
  glBindFramebufferEXT(GL_FRAMEBUFFER, 0);
  context_state_->gr_context()->resetContext(kRenderTarget_GrGLBackendState);
  GLint alpha_bits = 0;
  glGetIntegerv(GL_ALPHA_BITS, &alpha_bits);
  CHECK_GL_ERROR();
  supports_alpha_ = alpha_bits > 0;
}

SkiaOutputDeviceWebView::~SkiaOutputDeviceWebView() = default;

bool SkiaOutputDeviceWebView::Reshape(const gfx::Size& size,
                                      float device_scale_factor,
                                      const gfx::ColorSpace& color_space,
                                      bool has_alpha,
                                      gfx::OverlayTransform transform) {
  DCHECK_EQ(transform, gfx::OVERLAY_TRANSFORM_NONE);

  if (!gl_surface_->Resize(size, device_scale_factor, color_space, has_alpha)) {
    DLOG(ERROR) << "Failed to resize.";
    return false;
  }

  size_ = size;
  color_space_ = color_space;

  InitSkiaSurface(gl_surface_->GetBackingFramebufferObject());
  return !!sk_surface_;
}

void SkiaOutputDeviceWebView::SwapBuffers(
    BufferPresentedCallback feedback,
    std::vector<ui::LatencyInfo> latency_info) {
  StartSwapBuffers({});

  gfx::Size surface_size =
      gfx::Size(sk_surface_->width(), sk_surface_->height());

  FinishSwapBuffers(gl_surface_->SwapBuffers(std::move(feedback)), surface_size,
                    std::move(latency_info));
}

SkSurface* SkiaOutputDeviceWebView::BeginPaint() {
  DCHECK(sk_surface_);

  unsigned int fbo = gl_surface_->GetBackingFramebufferObject();

  if (last_frame_buffer_object_ != fbo) {
    InitSkiaSurface(fbo);
  }

  return sk_surface_.get();
}

void SkiaOutputDeviceWebView::EndPaint(const GrBackendSemaphore& semaphore) {}

void SkiaOutputDeviceWebView::InitSkiaSurface(unsigned int fbo) {
  last_frame_buffer_object_ = fbo;

  SkSurfaceProps surface_props =
      SkSurfaceProps(0, SkSurfaceProps::kLegacyFontHost_InitType);

  GrGLFramebufferInfo framebuffer_info;
  framebuffer_info.fFBOID = fbo;

  SkColorType color_type;
  if (supports_alpha_) {
    framebuffer_info.fFormat = GL_RGBA8;
    color_type = kRGBA_8888_SkColorType;
  } else {
    framebuffer_info.fFormat = GL_RGB8_OES;
    color_type = kRGB_888x_SkColorType;
  }

  GrBackendRenderTarget render_target(size_.width(), size_.height(), 0, 8,
                                      framebuffer_info);
  auto origin = gl_surface_->FlipsVertically() ? kTopLeft_GrSurfaceOrigin
                                               : kBottomLeft_GrSurfaceOrigin;
  sk_surface_ = SkSurface::MakeFromBackendRenderTarget(
      context_state_->gr_context(), render_target, origin, color_type,
      color_space_.ToSkColorSpace(), &surface_props);

  if (!sk_surface_) {
    LOG(ERROR) << "Couldn't create surface: "
               << context_state_->gr_context()->abandoned() << " " << color_type
               << " " << framebuffer_info.fFBOID << " "
               << framebuffer_info.fFormat << " " << color_space_.ToString()
               << " " << size_.ToString();
  }
}

}  // namespace viz
