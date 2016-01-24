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

#ifndef NGEN_DRAW_REQUEST_H
#define NGEN_DRAW_REQUEST_H


////////////////////////////////////////////////////////////////////////////

#include <vectormath_aos.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class Geometry;
    class Material;

    //! \brief  A draw request represents a block of geometry to be rendered by the framework.
    struct DrawRequest {
        int layerId;
        Geometry *geometry;
        Material *material;
        Vectormath::Aos::Vector3    position;
        Vectormath::Aos::Matrix3    orientation;
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DRAW_REQUEST_H