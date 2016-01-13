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


////////////////////////////////////////////////////////////////////////////

class DisplayPort;


////////////////////////////////////////////////////////////////////////////

#define NGEN_MAXIMUM_DISPLAY_PORTS      16


////////////////////////////////////////////////////////////////////////////

class DisplayProvider {
public:
    DisplayProvider();
    ~DisplayProvider();

    void onRender();

    DisplayPort* createDisplayPort( const char *pipeline );

    size_t getDisplayPortCount() const;

private:
    size_t m_displayPortCount;
    DisplayPort *m_displayPorts[ NGEN_MAXIMUM_DISPLAY_PORTS ];
};


////////////////////////////////////////////////////////////////////////////

//! \brief  Retrieves the number of display ports contained within the provider.
//! \return The number of display ports within the provider.
inline size_t DisplayProvider::getDisplayPortCount() const {
    return m_displayPortCount;
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DISPLAY_PROVIDER_H
