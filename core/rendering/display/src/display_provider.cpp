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

#include "display_provider.h"
#include "display_port.h"

namespace ngen {
    DisplayProvider::DisplayProvider()
    : m_displayPortCount(0)
    {
        //
    }

    DisplayProvider::~DisplayProvider() {
        assert( 0 == m_displayPortCount );
    }


    //! \brief  Called when it is time for all display ports to be rendered.
    void DisplayProvider::onRender() {
        for (size_t loop = 0; loop < m_displayPortCount; ++loop) {
            m_displayPorts[loop]->onRender();
        }
    }


    bool DisplayProvider::deletePort( DisplayPort *port ) {
        for ( size_t loop = 0; loop < m_displayPortCount; ++loop ) {
            if ( m_displayPorts[ loop ] == port ) {
                delete m_displayPorts[ loop ];

                m_displayPorts[ loop ] = m_displayPorts[ --m_displayPortCount ];
                return true;
            }
        }

        return false;
    }


    //! \brief  Creates a new display port and associates it with a specified rendering pipeline.
    //! \param  pipeline [in] -
    //!         Name of the rendering pipeline to be associated with the new display port.
    //! \return New DisplayPort instance, if the pipeline could not be found or the display port could not be created this method returns <em>nullptr</em>.
    DisplayPort* DisplayProvider::createDisplayPort(const char *pipeline) {
        if ( m_displayPortCount < kDisplayPortCapacity ) {
            DisplayPort *displayPort = new DisplayPort();       // TODO: Use allocator
            if (displayPort->initialize(m_requestProvider)) {
                m_displayPorts[m_displayPortCount++] = displayPort;
                return displayPort;
            }

            delete displayPort;
        }

        return nullptr;
    }
}
