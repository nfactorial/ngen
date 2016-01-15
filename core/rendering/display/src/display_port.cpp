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


//! \brief  Discards the display port and removes it from memory.
void DisplayPort::dispose() {
    //
}


//! \brief  Enables or disables the display port.
//!
//! If a display port is disabled, its content will not be rendered.
//!
//! \param  isEnabled [in] -
//!         <em>True</em> to enable the display port or <em>false</em> to disable.
void DisplayPort::setEnabled( bool isEnabled )
{
    m_isEnabled = isEnabled;
}


//! \brief  Retreives teh current camera arguments assigned to this display port.
//! \param  cameraArgs [out] -
//!         Structure that will receive the properties describing the camera attached tot the display port.
void DisplayPort::getCameraArgs( ngen::CameraArgs &cameraArgs )
{
    cameraArgs = m_camera;
}


//! \brief  Called by the framework when it is time for our display port to perform its rendering.
void DisplayPort::onRender() {
    if ( m_isEnabled && ngen::kCamera_Invalid != m_camera.type ) {
        // TODO: Calculate projection transform for camera
        // TODO: Calculate view transform for camera

        m_pipeline.execute();
    }
}
