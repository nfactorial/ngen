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

#ifndef NGEN_CAMER_TYPE_H
#define NGEN_CAMER_TYPE_H


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    //! \brief  Defines the types of camera supported by the rendering engine.
    enum kCamera_Type {
        kCamera_Invalid,
        kCamera_Orthographic,
        kCamera_Perspective,
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_CAMER_TYPE_H