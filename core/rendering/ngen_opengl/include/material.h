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

#ifndef NGEN_MATERIAL_H
#define NGEN_MATERIAL_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include <ngen/renderer/blend_mode.h>
#include <ngen/renderer/blend_func.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    struct RenderArgs;
    struct GeometryRequest;

    class Material {
    public:
        Material();
        ~Material();

        int getLayerId() const;
        bool isShadowAvailable() const;

        void execute( const RenderArgs &renderArgs, const GeometryRequest *requests, size_t requestCount );

        void onEndRendering( const RenderArgs &renderArgs );
        void onBeginRendering( const RenderArgs &renderArgs );

    private:
        void executeRequest( const RenderArgs &renderArgs, const GeometryRequest &drawRequest );

    private:
        int m_layerId;
        bool m_shadowEnabled;

        // TODO: Blend modes etc.
        bool m_blendEnabled;
        kBlendFunc m_blendFunc;
        kBlendMode m_blendMode;
    };


    //! \brief  Retrieves the identifier of the rendering layer this material belongs to.
    //! \return The identifier of the render layer the material belongs to.
    inline int Material::getLayerId() const {
        return m_layerId;
    }


    //! \brief  Determines whether or not the material supports shadow rendering.
    //! \return <em>True</em> if this material is capable of rendering shadow geometry otherwise <em>false</em>.
    inline bool Material::isShadowAvailable() const {
        return m_shadowEnabled;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_MATERIAL_H
