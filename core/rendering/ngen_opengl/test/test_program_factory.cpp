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

#include "program_factory.h"
#include "gtest/gtest.h"

TEST( ProgramFactory, Construction ) {
    ngen::ProgramFactory factory;

    EXPECT_EQ( 0, factory.getCount() );
    EXPECT_EQ( 0, factory.getCapacity() );
    EXPECT_EQ( nullptr, factory.findProgram( "anything" ) );
}

TEST( ProgramFactory, Initialize ) {
    const size_t kTestCapacity = 32;

    ngen::ProgramFactory factory;

    EXPECT_TRUE( factory.initialize( kTestCapacity ) );
    EXPECT_EQ( 0, factory.getCount() );
    EXPECT_EQ( kTestCapacity, factory.getCapacity() );
    EXPECT_EQ( nullptr, factory.findProgram( "anything" ) );
}