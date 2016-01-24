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

#include "texture.h"
#include <cassert>

namespace ngen {
    GLenum textureTypeToGL( kTextureType type ) {
        switch ( type ) {
            case kTextureType_1D:
                return GL_TEXTURE_1D;

            case kTextureType_2D:
                return GL_TEXTURE_2D;

            case kTextureType_3D:
                return GL_TEXTURE_3D;
        }

        return GL_INVALID_ENUM;
    }

    GLint textureFormatToGL( kSurfaceFormat format ) {
        switch ( format ) {
            case kSurfaceFormat_Invalid:
                break;

            case kSurfaceFormat_RGBA8:
                return GL_RGBA;

            case kSurfaceFormat_RGB8:
                return GL_RGB;
        }

        return GL_INVALID_VALUE;
    }

    //! \brief  Converts a kSurfaceFormat value to the appropriate OpenGL data format enumeration.
    GLenum textureFormatToDataType( kSurfaceFormat format ) {
        switch ( format ) {
            case kSurfaceFormat_Invalid:
                break;

            case kSurfaceFormat_RGBA8:
                return GL_UNSIGNED_BYTE;

            case kSurfaceFormat_RGB8:
                return GL_UNSIGNED_BYTE;
        }

        return GL_INVALID_ENUM;
    }

    GLTexture::GLTexture()
    : m_id( GL_INVALID_VALUE )
    , m_type( kTextureType_2D )
    , m_format( kSurfaceFormat_Invalid )
    , m_width( -1 )
    , m_height( -1 )
    {
    }

    GLTexture::~GLTexture() {
        assert( m_id == GL_INVALID_VALUE );
    }

    //! \brief  Prepares the texture for use by the application.
    //! \return <em>True</em> if the texture was created successfully otherwise <em>false</em>.
    bool GLTexture::initialize( const TextureDesc &desc ) {
        if ( GL_INVALID_VALUE == m_id ) {
            glGenTextures( 1, &m_id );

            // https://www.opengl.org/sdk/docs/man/html/glTexImage2D.xhtml
            /*
            glTexImage2D(     textureTypeToGL( desc.type )
                            , 0
                            , textureFormatToGL( desc.format )
                            , desc.width
                            , desc.height
                            , 0
                            , textureFormatToGL( desc.format )
                            , textureFormatToDataType( desc.format )
                            , data );
            */
            m_width = desc.width;
            m_height = desc.height;
            m_type = desc.type;
            m_format = desc.format;

            return (GL_INVALID_VALUE != m_id);
        }

        return false;
    }

    //! \brief  Destroys the texture represented by this object.
    void GLTexture::dispose() {
        if ( GL_INVALID_VALUE != m_id ) {
            glDeleteTextures( 1, &m_id );
            m_id = GL_INVALID_VALUE;
            m_width = 0;
            m_height = 0;
            m_type = kTextureType_2D;
            m_format = kSurfaceFormat_Invalid;
        }
    }
}
