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

namespace ngen {
    DisplayPort::DisplayPort()
    : m_requestProvider( nullptr )
    , m_isEnabled(true)
    {
        m_cameraArgs.type = ngen::kCamera_Invalid;
        m_cameraArgs.fov = 45.0f;
        m_cameraArgs.zNear = 0.1;
        m_cameraArgs.zFar = 200.0f;
    }

    DisplayPort::~DisplayPort() {
        //
    }


    //! \brief  Prepares the display port for use by the running title.
    //! \param  requestProvider [in] -
    //!         The request provider that will be used by the render layers.
    //! return  <em>True</em> if the display port initialized successfully otherwise <em>false</em>.
    bool DisplayPort::initialize( RequestProvider &requestProvider ) {
        if ( nullptr == m_requestProvider ) {
            m_requestProvider = &requestProvider;
            return true;
        }

        return false;
    }


    //! \brief  Discards the display port and removes it from memory.
    void DisplayPort::dispose() {
        m_requestProvider = nullptr;
    }


    //! \brief  Enables or disables the display port.
    //!
    //! If a display port is disabled, its content will not be rendered.
    //!
    //! \param  isEnabled [in] -
    //!         <em>True</em> to enable the display port or <em>false</em> to disable.
    void DisplayPort::setEnabled(bool isEnabled) {
        m_isEnabled = isEnabled;
    }


    //! \brief  Retreives teh current camera arguments assigned to this display port.
    //! \param  cameraArgs [out] -
    //!         Structure that will receive the properties describing the camera attached tot the display port.
    void DisplayPort::getCameraArgs(CameraArgs &cameraArgs) {
        cameraArgs = m_cameraArgs;
    }


    //! \brief  Called by the framework when it is time for our display port to perform its rendering.
    void DisplayPort::onRender() {
        if (m_isEnabled && ngen::kCamera_Invalid != m_cameraArgs.type) {
            prepareRenderArgs( m_cameraArgs, 1.0f );    // TODO: Supply appropriate aspect ratio

            m_pipeline.execute( m_renderArgs );
        }
    }


    //! \brief  Fills the RenderArgs structure with information appropriate for the rendered display.
    //! \param  cameraArgs [in] -
    //!         Description of the camera whose view is being rendered.
    //! \param  aspectRatio [in] -
    //!         Aspect ratio of the display.
    void DisplayPort::prepareRenderArgs( const CameraArgs &cameraArgs, float aspectRatio ) {
        m_renderArgs.cameraPos = cameraArgs.position;
        m_renderArgs.invViewTransform = Vectormath::Aos::Matrix4( cameraArgs.orientation, cameraArgs.position );
        m_renderArgs.viewTransform = Vectormath::Aos::inverse( m_renderArgs.invViewTransform );

        switch ( cameraArgs.type ) {
            case kCamera_Perspective:
                m_renderArgs.projection.perspective( cameraArgs.fov, aspectRatio, cameraArgs.zNear, cameraArgs.zFar );
                break;

            case kCamera_Orthographic:
                // TODO:
                break;

            case kCamera_Invalid:
                break;
        }

        m_renderArgs.viewProjection = m_renderArgs.viewTransform * m_renderArgs.projection;
    }
}
