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

#include "outgoing_udp.h"

namespace
{
    const char *kModuleName = "IncomingUdp";    // TODO: Use one string?
    const char *kThreadName = "IncomingUdp";
}

namespace net
{
    OutgoingUdp::OutgoingUdp()
    {
    }

    OutgoingUdp::~OutgoingUdp()
    {
    }


    //! \brief
    void OutgoingUdp::onExecute()
    {
        char buffer[ max_packet_size ];     // TODO: Member variable? Allow max_packet_size to be defined by configuration

        // Memory allocation comes from round-robin memory buffer(s) to remove
        // the necessity for new/delete blocks

        while ( isActive() )
        {
            MessageInfo messageInfo;

            if ( m_queue->pop( messageInfo ) )
            {
                const int sent = m_socket.send( messageInfo.ipAddress, messageInfo.buffer, messageInfo.dataLength );
                if ( sent < 0 )
                {
                    // m_log->error( kModuleName, "Failed to send outgoing UDP packet (err=%d).", sent );
                }
            }
        }
    }
}
