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

#ifndef NGEN_MATERIAL_REQUEST_H
#define NGEN_MATERIAL_REQUEST_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    struct RenderArgs;
    struct RequestPage;

    class Material;
    class RequestProvider;

    //! \brief  This structure is used to manage a list of draw requests made for a specific material.
    class MaterialRequest {
    public:
        MaterialRequest();
        ~MaterialRequest();

        bool initialize( RequestProvider *owner, Material *material );

        bool add( const DrawRequest &drawRequest );

        void execute( const RenderArgs &renderArgs );

        MaterialRequest* next() const;
        void link( MaterialRequest *next );

        size_t getRequests() const;         //!< Retrieves the total number of contained draw requests

        size_t getId() const;               //!< Retrieves the identifier of the material represented by this object
        Material* getMaterial() const;

    private:
        size_t          m_materialId;         //!< Identifier of the material in this list
        size_t          m_requestCount;       //!< Number of draw requests for this material
        Material        *m_material;          //!< Material associated with this request
        MaterialRequest *m_nextMaterial;      //!< Next material in this layer
        RequestPage     *m_requestPage;
        RequestProvider *m_requestProvider;   //!< Request provider we are associated with
    };


    //! \brief  Retrieves the identifier of the material currently associated with this object.
    //! \return The identifier of the material currently associated with this object.
    inline size_t MaterialRequest::getId() const {
        return m_materialId;
    }


    //! \brief  Retrieves the total number of requests contained within this object.
    //! \return The total number of requests contained within this object.
    inline size_t MaterialRequest::getRequests() const {
        return m_requestCount;
    }


    //! \brief  Retrieves the material currently associated with this object.
    //! \return The material currently associated with this object.
    inline Material* MaterialRequest::getMaterial() const {
        return m_material;
    }

    inline MaterialRequest* MaterialRequest::next() const {
        return m_nextMaterial;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_MATERIAL_REQUEST_H
