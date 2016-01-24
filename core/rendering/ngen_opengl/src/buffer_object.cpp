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

#include "buffer_object.h"
#include <cassert>


namespace ngen {
    GLBufferObject::GLBufferObject()
    : m_length( 0 )
    , m_id( GL_INVALID_VALUE )
    {
        //
    }

    GLBufferObject::~GLBufferObject() {
        assert( m_id == GL_INVALID_VALUE );
    }


    //! \brief  Prepares the buffer for use by the application.
    //! \return <em>True</em> if the buffer was created successfully otherwise <em>false</em>.
    bool GLBufferObject::initialize( const void *data, size_t length ) {
        if ( GL_INVALID_VALUE == m_id ) {
            glGenBuffers( 1, &m_id );
            if ( GL_INVALID_VALUE != m_id ) {
                m_length = length;

                glBindBuffer( GL_ARRAY_BUFFER, m_id );
                glBufferData( GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW );

                return true;
            }
        }

        return false;
    }


    //! \brief  Frees any resources currently allocated by this buffer.
    void GLBufferObject::dispose() {
        if ( GL_INVALID_VALUE != m_id ) {
            glDeleteBuffers( 1, &m_id );

            m_length = 0;
            m_id = GL_INVALID_VALUE;
        }
    }
}
