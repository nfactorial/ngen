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

#include "render_layer.h"
#include <ngen/renderer/render_args.h>


namespace ngen {
    RenderLayer::RenderLayer()
    : m_id(0)
    , m_requestCount(0)
    {
        //
    }

    RenderLayer::~RenderLayer() {
        //
    }


    //! \brief  Removes all draw requests from the render layers pipeline.
    void RenderLayer::flush() {
        m_requestCount = 0;
    }


    //! \brief  Adds a new draw request to the render layer
    //! \param  drawRequest [in] -
    //!         The DrawRequest instance to be added to this layer.
    bool RenderLayer::addRequest( const DrawRequest &drawRequest ) {
        return false;
    }


    //! \brief  Performs all rendering currently queued within the layer.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    void RenderLayer::execute( const RenderArgs &renderArgs ) {
        for (int loop = 0; loop < m_requestCount; ++loop) {
            //m_requests[ loop ]->execute();
        }
    }
}
