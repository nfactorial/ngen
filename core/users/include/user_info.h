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

#if !defined( USER_INFO_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define USER_INFO_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <cstddef>


////////////////////////////////////////////////////////////////////////////

//! \brief Temporary structure to represent an IP address. Will be re-worked in the future
struct tempIp {
    char a, b, c, d;

    bool operator==(const tempIp &other) const {
        return ( a == other.a && b == other.b && c == other.c && d == other.d );
    }

    bool operator!=( const tempIp &other ) const {
        return ( a != other.a || b != other.b || c != other.c || d != other.d );
    }
};


////////////////////////////////////////////////////////////////////////////

//! \brief  This structure is used to represent a user that may play within
//!
//! the currently running session. When the server is started, it is
//! supplied a list of users that are allowed to join play.
//! Any messages we receive that does not include the correct public key
//! will be discarded. Public keys are valid for the sessions lifetime
//! but new keys will be generated for each session for each player.
//!
//! A users message must originate from the users expected IP address as well
//! as include the public key for that user for it to be accepted by the
//! session.
//!
//! In the future the users messages will also be encrypted with the public
//! key in some form but, for now, session messages contain no sensitive data
//! so that is left for the future.
//!
struct UserInfo
{
    uint64_t    privateKey;     // Private key within our network
    uint64_t    publicKey;      // Key user must supply for this session
    uint64_t    lastSeen;       // Time stamp when we last heard from this user
    tempIp      ipAddress;      // IP address the user will communicate from
    uint32_t    latency;        // Last latency calculation for this user

    bool operator==(const UserInfo &other) const;
    bool operator!=(const UserInfo &other) const;

    static const UserInfo createUser( uint64_t privateKey, uint64_t publicKey, const tempIp &ipAddress );
    static const UserInfo kInvalidUser;
};


////////////////////////////////////////////////////////////////////////////

#endif //!defined( USER_INFO_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
