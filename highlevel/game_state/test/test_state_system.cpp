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

#include "state_system.h"
#include "gtest/gtest.h"

//! \brief  Verifies the StateSystem object behaves as expected when it is first created.
TEST( StateSystem, TestConstruction ) {
    StateSystem stateSystem;
    
    EXPECT_EQ( -1, stateSystem.getActiveState() );
    EXPECT_EQ( -1, stateSystem.getPendingState() );
    EXPECT_EQ( 0, stateSystem.getStateCount() );
    EXPECT_FALSE( stateSystem.requestState(0) );
}
