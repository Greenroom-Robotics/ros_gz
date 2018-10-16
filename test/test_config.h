/*
 * Copyright (C) 2018 Open Source Robotics Foundation
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
*/

#ifndef ROS1_IGN_BRIDGE__TEST_CONFIG_HH_
#define ROS1_IGN_BRIDGE__TEST_CONFIG_HH_

#include "ros/ros.h"
#include <chrono>
#include <thread>

namespace ros1_ign_bridge
{
  /// \brief Wait until a boolean variable is set to true for a given number
  /// of times.
  /// \param[in out] _boolVar The bool variable.
  /// \param[in] _sleepEach Time duration to wait between each retry.
  /// \param[in] _retries The number of retries.
  ///
  /// E.g.:
  ///   using namespace std::chrono_literals;
  ///   waitUntilBoolVar(myVar, 1ms, 10);
  template <class Rep, class Period>
  void waitUntilBoolVar(
      bool &_boolVar,
      const std::chrono::duration<Rep, Period> &_sleepEach,
      const int _retries)
  {
    int i = 0;
    while (!_boolVar && i < _retries)
    {
      ++i;
      std::this_thread::sleep_for(_sleepEach);
    }
  }

  /// \brief Wait until a boolean variable is set to true for a given number
  /// of times. This function calls ros::spinOnce each iteration.
  /// \param[in out] _boolVar The bool variable.
  /// \param[in] _sleepEach Time duration to wait between each retry.
  /// \param[in] _retries The number of retries.
  ///
  /// E.g.:
  ///   using namespace std::chrono_literals;
  ///   waitUntilBoolVar(myVar, 1ms, 10);
  template <class Rep, class Period>
  void waitUntilBoolVarAndSpin(
      bool &_boolVar,
      const std::chrono::duration<Rep, Period> &_sleepEach,
      const int _retries)
  {
    int i = 0;
    while (!_boolVar && i < _retries)
    {
      ++i;
      std::this_thread::sleep_for(_sleepEach);
      ros::spinOnce();
    }
  }
}

#endif  // header guard
