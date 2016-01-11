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

#if !defined( INCOMING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define INCOMING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


/////////////////////////////////////////////////////////////////

#include "platform/sockets/include/sockets.h"


/////////////////////////////////////////////////////////////////

namespace net
{
    //! \brief  Processes incoming message packets across a UDP socket.
    //!
    //! This low level packet handler accepts incoming UDP packets and adds them
    //! onto a specified queue. The incoming packets are accepted on a thread and
    //! thus the message queue must be thread safe.
    class IncomingUdp
    {
    public:
        IncomingUdp();
        ~IncomingUdp();

        bool start();
        void terminate();

    private:
        void execute();

    private:
        bool                m_isActive;
        ngen::Socket        m_socket;
    };
}


/*
    The main portal manages a list of running virtual machines, along with the
    number of game servers running on each VM. The portal tries to ensure at
    least one empty VM is running. When a new session is required, the portal
    checks to see if any currently running VM has free space for an game
    instance. If so, it spawns an instance on that machine.

    When a VM becomes empty (because all its game-instances have terminated)
    the portal marks it as 'Idle'. When there are more than two idle VM's
    the portal begins to terminate them when it detects a VM has been idle
    for more than five minutes.

    The portal will not terminate an idle machine if it is the only idle machine,
    thus ensuring at least one VM is available for new sessions.

    If there are no users logged into the portal, it will terminate the final
    idle VM after five minutes of inactivity.

    A game server VM is spawned with a number of UDP and TCP ports opened,
    UDP ports are open to the internet and the TCP ports are opened only to
    the portal server.

    When a game instance is spawned on the VM, it is supplied the TCP port
    it should use for communication with the portal, along with the portal
    servers address.
    A session configuration file in JSON format is supplied across the TCP
    port that specifies which UDP port the session  instance is to use,
    along with the description of each user that is expected to join.
*/




#define NGEN_SERVER_MAXIMUM_NAME_LENGTH         64

// The ServerInformation is supplied within a JSON definition from the portal
// once it has started.
struct ServerInformation
{
    char        name[ NGEN_SERVER_MAXIMUM_NAME_LENGTH ];
    uint32_t    udport;         // UDP port we will listen for client communication
    uint32_t    provisioner;    // TCP port for provisioner (internal server)
    uint32_t    clientCapacity; // Maximum number of clients the server should expect
    uint32_t    keepAlive;      // Frequency (in ms) the server should contact the portal to notify it is still alive
    uint32_t    pingInterval;   // Frequency (in ms) the server should perform a latency check on each client
    uint32_t    defaultTimeout; // Duration (in ms) before the server should consider an operation timed-out
    uint64_t    securityKey;    // Security key assigned to the session instamnce
};


struct ILog
{
    void error( const char *module, const char *fmt, ... ) = 0;
    void info( const char *module, const char *fmt, ... ) = 0;
    void warn( const char *module, const char *fmt, ... ) = 0;
};

// Server network loop for client communication
template < typename TSocketType > class UdpBase
{
    TSocketType     m_socket;
};

class IncomingUdp : public UdpBase< DefaultUdpSocket >
{
public:
    IncomingUdp( ILog *log );
    ~IncomingUdp();
};




#endif //!defined( INCOMING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
