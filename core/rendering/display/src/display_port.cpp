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

#include "display_port.h"


////////////////////////////////////////////////////////////////////////////

DisplayPort::DisplayPort()
: m_isEnabled( true )
{
    m_camera.type = ngen::kCamera_Invalid;
    m_camera.fov  = 75.0f;
}

DisplayPort::~DisplayPort() {
    //
}


//! \brief  Called by the framework when it is time for our display port to perform its rendering.
void DisplayPort::onRender() {
    if ( m_isEnabled && ngen::kCamera_Invalid != m_camera.type ) {
        // TODO: Calculate projection transform for camera
        // TODO: Calculate view transform for camera

        m_pipeline.execute();
    }
}
