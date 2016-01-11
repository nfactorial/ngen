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

#if !defined( JSON_WRITER_HEADER_INCLUDED_DECEMBER_2015_NFACTORIAL )
#defined JSON_WRITER_HEADER_INCLUDED_DECEMBER_2015_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

//! \brief  This class provides the main API for managing a data buffer that is to contain a JSON formatted document.
//!
class JsonWriter
{
    enum kBlockType
    {
        kBlockType_Invalid,         // Block is currently invalid and cannot be used
        kBlockType_Object,          // Block describes a JSON data object
        kBlockType_Array,           // Block describes a JSON array object
    };
    
    struct JsonBlock
    {
        kBlockType type;            // What type of block are we?
        size_t indentLevel;         // Number of indents for this block
        size_t startOffset;         // Offset from buffer start to this block
        size_t dataLength;          // Number of bytes contained within this block
    };
    
public:
    JsonWriter();
    ~JsonWriter();
    
    void reset();
    void dispose();
    
    size_t getLength() const;
    size_t getCapacity() const;
    
    const void* getBuffer() const;
    
    bool beginArray();
    bool beginObject();
    
    bool beginArray( const char *name );
    bool beginObject( const char *name );

    bool endArray();
    bool endObject();
    
    bool writeInt( const char *name, int value );
    bool writeBool( const char *name, bool value );
    bool writeString( const char *name, const char *value );
        
private:
    unsigned char   *m_rawBuffer;                   // Buffer where serialized data is to be stored.
    size_t          m_capacity;                     // Total number of bytes available for use by the writer.
    size_t          m_dataLength;                   // Total number of bytes consumed by the currently serialized data
    
    size_t          m_indents;
    JsonBlock       m_currentBlock;

    JsonWriter( const JsonWriter& other );
    JsonWriter& operator=( const JsonWriter& other );
};


////////////////////////////////////////////////////////////////////////////

// Thought, beginArray() and beginObject() become only methods available in JsonWriter. These return a boolean and take
// a JsonBlock reference.
// JsonWriter maintains two integer values, dataId and blockId.

//! \brief  Retrieves the length of the data (in bytes) contained within the JsonWriter object.
//! \return The length of the data buffer (in bytes) contained within the JsonWriter.
inline size_t JsonWriter::getLength() const
{
    return m_dataLength;
}


//! \brief  Retrieves the maximum amount of data (in bytes) that the JsonWriter can contain.
//! \return The maximum amount of data (in bytes) that the JsonWriter can contain.
inline size_t JsonWriter::getCapacity() const
{
    return m_capacity;
}


////////////////////////////////////////////////////////////////////////////

#endif //!defined( JSON_WRITER_HEADER_INCLUDED_DECEMBER_2015_NFACTORIAL )
