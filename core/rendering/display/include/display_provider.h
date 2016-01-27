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

#ifndef NGEN_DISPLAY_PROVIDER_H
#define NGEN_DISPLAY_PROVIDER_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include "request_provider.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class DisplayPort;

    const size_t kDisplayPortCapacity   = 16;

    //! \brief  Manages all renderable displays within the running title.
    class DisplayProvider {
    public:
        DisplayProvider();
        ~DisplayProvider();

        void onRender();

        bool deletePort( DisplayPort *port );
        DisplayPort* createDisplayPort(const char *pipeline);

        size_t getDisplayPortCount() const;

    private:
        RequestProvider m_requestProvider;

        size_t m_displayPortCount;
        std::array< DisplayPort*, kDisplayPortCapacity > m_displayPorts;
    };


    ////////////////////////////////////////////////////////////////////////////

    //! \brief  Retrieves the number of display ports contained within the provider.
    //! \return The number of display ports within the provider.
    inline size_t DisplayProvider::getDisplayPortCount() const {
        return m_displayPortCount;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DISPLAY_PROVIDER_H
