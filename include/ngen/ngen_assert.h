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

#if !defined( NGEN_ASSERT_HEADER_INCLUDED_DECEMBER_2015_NFACTORIAL )
#define NGEN_ASSERT_HEADER_INCLUDED_DECEMBER_2015_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

// Enable or disable asserts based on criteria
#if defined( _DEBUG )
    #define NGEN_ASSERT_ENABLED
#endif //defined( _DEBUG )


////////////////////////////////////////////////////////////////////////////

//! \brief  
#if defined( NGEN_ASSERT_ENABLED )
    #define NGEN_HEAP_NEW( heap )   new( heap, __FILE__, __LINE__ )
    #define NGEN_VERIFY( expression, message )                  \
        assert( expression )
        
    #define NGEN_ASSERT( expression, message )                  \
        assert( expression )
#else
    #define NGEN_HEAP_NEW( heap )   new( heap )

    #define NGEN_VERIFY( expression, message )                  \
        expression
        
    #define NGEN_ASSERT( expression, message ) {}
#endif //defined( NGEN_ASSERT_ENABLED )


////////////////////////////////////////////////////////////////////////////

#endif //!defined( NGEN_ASSERT_HEADER_INCLUDED_DECEMBER_2015_NFACTORIAL )
