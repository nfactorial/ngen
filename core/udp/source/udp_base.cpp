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

#include "udp_base.h"

namespace
{
    const char *kModuleName = "IncomingUdp";
    const char *kThreadName = "IncomingUdp";
}

namespace net
{
    UdpBase::UdpBase()
    : m_thread( ngen::threading::kInvalidThreadHandle )
    , m_isActive( false )
    {
    }

    UdpBase::~UdpBase()
    {
        assert( !m_isActive );
        assert( !m_socket.isValid() );
        assert( ngen::threading::kInvalidThreadHandle == m_thread );
    }


    //! \brief  Begins accepting incoming UDP packets through the specified port.
    //! \return <em>True</em> if the listener initialized successfully otherwise <em>false</em>.
    bool UdpBase::start()
    {
        assert( !m_isActive );
        assert( !m_socket.isValid() );

        if ( m_socket.create( UDP, blah, blah ) )
        {
            m_thread = ngen::threading::create( kThreadName, this, &this::onExecute );
            if ( ngen::threading::kInvalidThreadHandle != m_thread )
            {
                m_isActive = true;
                ngen::threading::unpause( m_thread );

                return true;
            }

            // m_log->Error( "Failed to create thread for UDP communication." );
            m_socket.close();
        }
        else
        {
            // m_log->Error( "Failed to create UDP socket for communication." );
        }

        return false;
    }


    //! \brief  Terminates the packet handler and stops listening for incoming packets.
    void UdpBase::terminate()
    {
        if ( m_isActive )
        {
            m_isActive = false;
            m_socket.close();

            ngen::threading::join( m_thread );

            m_thread = ngen::threading::kInvalidThreadHandle;
        }
    }
}
