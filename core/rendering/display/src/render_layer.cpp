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

#include <ngen/renderer/render_args.h>
#include <ngen/renderer/draw_request.h>

#include "render_layer.h"
#include "request_provider.h"
#include "material_request.h"


namespace ngen {
    RenderLayer::RenderLayer()
    : m_id(0)
    , m_requestCount( 0 )
    , m_requestList( nullptr )
    , m_requestProvider( nullptr )
    {
        //
    }

    RenderLayer::~RenderLayer() {
        //
    }


    //! \brief  Prepares the render layer for use by the running application.
    //! \param  requestProvider [in] -
    //!         Object that will be supplying us with memory to store our draw requests.
    //! \return <em>True</em> if the layer initialized successfully otherwise <em>false</em>.
    bool RenderLayer::initialize( RequestProvider *requestProvider ) {
        if ( nullptr != requestProvider && nullptr == m_requestProvider ) {
            m_requestProvider = requestProvider;
            return true;
        }

        return false;
    }

    //! \brief  Removes all draw requests from the render layers pipeline.
    void RenderLayer::flush() {
        m_requestCount = 0;
        m_requestList = nullptr;
    }


    //! \brief  Adds a new draw request to the render layer
    //! \param  drawRequest [in] -
    //!         The DrawRequest instance to be added to this layer.
    //! \return <em>True</em> if the request was added successfully otherwise <em>false</em>.
    bool RenderLayer::addRequest( const DrawRequest &drawRequest ) {
        assert( nullptr != drawRequest.material );

        MaterialRequest *request = findRequest( drawRequest.material );
        if ( nullptr == request ) {
            // TODO: Allocate request
            return false;
        }

/*        if ( request->add( drawRequest ) ) {
            m_requestCount++;
            return true;
        }
*/
        return false;
    }


    //! \brief  Retrieves the material request associated with the specified material, if one exists.
    //! \param  material [in] -
    //!         The material whose MaterialRequest is to be located.
    //! \return Pointer to the MaterialRequest associated with the specified material, if one could not be found returns <em>nullptr</em>.
    MaterialRequest* RenderLayer::findRequest( Material *material ) const {
        // TODO: Might need to use a map in the future rather than a linear search
        for ( MaterialRequest *request = m_requestList; nullptr != request; request = request->next() ) {
            if ( request->getMaterial() == material ) {
                return request;
            }
        }

        return nullptr;
    }


    //! \brief  Performs all rendering currently queued within the layer.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    void RenderLayer::execute( const RenderArgs &renderArgs ) {
        for ( MaterialRequest *materialRequest = m_requestList; nullptr != materialRequest; materialRequest = materialRequest->next() ) {
            materialRequest->execute( renderArgs );
        }
    }
}
