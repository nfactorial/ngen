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

#ifndef NGEN_TEXTURE_H
#define NGEN_TEXTURE_H


////////////////////////////////////////////////////////////////////////////

#include <OpenGL/gl.h>
#include <ngen/renderer/texture_desc.h>
#include <ngen/renderer/surface_format.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    //! \brief  Represents a single OpenGL texture for use by the running application.
    class GLTexture /* : public BaseTexture */ {
    public:
        GLTexture();
        ~GLTexture();

        bool initialize( const TextureDesc &desc );

        void dispose();

        GLuint getId() const;

        int getWidth() const;
        int getHeight() const;

        kTextureType getType() const;
        kSurfaceFormat getSurfaceFormat() const;

    private:
        GLuint m_id;
        kTextureType m_type;
        kSurfaceFormat m_format;
        int m_width;
        int m_height;
    };


    //! \brief  Retrieves the identifier of the texture object.
    //! \return The identifier of the texture object.
    inline GLuint GLTexture::getId() const {
        return m_id;
    }


    //! \brief  Retrieves the surface format of the texture object.
    //! \return The surface format of the texture object.
    inline kSurfaceFormat GLTexture::getSurfaceFormat() const {
        return m_format;
    }


    //! \brief  Retrieves the type of texture represented by this object.
    //! \return The type of texture represented by this object.
    inline kTextureType GLTexture::getType() const {
        return m_type;
    }


    //! \brief  Retrieves the width of the texture (in pixels).
    //! \return The width of the texture (in pixels).
    inline int GLTexture::getWidth() const {
        return m_width;
    }


    //! \brief  Retrieves the height of the texture (in pixels).
    //! \return The height of the texture (in pixels).
    inline int GLTexture::getHeight() const {
        return m_height;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_TEXTURE_H
