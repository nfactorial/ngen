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

#include <ngen/renderer/draw_request.h>
#include <cassert>

#include "material.h"

namespace ngen {
    Material::Material()
    : m_layerId( -1 )
    , m_shadowEnabled( false )  // Query: Should material have this flag or the geometry?
    {
        //
    }

    Material::~Material()
    {
        //
    }


    //! \brief  Called once rendering for this material has completed.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    void Material::onBeginRendering( const RenderArgs &renderArgs ) {
        // TODO: Prepare material for use by OpenGL
    }


    //! \brief  Called once rendering for this material has completed.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    void Material::onEndRendering( const RenderArgs &renderArgs ) {
        // TODO: Perform any cleanup necessary for the material
    }


    //! \brief  Renders a list of draw requests using the current material.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    //! \param  requests [in] -
    //!         Pointer to list of draw requests that are to be rendered.
    //! \param  requestCount [in] -
    //!         Number of requests in the supplied list.
    void Material::execute( const RenderArgs &renderArgs, const GeometryRequest *requests, size_t requestCount ) {
        assert( nullptr != requests );

        // NOTE: The request list may be a linked-list instead of an array in the future.
        for ( size_t loop = 0; loop < requestCount; ++loop ) {
            executeRequest( renderArgs, requests[ loop ] );
        }
    }

    //! \brief  Renders a single draw request using the current material.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    //! \param  drawRequest [in] -
    //!         The DrawRequest instance to be rendered.
    void Material::executeRequest( const RenderArgs &renderArgs, const GeometryRequest &drawRequest ) {
        // TODO: Perform rendering
    }
}
