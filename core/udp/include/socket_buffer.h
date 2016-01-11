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

#if !defined( SOCKET_BUFFER_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define SOCKET_BUFFER_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


/////////////////////////////////////////////////////////////////

namespace net
{
    //! \brief  Provides a circular memory buffer used for storing data to/from network sockets.
    //!
    //! Because the data is removed in the order it was inserted, we can roll
    //! through the buffer memory and wrap around to the beginning.
    class SocketBuffer
    {
    public:
        SocketBuffer();
        ~SocketBuffer();

        bool initialize(size_t bufferSize);

        void release(void *memory);
        void* allocate(size_t length);

    private:
        char        *m_buffer;      // Pointer to start of memory buffer
        size_t      m_length;       // Total length of buffer
        size_t      m_end;          // Next available position within the buffer
        size_t      m_start;        // Current allocation position

        struct Allocation
        {
            uint32_t offset;
            uint32_t allocLength;   // Length of data block allocated
            uint32_t actualLength;  // Length of block including header
            uint32_t pad;           // Ensure we're 128bits aligned, just makes me feel better
        };

        Allocation  *m_end;         // Remaining memory in buffer
        Allocation  *m_start;       // Next memory block to be released
    };

    SocketBuffer::SocketBuffer()
    : m_end( nullptr )
    , m_start( nullptr )
    {
    }

    SocketBuffer::~SocketBuffer()
    {
        assert( nullptr == m_end );
        assert( nullptr == m_start );
        assert( nullptr == m_buffer );
    }

    bool SocketBuffer::initialize( size_t bufferSize )
    {
        assert( nullptr == m_end );
        assert( nullptr == m_start );
        assert( 0 != bufferSize );

        m_buffer = new char[ bufferSize ];
        if ( m_buffer )
        {
            return true;
        }

        return false;
    }

    void* SocketBuffer::allocate(size_t length)
    {
        // Add space for header onto allocation length,
        length += sizeof( Allocation );

        // Round length to size of 'Allocation' structure, this ensures we're always
        // on a valid alignment for our Allocation structure.
        length = sizeof( Allocation ) * ( ( length + sizeof( Allocation ) - 1 ) / sizeof( Allcoation ) );

        size_t newEnd = m_end + length;
        if ( ( m_end + length ) > m_length )
        {
            if ( length > m_start )
            {
                // Not enough memory
                return nullptr;
            }

            m_end = 0;
        }

        void *mem =
    }

    void SocketBuffer::release( void *memory )
    {
        assert( memory == m_start );
    }
}


#endif //!defined( SOCKET_BUFFER_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
