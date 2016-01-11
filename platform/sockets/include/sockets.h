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

#if !defined( SOCKETS_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define SOCKETS_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

namespace ngen
{
    //! \brief  This structure provides a low-level wrapper around the platforms socket API.
    //!
    //! Whilst the bsd socket API is generally supported across platforms, some platforms
    //! have extended or modified the API to suit their needs. PlatformSocket is used to
    //! wrap each platforms implementation with a single, shared API. PlatformSocket is
    //! used by the Socket class and should not be used directly by other code.
    struct PlatformSocket
    {
        static void close();
        static SocketHandle create( );

        static int listen();
        static int recv( SocketHandle handle, void *buffer, int length );
        static int send( SocketHandle handle, const void *buffer, int length );
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //!defined( SOCKETS_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
