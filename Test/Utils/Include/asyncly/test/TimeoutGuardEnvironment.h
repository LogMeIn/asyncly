/*
 * Copyright 2019 LogMeIn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <ctime>
#include <memory>

#include <boost/noncopyable.hpp>

#include <gtest/gtest.h>

namespace asyncly {
namespace test {

class TimeoutGuard;

/// Wraps TimeoutGuard in a Google Test enviroment
class TimeoutGuardEnviroment : public ::testing::Environment, boost::noncopyable {
  public:
    TimeoutGuardEnviroment(std::time_t timeoutInSec);

  private:
    std::unique_ptr<TimeoutGuard> m_timeoutGuard;

    void SetUp() override;

    void TearDown() override;
};
}
} // namespace asyncly::test
