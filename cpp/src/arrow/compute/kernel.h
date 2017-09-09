// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef ARROW_COMPUTE_KERNEL_H
#define ARROW_COMPUTE_KERNEL_H

#include "arrow/array.h"

namespace arrow {

using internal::ArrayData;

namespace compute {

class FunctionContext;

/// \class OpKernel
/// \brief Base class for operator kernels
class ARROW_EXPORT OpKernel {
 public:
  virtual ~OpKernel() = default;
};

/// \class UnaryKernel
/// \brief An array-valued function of a single input argument
class ARROW_EXPORT UnaryKernel : public OpKernel {
 public:
  virtual Status Call(FunctionContext* ctx, const Array& input, ArrayData* out) = 0;
};

}  // namespace compute
}  // namespace arrow

#endif  // ARROW_COMPUTE_KERNEL_H
