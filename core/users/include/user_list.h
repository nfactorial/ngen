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

#if !defined( USER_LIST_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define USER_LIST_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL


/////////////////////////////////////////////////////////////////

#include <cstddef>

#include "user_info.h"
#include "user.h"


/////////////////////////////////////////////////////////////////

#define NGEN_USER_LIST_MAXIMUM_USERS         32


/////////////////////////////////////////////////////////////////

//! \brief  Maintains a collection of all users within the currently running session.
class UserList
{
public:
    UserList();
    ~UserList();

    size_t size() const;

    bool userExists( uint64_t publicKey );

    bool addUser( uint64_t privateKey, uint64_t publicKey, const tempIp &ipAddress );
    bool removeUser( uint64_t publicKey );

private:
    size_t              m_count;            //!< Number of users in this list
    UserInfo            m_users[ NGEN_USER_LIST_MAXIMUM_USERS ];
};


//! \brief  Retrieves the number of users in the list.
//! \return The number of users in the list.
inline size_t UserList::size() const
{
    return m_count;
}


/////////////////////////////////////////////////////////////////

#endif //!defined( USER_LIST_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
