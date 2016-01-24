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

#ifndef NGEN_SHADER_H
#define NGEN_SHADER_H


////////////////////////////////////////////////////////////////////////////

#include <OpenGL/gl.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class GLShader {
    public:
        GLShader( int type );
        ~GLShader();

        bool initialize( const char *source );

        void dispose();

        GLuint getId() const;

    private:
        int m_type;
        GLuint m_id;
    };


    //! \brief  Retrieves the identifier of the shader object.
    //! \return The identifier of the shader object.
    inline GLuint GLShader::getId() const {
        return m_id;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_SHADER_H
