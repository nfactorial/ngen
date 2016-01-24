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

#include "display_provider.h"
#include "gtest/gtest.h"

//! \brief  Tests the initial state of the display manager when first created.
TEST( DisplayProvider, Construction ) {
    ngen::DisplayProvider provider;

    EXPECT_EQ( 0, provider.getDisplayPortCount() );
}


//! \brief  Tests we can successfully create a display port.
TEST( DisplayProvider, CreatePort ) {
    ngen::DisplayProvider provider;

    ngen::DisplayPort *port = provider.createDisplayPort( "test_pipeline" );

    EXPECT_EQ( 1, provider.getDisplayPortCount() );
    EXPECT_NE( nullptr, port );
}
