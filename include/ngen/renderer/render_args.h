//
// Copyright 2016 nfactorial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef NGEN_RENDER_ARGS_H
#define NGEN_RENDER_ARGS_H


////////////////////////////////////////////////////////////////////////////

#include <vectormath_aos.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    //! \brief  Parameters for the current frame being rendered.
    struct RenderArgs {
        Vectormath::Aos::Vector3    cameraPos;          // Position of camera in world space
        Vectormath::Aos::Matrix4    viewTransform;      // World to view transform
        Vectormath::Aos::Matrix4    invViewTransform;   // View to world transform
        Vectormath::Aos::Matrix4    projection;         // Projection transform for the pipeline
        Vectormath::Aos::Matrix4    viewProjection;     // Concatenated view and projection transform
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_RENDER_ARGS_H
