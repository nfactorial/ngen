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

#ifndef NGEN_BLEND_MODE_H
#define NGEN_BLEND_MODE_H


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    enum kBlendMode {
        kBlendMode_Zero,
        kBlendMode_One,
        kBlendMode_SrcColor,
        kBlendMode_InvSrcColor,
        kBlendMode_SrcAlpha,
        kBlendMode_InvSrcAlpha,
        kBlendMode_DestAlpha,
        kBlendMode_InvDestAlpha,
        kBlendMode_DestColor,
        kBlendMode_InvDestColor
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_BLEND_MODE_H
