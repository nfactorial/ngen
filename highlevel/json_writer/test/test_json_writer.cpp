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

#include "json_writer.h"
#include "gtest/gtest.h"

#define GTEST_ENABLE_CATCH_EXCEPTIONS_     1 // TODO: Should be in build script


//////////////////////////////////////////////////////////////////////
// Tests for HeapAllocator class.

// \brief   Ensures we can successully create and destroy a writer without assigning it a buffer.
TEST( JsonWriterCtorTest, Uninitialized ) {
    JsonWriter writer;
    
    EXPECT_EQ( 0, writer.getLength() );
    EXPECT_EQ( 0, writer.getCapacity() );
    EXPECT_EQ( nullptr, writer.getBuffer() );

    // Cannot begin a data block without a buffer
    EXPECT_FALSE( writer.beginArray() );
    EXPECT_FALSE( writer.beginObject() );
    
    // Cannot end a data block without a beginning
    EXPECT_FALSE( writer.endArray() );
    EXPECT_FALSE( writer.endObject() );
}

//! \brief  Eensures the writer behaves correctly when it is initialized but no data is written
TEST( JsonWriter_Initialize, Initialize ) {
    constexpr size_t kCapacity = 1024 * 32;
    
    char *buffer = new char[ kCapacity ];
    
    JsonWriter writer;
    
    EXPECT_TRUE( writer.initialize( buffer, kCapacity ) );
    EXPECT_EQ( 0, writer.getLength() );
    EXPECT_EQ( kCapacity, writer.getCapacity() );

    // Cannot end a data block without a beginning
    EXPECT_FALSE( writer.endArray() );
    EXPECT_FALSE( writer.endObject() );
    
    delete [] buffer; 
}

//! \brief  Ensures the writer behaves correctly when writing an empty object.
TEST( JsonWriter_BeginObject, EmptyObject ) {
    constexpr size_t kCapacity = 1024 * 32;
    
    char *buffer = new char[ kCapacity ];

    JsonWriter writer;
    
    EXPECT_TRUE( writer.initialize( buffer, kCapacity ) );
    EXPECT_TRUE( writer.beginObject() );
    EXPECT_FALSE( writer.beginArray() );       // Cannot begin an array when object has been started
    EXPECT_FALSE( writer.endArray() );
    EXPECT_TRUE( writer.endObject() );

    // Once terminated, we cannot begin a new write without resetting the buffer
    EXPECT_FALSE( writer.beginArray() );
    EXPECT_FALSE( writer.beginObject() );
    EXPECT_FALSE( writer.endArray() );
    EXPECT_FALSE( writer.endObject() );

    delete [] buffer;
}

//! \brief  Ensures the writer behaves correctly when writing an empty array.
TEST( JsonWriter_BeginArray, EmptyArray ) {
    constexpr size_t kCapacity = 1024 * 32;
    
    char *buffer = new char[ kCapacity ];

    JsonWriter writer;
    
    EXPECT_TRUE( writer.initialize( buffer, kCapacity ) );
    EXPECT_TRUE( writer.beginArray() );
    EXPECT_FALSE( writer.beginObject() );       // Cannot begin an object when array has been started
    EXPECT_FALSE( writer.endObject() );
    EXPECT_TRUE( writer.endArray() );

    // Once terminated, we cannot begin a new write without resetting the buffer
    EXPECT_FALSE( writer.beginArray() );
    EXPECT_FALSE( writer.beginObject() );
    EXPECT_FALSE( writer.endArray() );
    EXPECT_FALSE( writer.endObject() );

    delete [] buffer;
}

//! \brief  Write a JSON array object and verify it generated the expected output
TEST( JsonWriter_TestIntArray, TestIntArray ) {
    constexpr size_t kCapacity = 1024 * 32;
    
    char *buffer = new char[ kCapacity ];

    JsonWriter writer;

    EXPECT_TRUE( writer.initialize( buffer, kCapacity ) );
    EXPECT_TRUE( writer.beginArray() );
    EXPECT_TRUE( writer.writeUInt( 64 ) );
    EXPECT_TRUE( writer.writeUInt( 64 ) );
    EXPECT_TRUE( writer.endArray() );
    
    static const char* kExpectedContent =
        "[\r\n"             \
        "\t64, 64\r\n"      \
        "]";

    const size_t kExpectedLength = strlen( kExpectedContent );
    
    EXPECT_EQ( kExpectedLength, writer.getDataLength() );
    EXPECT_EQ( 0, strcmp( kExpectedContent, writer.getBuffer(), kExpectedLength ) );
}

int main(int argc, char** argv ) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(catch_exceptions) = GTEST_ENABLE_CATCH_EXCEPTIONS_ != 0;
    return RUN_ALL_TESTS();
}
