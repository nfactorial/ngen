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

#include "request_provider.h"
#include "gtest/gtest.h"

#include <material.h>

//! \brief  Tests the initial state of the provider when first created.
TEST( RequestProvider, Construction ) {
    ngen::RequestProvider provider;

    EXPECT_EQ(0, provider.getPageCapacity());
    EXPECT_EQ(0, provider.getPageCount());
    EXPECT_EQ(0, provider.getMaterialCapacity());
    EXPECT_EQ(0, provider.getMaterialAllocations());
}


//! \brief  Ensures the provider can be initialized correctly.
TEST( RequestProvider, Initialize ) {
    const size_t kTestAllocations = 32;
    const size_t kTestPages = 32;

    ngen::RequestProvider provider;

    EXPECT_FALSE(provider.initialize(0, 0));
    EXPECT_TRUE(provider.initialize(kTestAllocations, kTestPages));
    EXPECT_EQ(kTestAllocations, provider.getMaterialCapacity());
    EXPECT_EQ(0, provider.getMaterialAllocations());
}

//! \brief  Ensure we can allocate material requests correctly.
TEST( RequestProvider, AllocateMaterial ) {
    const size_t kTestAllocations = 32;
    const size_t kTestPages = 32;

    ngen::Material testMaterial;
    ngen::RequestProvider provider;

    // Cannot allocate before initialization
    EXPECT_EQ(nullptr, provider.allocateMaterialRequest(&testMaterial));

    EXPECT_TRUE(provider.initialize(kTestAllocations, kTestPages));

    // Should not be able to create a request with a null material
    EXPECT_EQ(nullptr, provider.allocateMaterialRequest(nullptr));

    for (size_t loop = 0; loop < kTestAllocations; ++loop) {
        EXPECT_NE(nullptr, provider.allocateMaterialRequest(&testMaterial));
    }

    EXPECT_EQ(kTestAllocations, provider.getMaterialAllocations());
    EXPECT_EQ(kTestAllocations, provider.getMaterialCapacity());

    // Next allocation should fail, as we've used up all allocations
    EXPECT_EQ(nullptr, provider.allocateMaterialRequest(&testMaterial));

    provider.reset();

    EXPECT_EQ(0, provider.getMaterialAllocations());
    EXPECT_EQ(kTestAllocations, provider.getMaterialCapacity());
}

//! \brief  Ensure we can allocate draw request pages correctly.
TEST( RequestProvider, AllocatePage ) {
    const size_t kTestAllocations = 32;
    const size_t kTestPages = 32;

    ngen::RequestProvider provider;

    // Cannot allocate before initialization
    EXPECT_EQ(nullptr, provider.allocateRequestPage());

    EXPECT_TRUE(provider.initialize(kTestAllocations, kTestPages));

    for (size_t loop = 0; loop < kTestPages; ++loop) {
        EXPECT_NE(nullptr, provider.allocateRequestPage());
    }

    EXPECT_EQ(kTestPages, provider.getPageCount());
    EXPECT_EQ(kTestPages, provider.getPageCapacity());

    // Next allocation should fail, as we've used up all allocations
    EXPECT_EQ(nullptr, provider.allocateRequestPage());

    provider.reset();

    EXPECT_EQ(0, provider.getPageCount());
    EXPECT_EQ(kTestPages, provider.getPageCapacity());
}

//! \brief  Ensure we can allocate draw request pages correctly.
TEST( RequestProvider, Dispose ) {
    const size_t kTestAllocations = 32;
    const size_t kTestPages = 32;

    ngen::RequestProvider provider;

    // Cannot allocate before initialization
    EXPECT_EQ(nullptr, provider.allocateRequestPage());

    EXPECT_TRUE(provider.initialize(kTestAllocations, kTestPages));

    EXPECT_EQ( kTestAllocations, provider.getMaterialCapacity());
    EXPECT_EQ( kTestPages, provider.getPageCapacity());

    provider.dispose();

    EXPECT_EQ(0, provider.getMaterialCapacity());
    EXPECT_EQ(0, provider.getPageCapacity());
}
