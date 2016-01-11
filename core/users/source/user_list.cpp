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

#include "user_list.h"


UserList::UserList()
: m_count( 0 )
{

}

UserList::~UserList()
{
}


//! \brief  Determines whether or not a user with the specified public key exists within the collection.
//! \param  publicKey [in] -
//!         The public key associated with the user.
//! \return <em>True</em> if the user exists within the collection otherwise <em>false</em>.
bool UserList::userExists( uint64_t publicKey )
{
    // TODO: Lock local data for threading security

    for ( size_t loop = 0; loop < m_count; ++loop ) {
        if ( m_users[ loop ].publicKey == publicKey ) {
            return true;
        }
    }

    return false;
}


//! \brief  Attempts to add a new user to the list of verified users.
//! \param  privateKey [in] -
//!         The private key associated with the user.
//! \param  publicKey [in] -
//!         The public key associated with the user.
//! \param  ipAddress [in] -
//!         The IP address of the machine from where the user will be communicating.
//! \return <em>True</em> if the user was successfully added otherwise <em>false</em>.
bool UserList::addUser( uint64_t privateKey, uint64_t publicKey, const tempIp &ipAddress )
{
    // TODO: Lock local data for threading security

    if ( NGEN_USER_LIST_MAXIMUM_USERS == m_count ) {
        // log( "UserList::addUser - Unable to add new user, session capacity is full." );
        return false;
    }

    if ( userExists( publicKey ) ) {
        // log( "UserList::addUser - Unable to add new user, public key alerady in use." );
        return false;
    }

    const UserInfo user = UserInfo::createUser( privateKey, publicKey, ipAddress );
    if ( UserInfo::kInvalidUser == user ) {
        // Log( "UserList::addUser - Cannot add invalid user." );
        return false;
    }

    m_users[ m_count++ ] = user;

    return true;
}


//! \brief  Removes a user from the list of verified users.
//! \param  privateKey [in] -
//!         The private key of the user to be removed.
//! \return <em>True</em> if the user was successfully removed otherwise <em>false</em>.
bool UserList::removeUser( uint64_t publicKey )
{
    // TODO: Lock local data for threading security

    for ( size_t loop = 0; loop < m_count; ++loop ) {
        if ( m_users[ loop ].publicKey == publicKey ) {
            m_users[ loop ] = m_users[ --m_count ];
            m_users[ m_count ] = UserInfo::kInvalidUser;

            return true;
        }
    }

    return false;
}
