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


#if !defined( GAME_SYSTEM_FACTORY_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
#define GAME_SYSTEM_FACTORY_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

#include <unordered_map>


////////////////////////////////////////////////////////////////////////////

class GameSystem;


////////////////////////////////////////////////////////////////////////////

typedef GameSystem* ( *GameSystemCreateFunc )();


////////////////////////////////////////////////////////////////////////////

//! \brief  
//!
//! TODO: Might make this a templated class.
//! TODO: Probably needs a memory allocator to be supplied.
class GameSystemFactory
{
    typedef std::unordered_map< size_t, GameSystemCreateFunc > RegistryMap;

public:
    GameSystemFactory();
    ~GameSystemFactory();

    GameSystem* create( const char *name );

    bool unregister( const char *name );
    bool registerCtor( const char *name, GameSystemCreateFunc createFunc );

private:
    RegistryMap     m_registry;
};


////////////////////////////////////////////////////////////////////////////

#endif //!defined( GAME_SYSTEM_FACTORY_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
