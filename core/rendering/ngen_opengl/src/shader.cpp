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

#include "shader.h"
#include <cassert>


// http://lazyfoo.net/tutorials/SDL/51_SDL_and_modern_opengl/

namespace ngen {
    GLShader::GLShader( int type )
    : m_type( type )
    , m_id( GL_INVALID_VALUE )
    {
        //
    }

    GLShader::~GLShader()
    {
        assert( GL_INVALID_VALUE != m_id );
    }


    //! \brief  Deletes any resources currently referenced by this object.
    void GLShader::dispose() {
        if ( GL_INVALID_VALUE != m_id ) {
            glDeleteShader( m_id );
            m_id = GL_INVALID_VALUE;
        }
    }


    //! \brief  Creates and initializes the shader object for use by the application.
    //! \return <em>True</em> if the shader was initialized successfully otherwise <em>false</em>.
    bool GLShader::initialize( const char *source ) {
        if ( GL_INVALID_VALUE == m_id && nullptr != source ) {
            m_id = glCreateShader( m_type );
            if ( GL_INVALID_VALUE != m_id ) {
                glShaderSource( m_id, 1, &source, nullptr );
                glCompileShader( m_id );

                GLint compiled = GL_FALSE;
                glGetShaderiv( m_id, GL_COMPILE_STATUS, &compiled );
                if ( compiled ) {
                    return true;
                }
            }
        }

        return false;
    }
}
