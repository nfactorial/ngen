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


#include "game_system_factory.h"
#include "system_crc.h"


GameSystemFactory::GameSystemFactory()
{
}

GameSystemFactory::~GameSystemFactory() {
}


//! \brief  Attempts to create an instance of the object associated with the specified name.
//! \param  name [in] -
//!         Name of the object to be created.
//! \return Pointer to the newly created object, if the object could not be found this method returns <em>nullptr</em>.
GameSystem* GameSystemFactory::create( const char *name )
{
    if ( nullptr != name ) {
        const size_t length = strlen( name );
        if ( length > 0 ) {
            const size_t keyValue = ngen::calculateChecksum(name, length);

            auto it = m_registry.find(keyValue);
            if (it != m_registry.end()) {
                return it->second();
            }
        }
    }

    return nullptr;
}


//! \brief  Unregisters a previously registered object from the factory.
//! \param  name [in] -
//!         Name of the object to be unregistered.
//! \return <em>True</em> if the object was unregistered successfully otherwise <em>false</em>.
bool GameSystemFactory::unregister( const char *name )
{
    if ( nullptr != name ) {
        const size_t length = strlen( name );
        if ( length > 0 ) {
            const size_t keyValue = ngen::calculateChecksum(name, length);

            auto it = m_registry.find(keyValue);
            if (it != m_registry.end()) {
                m_registry.erase(it);
                return true;
            }
        }
    }

    return false;
}


//! \brief  Registers a new object with the factory.
//!
//! Note: Cannot be named 'register' as there appears to be a macro defined somewhere with that name.
//!
//! \param  name [in] -
//!         Name of the object that is being registered.
//! \param  createFunc [in] -
//!         Function to be called that will instantiate a new instance of the object.
//! \return <em>True</em> if regisstration was successful otherwise <em>false</em>.
bool GameSystemFactory::registerCtor( const char *name, GameSystemCreateFunc createFunc )
{
    if ( nullptr != name && nullptr != createFunc )
    {
        const size_t length = strlen( name );
        if ( length > 0 ) {
            const size_t keyValue = ngen::calculateChecksum(name, length);

            // TODO: Lock here if thread safety is needed
            if (m_registry.find(keyValue) == m_registry.end()) {
                m_registry.insert(RegistryMap::value_type(keyValue, createFunc));
                return true;
            }
        }
    }

    return false;
}
