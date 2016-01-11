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

#if !defined( NGEN_HEAP_ALLOCATOR_NOVEMBER_2015_NFACTORIAL )
#define NGEN_HEAP_ALLOCATOR_NOVEMBER_2015_NFACTORIAL


//////////////////////////////////////////////////////////////////////

#include "memory.h"


//////////////////////////////////////////////////////////////////////

//! \brief	Implements a memory allocator that behaves like a standard memory heap.
class HeapAllocator : public IMemoryPool
{
	// This structure appears in front of all allocated memory.
	struct AllocationHeader
	{
		size_t     length;      // Length of the allocated memory block in bytes
	};

public:
	HeapAllocator();
	virtual ~HeapAllocator();

	bool initialize( void *buffer, size_t length );
	
	bool isValid() const;
	size_t getBufferLength() const;

	size_t getAllocations() const;
	size_t getTotalAllocations() const;
	size_t getFailedAllocations() const;
	
	// IMemoryPool methods	
    virtual void release( void *memory );
    virtual void* allocate( size_t size );
	virtual void* allocate( size_t size, const char *fileName, size_t line );

private:
	void* allocateBlock( size_t size, const char *fileName, size_t line );

private:
	size_t m_totalAllocations;		// Total number of allocations made by this allocator
	size_t m_currentAllocations;	// Current number of allocated memory blocks
	size_t m_failedAllocations;		// Number of failed allocations
	size_t m_memoryRemaining;		// Number of bytes still available for allocation (not sequential)
	size_t m_bufferLength;
	
	unsigned char *m_memory;
};


//////////////////////////////////////////////////////////////////////

//! \brief	Retrieves a boolean that signals whether or not the allocator is usable.
//! \return	<em>True</em> if the allocator is usable otherwise <em>false</em>.
inline bool HeapAllocator::isValid() const
{
	return ( 0 != m_bufferLength && nullptr != m_memory );
}


//! \brief	Retrieves the total number of bytes within the allocator.
//! \return	The number of bytes assigned to the allocator.
inline size_t HeapAllocator::getBufferLength() const
{
	return m_bufferLength;
}


//! \brief	Retrieves the number of allocations currently active within the allocator.
//! \return	The current number of active allocations in the allocator.
inline size_t HeapAllocator::getAllocations() const
{
	return m_currentAllocations;
}


//! \brief	Retrieves the number of failed allocations the allocator has returned.
//! \return	The number of times the allocator failed to allocate a requested memory block.
inline size_t HeapAllocator::getFailedAllocations() const
{
	return m_failedAllocations;
}


//! \brief	Retrieves the total number of allocations amde within the allocator since it was created.
//! \return	The total number of successful allocations made using this allocator.
inline size_t HeapAllocator::getTotalAllocations() const
{
	return m_totalAllocations;
}


//////////////////////////////////////////////////////////////////////

#endif //!defined( NGEN_HEAP_ALLOCATOR_NOVEMBER_2015_NFACTORIAL )
