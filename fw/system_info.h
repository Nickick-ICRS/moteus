// Copyright 2015-2022 Josh Pieper, jjp@pobox.com.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "mjlib/micro/pool_ptr.h"
#include "mjlib/micro/telemetry_manager.h"

namespace moteus {

/// This class keeps track of things like how many main loops we
/// execute per primary event, and other system health issues like
/// memory usage.
class SystemInfo {
 public:
  SystemInfo(mjlib::micro::Pool&, mjlib::micro::TelemetryManager&);
  ~SystemInfo();

  void PollMillisecond();
  void SetCanResetCount(uint32_t);

  uint32_t millisecond_counter() const;

  // Increment this from an idle thread.
  static volatile uint32_t idle_count;

 private:
  class Impl;
  mjlib::micro::PoolPtr<Impl> impl_;
};

}
