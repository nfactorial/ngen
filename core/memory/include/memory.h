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

#if !defined( NGEN_MEMORY_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
#define NGEN_MEMORY_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL

#include <cstdlib>

struct IMemoryPool
{
    virtual void release( void *memory ) = 0;
    virtual void* allocate( size_t size ) = 0;
    virtual void* allocate( size_t size, const char *fileName, size_t line ) = 0;
};

void* operator new( std::size_t length, IMemoryPool *memoryPool );
void* operator new( std::size_t length, IMemoryPool *memoryPool, const char *fileName, std::size_t line );


#endif //!defined( NGEN_MEMORY_HEADER_INCLUDED_OCTOBER_2015_NFACTORIAL )
