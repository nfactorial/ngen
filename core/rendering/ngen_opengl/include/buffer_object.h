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

#ifndef NGEN_BUFFER_OBJECT_H
#define NGEN_BUFFER_OBJECT_H


////////////////////////////////////////////////////////////////////////////

#include <OpenGL/gl.h>
#include <stddef.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class GLBufferObject {
    public:
        GLBufferObject();
        ~GLBufferObject();

        bool initialize( const void *data, size_t length );

        void dispose();

        GLuint getId() const;

    private:
        size_t m_length;
        GLuint  m_id;
    };


    //! \brief  Retrieves the identifier of the OpenGL buffer.
    //! \return The OpenGL identifier of the buffer object.
    inline GLuint GLBufferObject::getId() const {
        return m_id;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_BUFFER_OBJECT_H
