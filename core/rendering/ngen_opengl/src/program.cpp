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

#include "program.h"
#include <cassert>

namespace ngen {
    GLProgram::GLProgram()
    : m_id( GL_INVALID_VALUE )
    , m_pixelShader( GL_VERTEX_SHADER )
    , m_vertexShader( GL_FRAGMENT_SHADER )
    {
        //
    }

    GLProgram::~GLProgram() {
        assert( GL_INVALID_VALUE == m_id );
    }


    //! \brief  Creates the OpenGL program using the supplied settings.
    //! \return <em>True</em> if the program created successfully otherwise <em>false</em>.
    bool GLProgram::initialize() {
        if ( GL_INVALID_VALUE == m_id ) {
            m_id = glCreateProgram();
            if ( GL_INVALID_VALUE != m_id ) {
                // QUERY: Should we create shaders locally like this, or obtain from a shared repository?
                // TODO: Create vertex shader
                // TODO: Create pixel shader
                // TODO: Link program
                glAttachShader( m_id, m_vertexShader.getId() );
                glAttachShader( m_id, m_pixelShader.getId() );

                glLinkProgram( m_id );

                GLint success = GL_FALSE;
                glGetProgramiv( m_id, GL_LINK_STATUS, &success );
                if ( GL_TRUE == success ) {
                    // TODO: Extract parameters
                    return true;
                }

                dispose();
            }
        }

        return false;
    }


    //! \brief  Releases any resources currently owned by this program.
    void GLProgram::dispose() {
        if ( GL_INVALID_VALUE != m_id ) {
            glDeleteProgram( m_id );
            m_id = GL_INVALID_VALUE;

            m_pixelShader.dispose();
            m_vertexShader.dispose();
        }
    }
}
