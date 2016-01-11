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


//////////////////////////////////////////////////////////////////////

HeapAllocator::HeapAllocator()
: m_totalAllocations( 0 )
, m_currentAllocations( 0 )
, m_failedAllocations( 0 )
, m_memoryRemaining( 0 )
, m_bufferLength( 0 )
, m_memory( nullptr )
{
}

HeapAllocator::~HeapAllocator()
{
}


//! \brief Prepaers the allocator for use by the application.
//! \param	buffer [in] -
//!			Pointer to the block of memory the allocator may supply allocations from.
//! \param	length [in] -
//!			Length of the memory buffer (in bytes) pointed to by buffer.
//! \return	<em>True</em> if the memory buffer initialized successfully otherwise <em>false</em>.
bool HeapAllocator::initialize( void *buffer, size_t length )
{
	uintptr_t ptr = ( uintptr_t )buffer;
	if ( 0 == ( ptr & 0x003 ) )
	{
		if ( buffer && length > 0 )
		{
			m_bufferLength = length;
			m_memory = static_cast< unsigned char* >( buffer );
			return true;
		}
	}
	else
	{
		// Log( "HeapAllocator cannot use unaligned memory buffer." );
	}
	
	return false;
}


//! \brief	Releases a block of memory previously allocated by this allocator.
//! \param	memory [in] -
//!			Pointer to the memory block being released.
void HeapAllocator::release( void *memory )
{
}


//! \brief	Attempts to allocate a new memory block using the allocator.
//! \param	size [in] -
//!			Size of the memory block (in bytes) to be allocated.
//! \return	Pointer to the allocated memory block, if the block could not be allocated this method returns nullptr.
void* HeapAllocator::allocate( size_t size )
{
	void *memory = allocateBlock( size + sizeof( AllocationHeader ), nullptr, 0 );
	if ( memory )
	{
		m_totalAllocations++;
		m_currentAllocations++;
	}
	else
	{
		m_failedAllocations++;
	}
	
	return memory;
}


//! \brief	Attempts to allocate a new memory block using the allocator and associates it with a specified file and line number.
//! \param	size [in] -
//!			Size of the memory block (in bytes) to be allocated.
//! \param	fileName [in] -
//!			Name of the file where the allocation request wasa made.
//! \param	line [in] -
//!			Line number within the file where the allocation request was made.
//! \return	Pointer to the allocated memory block, if the block could not be allocated this method returns nullptr.
void* HeapAllocator::allocate( size_t size, const char *fileName, size_t line )
{
	return allocateBlock( size, fileName, line );
}


//! \brief	Attempts to allocate a new memory block using the allocator and associates it with a specified file and line number.
//! \param	size [in] -
//!			Size of the memory block (in bytes) to be allocated.
//! \param	fileName [in] -
//!			Name of the file where the allocation request wasa made.
//! \param	line [in] -
//!			Line number within the file where the allocation request was made.
//! \return	Pointer to the allocated memory block, if the block could not be allocated this method returns nullptr.
void* HeapAllocator::allocateBlock( size_t size, const char *fileName, size_t line )
{
	if ( size > m_bufferLength )
	{
		// Log( "Cannot allocate memory block of size {size}, buffer is too small." );
		return nullptr;
	}

	if ( size > m_memoryRemaining )
	{
		// Log( "Cannot allocate memory block of size {size}, not enough memory remaining." );
		return nullptr;
	}

	// There is potentially enough memory for this block, so attempt to find free space
	void *memory = nullptr;
	
	return memory;
}
