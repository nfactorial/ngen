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

#ifndef NGEN_RENDER_LAYER_H
#define NGEN_RENDER_LAYER_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include "material_request.h"


////////////////////////////////////////////////////////////////////////////

#define NGEN_MAXIMUM_MATERIAL_REQUESTS      64


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    struct DrawRequest;

    //! \brief Manages a layer within the rendering pipeline.
    class RenderLayer {
    public:
        RenderLayer();

        ~RenderLayer();

        void flush();

        void execute();

        size_t getId() const;

        size_t getRequestCount() const;

        bool addRequest( const DrawRequest &drawRequest );

    private:
        size_t m_id;

        size_t m_requestCount;
        MaterialRequest m_materialRequests[NGEN_MAXIMUM_MATERIAL_REQUESTS];
    };


    ////////////////////////////////////////////////////////////////////////////

    //! \brief  Retrieves the identifier associated with this layer.
    //! \return The identifier associated with this layer.
    inline size_t RenderLayer::getId() const {
        return m_id;
    };


    //! \brief  Retrieves the number of material requests currently contained within this layer.
    //! \return The total number of material requests contained within the layer.
    inline size_t RenderLayer::getRequestCount() const {
        return m_requestCount;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_RENDER_LAYER_H
