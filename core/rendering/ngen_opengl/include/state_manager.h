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

#ifndef NGEN_STATE_MANAGER_H
#define NGEN_STATE_MANAGER_H


////////////////////////////////////////////////////////////////////////////

#include <ngen/renderer/blend_mode.h>
#include <ngen/renderer/blend_func.h>
#include "state_value.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class StateManager {
    public:
        StateManager();
        ~StateManager();

        void invalidate();

        void setBlending( bool enabled, kBlendFunc blendFunc, kBlendMode blendMode );

    private:
        StateValue< bool > m_blendEnabled;
        StateValue< kBlendFunc > m_blendFunc;
        StateValue< kBlendMode > m_blendMode;
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_STATE_MANAGER_H
