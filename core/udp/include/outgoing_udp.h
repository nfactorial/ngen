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

#if !defined( OUTGOING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define OUTGOING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


/////////////////////////////////////////////////////////////////

#include "udp_base.h"


/////////////////////////////////////////////////////////////////

namespace net
{
    //! \brief  Processes outgoing message packets across a UDP socket.
    //!
    //! This low level packet handler sends outgoing UDP packets to a
    //! specified target and removes them from a specified message queue.
    class OutgoingUdp : public UdpBase
    {
    public:
        OutgoingUdp();
        ~OutgoingUdp();

    private:
        void onExecute();
    };
}


#endif //!defined( OUTGOING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
