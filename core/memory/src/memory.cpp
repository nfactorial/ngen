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

#include "memory.h"

#include <cassert>


//! \brief	Debug allocation method that logs the filename and line number where the allocation was made.
//! \param	length [in] -
//!			The number of bytes to be allocated.
//! \param	memoryPool [in] -
//!			The memory pool to be used when attempting to allocate the requested memory.
//! \return	Pointer to the allocated memory block, if the allocation could not be made this method returns a null pointer.
void* operator new( std::size_t length, IMemoryPool *memoryPool )
{
	//NGEN_ASSERT( nullptr != memoryPool, "ngen - operator new called without a valid memory pool." );
	return memoryPool->allocate( length );
}


//! \brief	Debug allocation method that logs the filename and line number where the allocation was made.
//! \param	length [in] -
//!			The number of bytes to be allocated.
//! \param	memoryPool [in] -
//!			The memory pool to be used when attempting to allocate the requested memory.
//! \param	fileName [in] -
//!			Path of the file that made the allocation request.
//! \param	line [in] -
//!			Line number within the src file that made the allocation request.
//! \return	Pointer to the allocated memory block, if the allocation could not be made this method returns a null pointer.
void* operator new( std::size_t length, IMemoryPool *memoryPool, const char *fileName, std::size_t line )
{
	//NGEN_ASSERT( nullptr != memoryPool, "ngen - operator new called without a valid memory pool." );
	return memoryPool->allocate( length, fileName, line );
}
