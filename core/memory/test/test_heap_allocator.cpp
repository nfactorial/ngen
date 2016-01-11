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

#include "heap_allocator.h"
#include "gtest/gtest.h"


//////////////////////////////////////////////////////////////////////
// Tests for HeapAllocator class.

// Checks that we can successully create and initialize a HeapAllocator object.
TEST( HeapAllocator, SuccessfulCtor ) {
    constexpr size_t kTestMemoryBufferLength = 1024;
    
    char *tempBuffer = new char[ kTestMemoryBufferLength ];
    
    HeapAllocator *allocator = new HeapAllocator();
    
    EXPECT_TRUE( allocator->initialize( tempBuffer, kTestMemoryBufferLength ) );
    EXPECT_TRUE( nullptr != allocator );
    EXPECT_TRUE( allocator->isValid() );
    EXPECT_EQ( kTestMemoryBufferLength, allocator->getBufferLength() );
    EXPECT_EQ( 0, allocator->getAllocations() );
    EXPECT_EQ( 0, allocator->getTotalAllocations() );
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    
    delete allocator;
    delete [] tempBuffer;
}

// Tests the heap allocator fails to initialize if provided a null memory buffer.
TEST( HeapAllocator, FailureCtor ) {
    constexpr size_t kTestMemoryBufferLength = 1024;
    
    HeapAllocator *allocator = new HeapAllocator();

    EXPECT_FALSE( allocator->initialize( nullptr, kTestMemoryBufferLength ) );
    EXPECT_TRUE( nullptr != allocator );
    EXPECT_FALSE( allocator->isValid() );
    EXPECT_EQ( 0, allocator->getBufferLength() );
    EXPECT_EQ( 0, allocator->getAllocations() );
    EXPECT_EQ( 0, allocator->getTotalAllocations() );
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    
    delete allocator;
}

// This test checks that the allocator fails to initialize if it is not supplied an aligned memory buffer.
TEST( HeapAllocator, UnalignedFailureCtor ) {
    constexpr size_t kTestMemoryBufferLength = 1024;
    constexpr size_t kUnalignOffset = sizeof( int ) / 2;
    
    char *tempBuffer = new char[ kTestMemoryBufferLength + sizeof( int ) ];
    
    HeapAllocator *allocator = new HeapAllocator();
    
    EXPECT_FALSE( allocator->initialize( &tempBuffer[ kUnalignOffset ], kTestMemoryBufferLength ) );
    EXPECT_TRUE( nullptr != allocator );
    EXPECT_FALSE( allocator->isValid() );
    EXPECT_EQ( 0, allocator->getBufferLength() );
    EXPECT_EQ( 0, allocator->getAllocations() );
    EXPECT_EQ( 0, allocator->getTotalAllocations() );
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    
    delete allocator;
    delete [] tempBuffer;
}

// Checks whether we can successfully allocate a memory block using the HeapAllocator
TEST( HeapAllocator, AllocationSuccess ) {
    constexpr size_t kTestMemoryBufferLength = 1024;
    constexpr size_t kTestAllocation = kTestMemoryBufferLength / 2;

    char *tempBuffer = new char[ kTestMemoryBufferLength ];
    
    HeapAllocator *allocator = new HeapAllocator();
    
    EXPECT_TRUE( allocator->initialize( tempBuffer, kTestMemoryBufferLength ) );
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    
    void *testAlloc = allocator->allocate( kTestAllocation );
    EXPECT_NE( nullptr, testAlloc );
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    EXPECT_EQ( 1, allocator->getTotalAllocations() );
    EXPECT_EQ( 1, allocator->getAllocations() );

    allocator->release( testAlloc );
    
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    EXPECT_EQ( 0, allocator->getAllocations() );
    EXPECT_EQ( 1, allocator->getTotalAllocations() );

    delete allocator;
    delete [] tempBuffer;
}

// Checks that the HeapAllocator responds correctly when we attempt to allocate a memory block larger than the available pool.
TEST( HeapAllocator, AllocationTooLarge ) {
    constexpr size_t kTestMemoryBufferLength = 1024;
    constexpr size_t kTestAllocation = kTestMemoryBufferLength * 2;

    char *tempBuffer = new char[ kTestMemoryBufferLength ];
    
    HeapAllocator *allocator = new HeapAllocator();
    
    EXPECT_TRUE( allocator->initialize( tempBuffer, kTestMemoryBufferLength ) );
    EXPECT_EQ( 0, allocator->getFailedAllocations() );
    EXPECT_EQ( nullptr, allocator->allocate( kTestAllocation ) );
    EXPECT_EQ( 1, allocator->getFailedAllocations() );
    EXPECT_EQ( 0, allocator->getTotalAllocations() );
    EXPECT_EQ( 0, allocator->getAllocations() );

    delete allocator;
    delete [] tempBuffer;
}
