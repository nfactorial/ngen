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
    RequestProvider::RequestProvider()
    : m_capacity( 0 )
    , m_allocations( 0 )
    , m_requests( nullptr )
    {
        //
    }

    RequestProvider::~RequestProvider()
    {
        assert( nullptr == m_requests );
    }


    //! \brief  Prepares the request provider for use by the running application.
    //! \param  maximumRequests [in] -
    //!         Maximum number of material requests that may be made by the title.
    //! \return <em>True</em> if the provider initialized successfully otherwise <em>false</em>.
    bool RequestProvider::initialize( size_t maximumRequests )
    {
        if ( maximumRequests > 0 && nullptr == m_requests ) {
            m_requests = new MaterialRequest[ maximumRequests ];
            if ( nullptr != m_requests ) {
                m_capacity = maximumRequests;
                return true;
            }
        }

        return false;
    }

    //! \brief  Releases all memory and resources currently in use by the object.
    void RequestProvider::dispose() {
        delete [] m_requests;
        m_requests = nullptr;

        m_capacity = 0;
        m_allocations = 0;
    }


    //! \brief  Resets the provider as though there are 0 allocations.
    void RequestProvider::reset() {
        m_allocations = 0;
    }


    //! \brief  Creates and returns a new request object for the specifid material.
    //! \param  material [in] -
    //!         The material which will be represented by the allocation.
    //! \return Pointer to the newly allocated request object, if the request could not be allocated this method returns <em>nullptr</em>.
    MaterialRequest* RequestProvider::createMaterialRequest( Material *material )
    {
        if ( material ) {
            if (m_allocations < m_capacity) {
                return &m_requests[m_allocations++];
            }
        }

        return nullptr;
    }
}
