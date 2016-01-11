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

#if !defined( UDP_BASE_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define UDP_BASE_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


/////////////////////////////////////////////////////////////////

#include "platform/sockets/include/sockets.h"


struct IUdpMessageQueue
{
    void onTerminate() = 0;
    void pop() = 0;
    void push( const void *buffer, int dataLength ) = 0;
};


/////////////////////////////////////////////////////////////////

namespace net
{
    //! \brief  Base class for incoming and outgoing UDP packet handlers.
    class UdpBase
    {
    public:
        virtual ~UdpBase();

        bool start();
        void terminate();

    protected:
        UdpBase( IUdpMessageQueue *queue );

        bool isActive() const;

    private:
        virtual void onExecute() = 0;

    protected:
        IUdpMessageQueue    *m_queue;   // TODO: Make private, add push/pop protected methods?
        ngen::Socket        m_socket;

    private:
        ngen::threading::ThreadHandle   m_thread;
        bool                            m_isActive;
    };


    //! \brief  Determines whether or not the UDP handler is currently active.
    //! \return <em>True</em> if the UDP handler is active otherwise <em>false</em>.
    inline bool UdpBase::isActive() const
    {
        return m_isActive;
    }
}


#endif //!defined( OUTGOING_UDP_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
