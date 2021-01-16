// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/service_manager/sandbox/sandbox_type.h"

#include "base/command_line.h"
#include "build/build_config.h"
#include "services/service_manager/sandbox/switches.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace service_manager {

TEST(SandboxTypeTest, Empty) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitchASCII(switches::kServiceSandboxType, "network");
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));

#if defined(OS_WIN)
  EXPECT_FALSE(
      command_line.HasSwitch(switches::kNoSandboxAndElevatedPrivileges));
  SetCommandLineFlagsForSandboxType(
      &command_line, SandboxType::kNoSandboxAndElevatedPrivileges);
  EXPECT_EQ(SandboxType::kNoSandboxAndElevatedPrivileges,
            SandboxTypeFromCommandLine(command_line));
#endif

  EXPECT_FALSE(command_line.HasSwitch(switches::kNoSandbox));
  SetCommandLineFlagsForSandboxType(&command_line, SandboxType::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
  EXPECT_TRUE(command_line.HasSwitch(switches::kNoSandbox));
}

TEST(SandboxTypeTest, Renderer) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  command_line.AppendSwitchASCII(switches::kProcessType,
                                 switches::kRendererProcess);
  EXPECT_EQ(SandboxType::kRenderer, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitchASCII(switches::kServiceSandboxType, "network");
  EXPECT_EQ(SandboxType::kRenderer, SandboxTypeFromCommandLine(command_line));

  EXPECT_FALSE(command_line.HasSwitch(switches::kNoSandbox));
  SetCommandLineFlagsForSandboxType(&command_line, SandboxType::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
  EXPECT_TRUE(command_line.HasSwitch(switches::kNoSandbox));
}

TEST(SandboxTypeTest, Utility) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  command_line.AppendSwitchASCII(switches::kProcessType,
                                 switches::kUtilityProcess);
  EXPECT_EQ(SandboxType::kUtility, SandboxTypeFromCommandLine(command_line));

  base::CommandLine command_line2(command_line);
  SetCommandLineFlagsForSandboxType(&command_line2, SandboxType::kNetwork);
  EXPECT_EQ(SandboxType::kNetwork, SandboxTypeFromCommandLine(command_line2));

  base::CommandLine command_line3(command_line);
  SetCommandLineFlagsForSandboxType(&command_line3, SandboxType::kCdm);
  EXPECT_EQ(SandboxType::kCdm, SandboxTypeFromCommandLine(command_line3));

  base::CommandLine command_line4(command_line);
  SetCommandLineFlagsForSandboxType(&command_line4, SandboxType::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line4));

  base::CommandLine command_line5(command_line);
  SetCommandLineFlagsForSandboxType(&command_line5, SandboxType::kPpapi);
  EXPECT_EQ(SandboxType::kPpapi, SandboxTypeFromCommandLine(command_line5));

  base::CommandLine command_line6(command_line);
  command_line6.AppendSwitchASCII(switches::kServiceSandboxType, "bogus");
  EXPECT_EQ(SandboxType::kUtility, SandboxTypeFromCommandLine(command_line6));

  base::CommandLine command_line7(command_line);
  SetCommandLineFlagsForSandboxType(&command_line7,
                                    SandboxType::kPrintCompositor);
  EXPECT_EQ(SandboxType::kPrintCompositor,
            SandboxTypeFromCommandLine(command_line7));

  command_line.AppendSwitch(switches::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
}

TEST(SandboxTypeTest, GPU) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  command_line.AppendSwitchASCII(switches::kProcessType, switches::kGpuProcess);
  SetCommandLineFlagsForSandboxType(&command_line, SandboxType::kGpu);
  EXPECT_EQ(SandboxType::kGpu, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitchASCII(switches::kServiceSandboxType, "network");
  EXPECT_EQ(SandboxType::kGpu, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitch(switches::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
}

TEST(SandboxTypeTest, PPAPIBroker) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  command_line.AppendSwitchASCII(switches::kProcessType,
                                 switches::kPpapiBrokerProcess);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitchASCII(switches::kServiceSandboxType, "network");
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitch(switches::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
}

TEST(SandboxTypeTest, PPAPIPlugin) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  command_line.AppendSwitchASCII(switches::kProcessType,
                                 switches::kPpapiPluginProcess);
  SetCommandLineFlagsForSandboxType(&command_line, SandboxType::kPpapi);
  EXPECT_EQ(SandboxType::kPpapi, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitchASCII(switches::kServiceSandboxType, "network");
  EXPECT_EQ(SandboxType::kPpapi, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitch(switches::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
}

TEST(SandboxTypeTest, Nonesuch) {
  base::CommandLine command_line(base::CommandLine::NO_PROGRAM);
  command_line.AppendSwitchASCII(switches::kProcessType, "nonesuch");
  EXPECT_EQ(SandboxType::kInvalid, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitchASCII(switches::kServiceSandboxType, "network");
  EXPECT_EQ(SandboxType::kInvalid, SandboxTypeFromCommandLine(command_line));

  command_line.AppendSwitch(switches::kNoSandbox);
  EXPECT_EQ(SandboxType::kNoSandbox, SandboxTypeFromCommandLine(command_line));
}

TEST(SandboxTypeTest, ElevatedPrivileges) {
  // Tests that the "no sandbox and elevated privileges" which is Windows
  // specific default to no sandbox on non Windows platforms.
  SandboxType elevated_type =
      UtilitySandboxTypeFromString(switches::kNoneSandboxAndElevatedPrivileges);
#if defined(OS_WIN)
  EXPECT_EQ(SandboxType::kNoSandboxAndElevatedPrivileges, elevated_type);
#else
  EXPECT_EQ(SandboxType::kNoSandbox, elevated_type);
#endif
}

}  // namespace service_manager
