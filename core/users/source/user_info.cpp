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

#include "user_info.h"

const UserInfo      UserInfo::kInvalidUser = { 0, 0, 0, { 0, 0, 0, 0 }, 0 };


//! \brief  Creates and initializes a new UserInfo object with the supplied data.
//! \param  privateKey [in] -
//!         Private key to be associated with the new user.
//! \param  publicKey [in] -
//!         Public key to be associated with the new user.
//! \param  ipAddress [in] -
//!         IP Address where the user is known to exist.
//! \return UserInfo object initialized with the specified data.
const UserInfo UserInfo::createUser( uint64_t privateKey, uint64_t publicKey, const tempIp &ipAddress )
{
    UserInfo newUser = { privateKey, publicKey, 0, ipAddress, 0 };
    return newUser;
}


//! \brief  Simple equality operator implementation.
bool UserInfo::operator==(const UserInfo &other) const
{
    return (    privateKey == other.privateKey
             && publicKey == other.publicKey
             && lastSeen == other.lastSeen
             && ipAddress == other.ipAddress
             && latency == other.latency );
}

//! \brief  Simple inequality operator implementation.
bool UserInfo::operator!=(const UserInfo &other) const
{
    return ( privateKey != other.privateKey
             || publicKey != other.publicKey
             || lastSeen != other.lastSeen
             || ipAddress != other.ipAddress
             || latency != other.latency );
}
