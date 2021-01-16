// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ASH_ASSISTANT_MODEL_ASSISTANT_RESPONSE_H_
#define ASH_ASSISTANT_MODEL_ASSISTANT_RESPONSE_H_

#include <map>
#include <memory>
#include <vector>

#include "base/callback.h"
#include "base/component_export.h"
#include "base/macros.h"
#include "base/memory/ref_counted.h"
#include "chromeos/services/assistant/public/mojom/assistant.mojom-forward.h"

namespace ash {

class AssistantUiElement;

// Models a renderable Assistant response.
// It is refcounted so that views that display the response can safely
// reference the data inside this response.
class COMPONENT_EXPORT(ASSISTANT_MODEL) AssistantResponse
    : public base::RefCounted<AssistantResponse> {
 public:
  using AssistantSuggestion = chromeos::assistant::mojom::AssistantSuggestion;
  using AssistantSuggestionPtr =
      chromeos::assistant::mojom::AssistantSuggestionPtr;

  using ProcessingCallback = base::OnceCallback<void(bool)>;

  enum class ProcessingState {
    kUnprocessed,  // Response has not yet been processed.
    kProcessing,   // Response is currently being processed.
    kProcessed,    // Response has finished processing.
  };

  AssistantResponse();

  // Adds the specified |ui_element| that should be rendered for the
  // interaction.
  void AddUiElement(std::unique_ptr<AssistantUiElement> ui_element);

  // Returns all UI elements belonging to the response.
  const std::vector<std::unique_ptr<AssistantUiElement>>& GetUiElements() const;

  // Adds the specified |suggestions| that should be rendered for the
  // interaction.
  void AddSuggestions(std::vector<AssistantSuggestionPtr> suggestions);

  // Returns the suggestion uniquely identified by |id|.
  const AssistantSuggestion* GetSuggestionById(int id) const;

  // Returns all suggestions belongs to the response, mapped to a unique id.
  std::map<int, const AssistantSuggestion*> GetSuggestions() const;

  // Gets/sets the processing state for the response.
  ProcessingState processing_state() const { return processing_state_; }
  void set_processing_state(ProcessingState processing_state) {
    processing_state_ = processing_state;
  }

  // Gets/sets if the response has TTS. This can only be reliably checked after
  // the response is finalized for obvious reasons.
  bool has_tts() const { return has_tts_; }
  void set_has_tts(bool has_tts) { has_tts_ = has_tts; }

  // Invoke to begin processing the response. The specified |callback| will be
  // run to indicate whether or not the processor has completed processing of
  // all UI elements in the response.
  void Process(ProcessingCallback callback);

 private:
  class Processor;

  friend class base::RefCounted<AssistantResponse>;
  ~AssistantResponse();

  std::vector<AssistantSuggestionPtr> suggestions_;
  ProcessingState processing_state_ = ProcessingState::kUnprocessed;
  bool has_tts_ = false;

  // We specify the declaration order below as intended because we want
  // |processor_| to be destroyed before |ui_elements_| (we also forced this
  // order in the destructor), so that when the response processing got
  // interrupted, the |ProcessingCallback| can have a chance to return false
  // during the destruction to indicate the failure of completion.
  std::vector<std::unique_ptr<AssistantUiElement>> ui_elements_;
  std::unique_ptr<Processor> processor_;

  DISALLOW_COPY_AND_ASSIGN(AssistantResponse);
};

}  // namespace ash

#endif  // ASH_ASSISTANT_MODEL_ASSISTANT_RESPONSE_H_
