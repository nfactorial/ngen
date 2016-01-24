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

#ifndef NGEN_REQUEST_PROVIDER_H
#define NGEN_REQUEST_PROVIDER_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class Material;

    struct MaterialRequest;

    //! \brief  Provides memory management for draw requests within a frame.
    //!
    //! Rendering is performed as a two-step process, first the title registers all the geometry it
    //! wishes to be rendered. The rendering framework sorts these requests within each layer and material.
    //! Once complete, the framework then visits each render layer and performs the registered requests.
    //!
    //! To manage the allocation of the render queues, we do not want to allocate them dynamically on the heap.
    //! The performance for doing this is too much, instead the request provider supplies an API for quickly
    //! allocating requests from a pooled storage.
    //!
    //! The rendering process is not currently multi-threaded however it is possible it will be extended in the
    //! future to support multiple threads. For now, the framework uses only a single request provider that
    //! is shared across all display ports.
    class RequestProvider {
    public:
        RequestProvider();
        ~RequestProvider();

        bool initialize( size_t maximumRequests );

        void dispose();

        void reset();

        MaterialRequest* createMaterialRequest( Material *material );

        size_t getCapacity() const;
        size_t getAllocations() const;

    private:
        size_t m_capacity;
        size_t m_allocations;
        MaterialRequest *m_requests;
    };


    //! \brief  Retrieves the maximum number of requests the provider can supply.
    //! \return The maximum number of requests that may be supplied by the provider.
    inline size_t RequestProvider::getCapacity() const {
        return m_capacity;
    }


    //! \brief  Retrieves the current number of requests allocated by the provider.
    //! \return The current number of requests allocated by the provider.
    inline size_t RequestProvider::getAllocations() const {
        return m_allocations;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_REQUEST_PROVIDER_H
