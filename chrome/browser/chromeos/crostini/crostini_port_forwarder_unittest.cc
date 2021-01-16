// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/crostini/crostini_port_forwarder.h"

#include "chrome/browser/chromeos/crostini/crostini_test_helper.h"
#include "chrome/test/base/testing_profile.h"
#include "chromeos/dbus/permission_broker/fake_permission_broker_client.h"
#include "content/public/test/browser_task_environment.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

using testing::Mock;
using testing::Return;

void TestingCallback(bool* out, bool in) {
  *out = in;
}

namespace crostini {

class CrostiniPortForwarderTest : public testing::Test {
 public:
  CrostiniPortForwarderTest() {}

  ~CrostiniPortForwarderTest() override {}

  void SetUp() override {
    chromeos::PermissionBrokerClient::InitializeFake();
    profile_ = std::make_unique<TestingProfile>();
    test_helper_ = std::make_unique<CrostiniTestHelper>(profile_.get());
    crostini_port_forwarder_ =
        std::make_unique<CrostiniPortForwarder>(profile());
  }

  void TearDown() override {
    chromeos::PermissionBrokerClient::Shutdown();
    crostini_port_forwarder_.reset();
    test_helper_.reset();
    profile_.reset();
  }

 protected:
  Profile* profile() { return profile_.get(); }

  std::unique_ptr<CrostiniTestHelper> test_helper_;
  std::unique_ptr<TestingProfile> profile_;
  std::unique_ptr<CrostiniPortForwarder> crostini_port_forwarder_;
  content::BrowserTaskEnvironment task_environment_;

 private:
  DISALLOW_COPY_AND_ASSIGN(CrostiniPortForwarderTest);
};

TEST_F(CrostiniPortForwarderTest, AddPortTcpSuccess) {
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::TCP,
                                    "tcp-port",
                                    base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));
}

TEST_F(CrostiniPortForwarderTest, AddPortUdpSuccess) {
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port",
                                    base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
}

TEST_F(CrostiniPortForwarderTest, AddPortDuplicateFail) {
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port",
                                    base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            1U);

  // Leave success as == true.
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port-duplicate",
                                    base::BindOnce(&TestingCallback, &success));
  EXPECT_FALSE(success);
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            1U);
}

TEST_F(CrostiniPortForwarderTest, AddPortUdpAndTcpSuccess) {
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port",
                                    base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);

  success = false;
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::TCP,
                                    "tcp-port",
                                    base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            2U);
}

TEST_F(CrostiniPortForwarderTest, AddPortMultipleSuccess) {
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port", base::DoNothing());
  crostini_port_forwarder_->AddPort(5001, CrostiniPortForwarder::Protocol::TCP,
                                    "tcp-port", base::DoNothing());
  crostini_port_forwarder_->AddPort(5002, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port", base::DoNothing());
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            3U);
}

TEST_F(CrostiniPortForwarderTest, ActivateTcpPortSuccess) {
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->ActivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
}

TEST_F(CrostiniPortForwarderTest, TryActivatePortPermissionBrokerClientFail) {
  bool success = false;
  crostini_port_forwarder_->TryActivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP, "tcp-port",
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            1U);
  chromeos::PermissionBrokerClient::Shutdown();

  // Leave success as == true.
  crostini_port_forwarder_->TryActivatePort(
      5001, CrostiniPortForwarder::Protocol::TCP, "tcp-port",
      base::BindOnce(&TestingCallback, &success));
  EXPECT_FALSE(success);
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            1U);
  // Re-initialize otherwise Shutdown in TearDown phase will break.
  chromeos::PermissionBrokerClient::InitializeFake();
}

TEST_F(CrostiniPortForwarderTest, DeactivatePortTcpSuccess) {
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::TCP,
                                    "tcp-port", base::DoNothing());
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);
}

TEST_F(CrostiniPortForwarderTest, DeactivatePortUdpSuccess) {
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port", base::DoNothing());
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::UDP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);
}

TEST_F(CrostiniPortForwarderTest, DeactivateNonExistentPortFail) {
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_FALSE(success);

  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::UDP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_FALSE(success);
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);
}

TEST_F(CrostiniPortForwarderTest, DeactivateWrongProtocolFail) {
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port", base::DoNothing());
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_FALSE(success);
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasUdpPortForward(
      5000, "wlan0"));
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            1U);
}

TEST_F(CrostiniPortForwarderTest, DeactivatePortTwiceFail) {
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::TCP,
                                    "tcp-port", base::DoNothing());
  EXPECT_TRUE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));

  bool success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_FALSE(chromeos::FakePermissionBrokerClient::Get()->HasTcpPortForward(
      5000, "wlan0"));
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);

  success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_FALSE(success);
}

TEST_F(CrostiniPortForwarderTest, DeactivateMultiplePortsSameProtocolSuccess) {
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::TCP,
                                    "tcp-port", base::DoNothing());
  crostini_port_forwarder_->AddPort(5000, CrostiniPortForwarder::Protocol::UDP,
                                    "udp-port", base::DoNothing());
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            2U);

  bool success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::TCP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);

  success = false;
  crostini_port_forwarder_->DeactivatePort(
      5000, CrostiniPortForwarder::Protocol::UDP,
      base::BindOnce(&TestingCallback, &success));
  EXPECT_TRUE(success);
  EXPECT_EQ(crostini_port_forwarder_->GetNumberOfForwardedPortsForTesting(),
            0U);
}

// TODO(matterchen): At this point in time, remove port and deactivate port are
// identical. Implement unit tests for remove port when port forwarding
// profile preferences tracking is implemented.

}  // namespace crostini
