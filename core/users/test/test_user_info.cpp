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
#include "gtest/gtest.h"


//! \brief  Verifies the UserInfo structure behaves as expected.
TEST( UserInfo, Construction ) {
    const uint64_t kTestPrivateKey = 1234567;
    const uint64_t kTestPublicKey = 7654321;
    const tempIp kTestIpAddress = { 1, 2, 3, 4 };

    // Check a created user contains the correct values
    const UserInfo testUser = UserInfo::createUser( kTestPrivateKey, kTestPublicKey, kTestIpAddress );

    EXPECT_TRUE( testUser == testUser );
    EXPECT_FALSE( testUser != testUser );
    EXPECT_NE( UserInfo::kInvalidUser, testUser);
    EXPECT_EQ( kTestPrivateKey, testUser.privateKey);
    EXPECT_EQ( kTestPublicKey, testUser.publicKey);
    EXPECT_EQ( kTestIpAddress, testUser.ipAddress);
    EXPECT_EQ( 0, testUser.lastSeen);
    EXPECT_EQ( 0, testUser.latency);
}
