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

#include "incoming_udp.h"

namespace
{
    const char *kModuleName = "IncomingUdp";
    const char *kThreadName = "IncomingUdp";
}


IncomingUdp::IncomingUdp()
{
}

IncomingUdp::~IncomingUdp()
{
}


//! \brief
void IncomingUdp::onExecute()
{
    char buffer[ max_packet_size ];     // TODO: Member variable? Allow max_packet_size to be defined by configuration

    // Memory allocation comes from round-robin memory buffer(s) to remove
    // the necessity for new/delete blocks

    while ( isActive() )
    {
        const int dataLength = m_socket.recv( buffer, max_packet_size );
        if ( dataLength < 0 )
        {
            if ( isActive() )
            {
                processSocketError( dataLength );
            }
        }
        else if ( dataLength > 0 )  // TODO: Simpler if the message queue handles this?
        {
            m_queue->push( buffer, dataLength );
            
            // TODO: Should validate packet then pass it into message queue, we shouldn't know about UserInfo at this level.
            // TODO: Decrypt packet content
            UserInfo *user = findUser( packetInfo.publicKey );
            if ( user && user->ipAddress == packetInfo.ipAddress )
            {
                user->queueMessage( buffer, dataLength );
            }
            else
            {
                m_log->Error( kModuleName, "Received unexpected UDP packet.\n" );
            }
        }
    }
}
