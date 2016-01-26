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

#include <cassert>

#include "request_provider.h"
#include "material_request.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    RequestProvider::RequestProvider() {
    }

    RequestProvider::~RequestProvider() {
    }


    //! \brief  Prepares the request provider for use by the running application.
    //! \param  maximumRequests [in] -
    //!         Maximum number of material requests that may be made by the title.
    //! \param  pages [in] -
    //!         Number of draw request pages available for use by the application.
    //! \return <em>True</em> if the provider initialized successfully otherwise <em>false</em>.
    bool RequestProvider::initialize( size_t materialRequests, size_t pages ) {
        if ( m_requests.empty() && m_requestPages.empty() && materialRequests > 0 && pages > 0 ) {
            m_requests.reserve( materialRequests );
            m_requestPages.reserve( pages );

            return true;
        }

        return false;
    }

    //! \brief  Releases all memory and resources currently in use by the object.
    void RequestProvider::dispose() {
        m_requests.clear();
        m_requestPages.clear();
    }


    //! \brief  Resets the provider as though there are 0 allocations.
    void RequestProvider::reset() {
        m_requests.clear();
        m_requestPages.clear();
    }


    //! \brief  Creates and returns a new request object for the specifid material.
    //! \param  material [in] -
    //!         The material which will be represented by the allocation.
    //! \return Pointer to the newly allocated request object, if the request could not be allocated this method returns <em>nullptr</em>.
    MaterialRequest* RequestProvider::allocateMaterialRequest( Material *material ) {
        if ( material && m_requests.size() < m_requests.capacity() ) {
            MaterialRequest request;
            if ( request.initialisze( this, material ) ) {
                m_requests.push_back( request );
                return &m_requests.back();
            }
        }

        return nullptr;
    }

    RequestPage* RequestProvider::allocateRequestPage() {
        if ( m_requestPages.size() < m_requestPages.capacity() ) {
            RequestPage newPage;

            newPage.nextPage = nullptr;
            newPage.items = 0;

            // TODO: Don't really want to push an item into the page vector. Will re-structure this soon.
            // TODO: Prefer to use an array_view.

            m_requestPages.push_back( newPage );
            return &m_requestPages.back();
        }

        return nullptr;
    }
}
