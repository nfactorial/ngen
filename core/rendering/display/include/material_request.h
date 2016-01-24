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

#ifndef NGEN_MATERIAL_REQUEST_H
#define NGEN_MATERIAL_REQUEST_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>


////////////////////////////////////////////////////////////////////////////

class Material;


////////////////////////////////////////////////////////////////////////////

struct MaterialRequest
{
    size_t      materialId;             //!< Identifier of the material in this list
    size_t      drawRequests;           //!< Number of draw requests for this material
    Material    *material;              //!< Material associated with this request
};


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_MATERIAL_REQUEST_H
