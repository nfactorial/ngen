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

#ifndef NGEN_TEXTURE_DESC_H
#define NGEN_TEXTURE_DESC_H


////////////////////////////////////////////////////////////////////////////

#include "surface_format.h"
#include "texture_type.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    //! \brief  Describes a texture object within the system.
    struct TextureDesc {
        bool            renderTarget;
        int             width;
        int             height;
        kTextureType    type;
        kSurfaceFormat  format;
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_TEXTURE_DESC_H
