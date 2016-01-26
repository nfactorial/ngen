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
#include <ngen/renderer/render_args.h>
#include <request_page.h>
#include <material.h>

#include "material_request.h"
#include "request_provider.h"

namespace ngen {
    MaterialRequest::MaterialRequest()
    : m_materialId( 0 )
    , m_requestCount( 0 )
    , m_material( nullptr )
    , m_nextMaterial( nullptr )
    , m_requestPage( nullptr )
    , m_requestProvider( nullptr )
    {
    }

    MaterialRequest::~MaterialRequest() {
        //
    }


    //! \brief  Prepares the material request for use by the rendering framework.
    //! \param  owner [in] -
    //!         The RequestProvider object to which we belong.
    //! \param  material [in] -
    //!         The material whose draw requests we will be holding.
    //! \return <em>True</em> if we initialized successfully otherwise <em>false</em>.
    bool MaterialRequest::initialisze( RequestProvider *owner, Material *material ) {
        if ( owner && material ) {
            m_material = material;
            //m_materialId = material->getId();
            m_requestCount = 0;
            m_nextMaterial = nullptr;
            m_requestPage  = nullptr;
            m_requestProvider = owner;

            return true;
        }

        return false;
    }

    bool MaterialRequest::add( const DrawRequest &drawRequest ) {
        if (nullptr == m_requestPage || m_requestPage->items == kNgenRequestPageCapacity ) {
            RequestPage *newPage = m_requestProvider->allocateRequestPage();
            if ( nullptr == newPage ) {
                return false;
            }

            newPage->nextPage = m_requestPage;
            m_requestPage = newPage;
        }

        m_requestPage->requests[ m_requestPage->items++ ] = drawRequest;
        return true;
    }

    void MaterialRequest::link( MaterialRequest *next ) {
        if ( nullptr != next ) {
            next->m_nextMaterial = this;
        }
    }


    //! \brief  Performs all queued render requests by sending them to the associated material.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    void MaterialRequest::execute( const RenderArgs &renderArgs ) {
        assert( nullptr != m_material );

        m_material->onBeginRendering( renderArgs );

        for ( RequestPage *page = m_requestPage; nullptr != page; page = page->nextPage ) {
            // TODO: Should probably supply an array_view instead.
            m_material->execute( renderArgs, &page->requests[ 0 ], page->items );
        }

        m_material->onEndRendering( renderArgs );
    }
}
