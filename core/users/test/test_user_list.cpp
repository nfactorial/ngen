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
#include "gtest/gtest.h"

const uint64_t kTestPublicKey = 192385;
const uint64_t kTestPrivateKey = 467283;
const tempIp kTestIpAddress = { 4, 3, 2, 1 };


//! \brief  Ensures an empty user list behaves as expected.
TEST( UserList, EmptyConstruction ) {
    UserList userList;

    // Ensure list defaults to empty
    EXPECT_EQ( 0, userList.size() );
    EXPECT_FALSE( userList.userExists( UserInfo::kInvalidUser.publicKey ) );
    EXPECT_FALSE( userList.userExists( kTestPublicKey ) );    

    // Ensure we cannot remove a non-existant user from an empty list
    EXPECT_FALSE( userList.removeUser( UserInfo::kInvalidUser.publicKey ) );
    EXPECT_FALSE( userList.removeUser( kTestPublicKey ) );

    // Ensure we cannot add an invalid user
    EXPECT_FALSE( userList.addUser( UserInfo::kInvalidUser.privateKey, UserInfo::kInvalidUser.publicKey, UserInfo::kInvalidUser.ipAddress ) );
}


//! \brief  Check that the user list allows us to add and remove a single user.  
TEST( UserList, AddRemoveUser ) {
    UserList userList;

    // Ensure we successfully add a valid user
    EXPECT_TRUE( userList.addUser( kTestPrivateKey, kTestPublicKey, kTestIpAddress ) );
    EXPECT_EQ( 1, userList.size() );
    EXPECT_TRUE( userList.userExists( kTestPublicKey ) );
    EXPECT_FALSE( userList.userExists( UserInfo::kInvalidUser.publicKey ) );

    // Ensure we can successfully remove the user
    EXPECT_TRUE( userList.removeUser( kTestPublicKey ) );
    EXPECT_EQ( 0, userList.size() );
    EXPECT_FALSE( userList.userExists( kTestPublicKey ) );
    EXPECT_FALSE( userList.userExists( UserInfo::kInvalidUser.publicKey ) );
}


//! \brief  Fill the container with users and verify it still behaves as expected.
TEST( UserList, FillContainer ) {
    UserList userList;

    // Fill the collection
    // NOTE: It is valid for multiple users to have the same IP Address.
    for ( size_t loop = 0; loop < NGEN_USER_LIST_MAXIMUM_USERS; ++loop )
    {
        userList.addUser( kTestPrivateKey - loop, kTestPublicKey + loop, kTestIpAddress );
    }
    EXPECT_EQ( NGEN_USER_LIST_MAXIMUM_USERS, userList.size() );

    // Ensure we cannot add any more users
    const uint64_t kTestOverflowPrivateKey = kTestPrivateKey - NGEN_USER_LIST_MAXIMUM_USERS;
    const uint64_t kTestOverflowPublicKey = kTestPublicKey + NGEN_USER_LIST_MAXIMUM_USERS;

    EXPECT_FALSE( userList.addUser( kTestPrivateKey - NGEN_USER_LIST_MAXIMUM_USERS, kTestPublicKey + NGEN_USER_LIST_MAXIMUM_USERS, kTestIpAddress ) );
    //EXPECT_FALSE( userList.addUser( UserInfo::kInvalidUser ) );

    for ( size_t loop = 0; loop < NGEN_USER_LIST_MAXIMUM_USERS; ++loop )
    {
        EXPECT_TRUE( userList.userExists( kTestPublicKey + loop ) );
    }

    // Remove all users from the collection
    for ( size_t loop = 0; loop < NGEN_USER_LIST_MAXIMUM_USERS; ++loop )
    {
        EXPECT_TRUE( userList.removeUser( kTestPublicKey + loop ) );
    }

    EXPECT_EQ( 0, userList.size() );

    for ( size_t loop = 0; loop < NGEN_USER_LIST_MAXIMUM_USERS; ++loop )
    {
        EXPECT_FALSE( userList.userExists( kTestPublicKey + loop ) );
    }
}
