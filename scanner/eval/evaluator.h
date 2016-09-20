/* Copyright 2016 Carnegie Mellon University
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
 */

#pragma once

#include "scanner/util/common.h"
#include "scanner/util/profiler.h"

#include <vector>

namespace scanner {

class Evaluator {
public:
  virtual ~Evaluator() {};

  virtual void configure(const DatasetItemMetadata& metadata) = 0;

  virtual void evaluate(
    u8* input_buffer,
    std::vector<std::vector<u8*>>& output_buffers,
    std::vector<std::vector<size_t>>& output_sizes,
    i32 batch_size) = 0;

  void set_profiler(Profiler* profiler) {
    profiler_ = profiler;
  }

protected:
  Profiler* profiler_ = nullptr;
};

// allocate buffers
// setup
// set batch size
// consume input
// produce output
// teardown
// deallocate buffers

}