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
#include "display_port.h"

//! \brief  Tests the initial state of the display manager when first created.
TEST( DisplayProvider, Construction ) {
    ngen::DisplayProvider provider;

    EXPECT_EQ( 0, provider.getDisplayPortCount() );
}


//! \brief  Tests we can successfully create a display port.
TEST( DisplayProvider, CreatePort ) {
    ngen::DisplayProvider provider;

    const char *kPipelineName = "test_pipeline";

    std::array<ngen::DisplayPort *, ngen::kDisplayPortCapacity> ports;

    for (size_t loop = 0; loop < ngen::kDisplayPortCapacity; ++loop) {
        ports[loop] = provider.createDisplayPort(kPipelineName);
        EXPECT_NE(nullptr, ports[loop]);
    }

    EXPECT_EQ(ngen::kDisplayPortCapacity, provider.getDisplayPortCount());

    // Next allocation should fail, as all the display ports have been allocated.
    EXPECT_EQ(nullptr, provider.createDisplayPort(kPipelineName));

    // Delete allocated display ports
    for (size_t loop = 0; loop < ngen::kDisplayPortCapacity; ++loop) {
        EXPECT_TRUE(provider.deletePort(ports[loop]));
    }

    EXPECT_EQ(0, provider.getDisplayPortCount());

    EXPECT_FALSE(provider.deletePort(nullptr));
}
