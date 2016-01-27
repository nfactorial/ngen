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

#ifndef NGEN_REQUEST_PAGE_H
#define NGEN_REQUEST_PAGE_H


////////////////////////////////////////////////////////////////////////////

#include <array>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    struct RequestPage {
        static const size_t kRequestPageCapacity     = 64;

        RequestPage *nextPage;
        size_t items;
        std::array< GeometryRequest, kRequestPageCapacity > requests;
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_REQUEST_PAGE_H
