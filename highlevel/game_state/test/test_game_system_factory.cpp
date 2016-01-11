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

#include <cstddef>
#include "game_system_factory.h"
#include "game_system.h"
#include "gtest/gtest.h"

namespace
{
    GameSystem testSystem;
    
    const char *kTestSystemName = "test_system";
    const char *kInvalidSystemName = "invalid_system";
    
    size_t creatorCalls = 0;
     
    GameSystem* TestGameSystemCreator() {
        creatorCalls++;
        return &testSystem;
    }
}

//! \brief  Verify factory begins life with expected behaviour
TEST( GameSystemFactory, Constructor ) {
    GameSystemFactory factory;
    
    EXPECT_EQ( nullptr, factory.create( kTestSystemName ) );
}


//! \brief  Verify the register function behaves as expected
TEST( GameSystemFactory, Register ) {
    GameSystemFactory factory;

    // Test handling of invalid parameters
    EXPECT_FALSE( factory.registerCtor( nullptr, TestGameSystemCreator ) );
    EXPECT_FALSE( factory.registerCtor( "", TestGameSystemCreator ) );
    EXPECT_FALSE( factory.registerCtor( kTestSystemName, nullptr ) );

    // Register a valid object
    EXPECT_TRUE( factory.registerCtor( kTestSystemName, TestGameSystemCreator ) );
    
    // Make sure we cannot register it twice
    EXPECT_FALSE( factory.registerCtor( kTestSystemName, TestGameSystemCreator ) );
}


//! \brief  Verify the unregister function behaves correctly
TEST( GameSystemFactory, Unregister ) {
    GameSystemFactory factory;

    // Ensure we cannot unregister an object that hasn't been registered
    EXPECT_FALSE( factory.unregister( kTestSystemName ) );
    
    EXPECT_TRUE( factory.registerCtor( kTestSystemName, TestGameSystemCreator ) );
    EXPECT_TRUE( factory.unregister( kTestSystemName ) );
    EXPECT_FALSE( factory.unregister( kTestSystemName ) );
}


//! brief   Verify object creation works as expected.
TEST( GameSystemFactory, Creation ) {
    GameSystemFactory factory;

    creatorCalls = 0;

    // Ensure create function fails if we request an unregistered object
    EXPECT_EQ( nullptr, factory.create( nullptr ) );
    EXPECT_EQ( nullptr, factory.create( kTestSystemName ) );
    EXPECT_EQ( nullptr, factory.create( kInvalidSystemName ) );

    // Register an object, and verify behaviour
    EXPECT_TRUE( factory.registerCtor( kTestSystemName, TestGameSystemCreator ) );
    
    EXPECT_EQ( nullptr, factory.create( nullptr ) );
    EXPECT_EQ( nullptr, factory.create( kInvalidSystemName ) );
    EXPECT_EQ( &testSystem, factory.create( kTestSystemName ) );
    EXPECT_EQ( 1, creatorCalls );
    
    // Unregister the object and verify behaviour
    EXPECT_TRUE( factory.unregister( kTestSystemName ) );
    
    EXPECT_EQ( nullptr, factory.create( nullptr ) );
    EXPECT_EQ( nullptr, factory.create( kInvalidSystemName ) );
    EXPECT_EQ( nullptr, factory.create( kTestSystemName ) );
    EXPECT_EQ( 1, creatorCalls );
}
