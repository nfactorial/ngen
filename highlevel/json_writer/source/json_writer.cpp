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

JsonWriter::JsonWriter()
: m_rawBuffer( nullptr )
, m_capacity( 0 )
, m_dataLength( 0 )
, m_indents( 0 )
{
    m_currentBlock.type = kBlockType_Invalid;
    m_currentBlock.indentLevel = 0;
    m_currentBlock.startOffset = 0;
    m_currentBlock.dataLength = 0;
}

JsonWriter::~JsonWriter()
{
}


//! \brief  Discards all references to any external memory.
void JsonWriter::dispose()
{
    reset();
    
    m_rawBuffer = nullptr;
    m_capacity = 0;
}


//! \brief  Terminates all serialization in progress and prepares the writer for a new JSON data block.
void JsonWriter::reset()
{
    m_dataLength = 0;
    m_indents = 0;
    
    m_currentBlock.type = kBlockType_Invalid;
    m_currentBlock.indentLevel = 0;
    m_currentBlock.startOffset = 0;
    m_currentBlock.dataLength = 0;
}


//! \brief  Starts serialization of an array object.
//! \return <em>True</em> if the array serialization began successfully otherwise returns <em>false</em>. 
bool JsonWriter::beginArray()
{
    if ( m_currentBlock.type == kBlockType_Invalid && m_dataLength == 0 )
    {
        m_currentBlock.type = kBlockType_Array;
        m_currentBlock.indentLevel  = 1;
        m_currentBlock.startOffset  = 0;
        
        // TODO: Add '[' and newline to buffer

        return true;
    }

    return false;
}


//! \brief  Starts serialization of an object.
//! \return <em>True</em> if the object serialization began successfully otherwise returns <em>false</em>. 
bool JsonWriter::beginObject()
{
    if ( m_currentBlock.type == kBlockType_Invalid && m_dataLength == 0 )
    {
        m_currentBlock.type = kBlockType_Array;
        m_currentBlock.indentLevel  = 1;
        m_currentBlock.startOffset  = 0;
        
        // TODO: Add '{' and newline to buffer

        return true;
    }

    return false;
}


//! \brief  Completes the serialization of an array object.
//! \return <em>True</em> if the array serialization was terminated successfully otherwise returns <em>false</em>. 
bool JsonWriter::endArray()
{
    if ( m_currentBlock.type == kBlockType_Array && m_currentBlock.indentLevel == 1 )
    {
        // TODO: Add ']' to buffer
        
        m_currentBlock.type = kBlockType_Invalid;
        m_currentBlock.indentLevel = 0;
        m_currentBlock.startOffset = 0;
        
        return true;
    }
    
    return false;
}


//! \brief  Completes the serialization of an array object.
//! \return <em>True</em> if the array serialization was terminated successfully otherwise returns <em>false</em>. 
bool JsonWriter::endObject()
{
    if ( m_currentBlock.type == kBlockType_Array && m_currentBlock.indentLevel == 1 )
    {
        // TODO: Add '}' to buffer
        
        m_currentBlock.type = kBlockType_Invalid;
        m_currentBlock.indentLevel = 0;
        m_currentBlock.startOffset = 0;

        return true;
    }

    return false;
}
