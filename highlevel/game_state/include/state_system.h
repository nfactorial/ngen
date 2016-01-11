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

#if !defined( STATE_SYSTEM_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
#define STATE_SYSTEM_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

#include <cstdint>


////////////////////////////////////////////////////////////////////////////

class GameSystem;
class GameSystemFactory;

struct UpdateArgs;
struct StateDescription;


////////////////////////////////////////////////////////////////////////////

//! \brief  The StateSystem object is used to manage a tree of game states within the running title.
class StateSystem
{
public:
    StateSystem();
    ~StateSystem();
    
    bool initialize( GameSystemFactory &factory );
    
    void update( const UpdateArgs &updateArgs );

    bool requestState( uint32_t crc );
    
    int getActiveState() const;
    int getPendingState() const;
    
    int getStateCount() const;

private:
    GameSystemFactory   *m_systemFactory;
    
//    StringTable         m_stringTable;          // Strings used by the state system
    StateDescription    *m_stateList;           // List of all states within the system

    size_t              m_systemCount;
    GameSystem          **m_systemList;
    GameSystem          **m_updateTable;        // Multiple lists of systems, one per state that includes poitners to all systems to be updated for that state

    uint32_t            *m_childTable;          // Array of indices that note the children of each node.

    int                 m_stateCount;           // Number of states within the state list
        
    int                 m_activeState;          // State that is currently being processed
    int                 m_pendingState;         // State to be switched to at the end of the update phase
};


//! \brief  Returns the number of states held within the object.
//! \return The number of states within the state system object.
inline int StateSystem::getStateCount() const
{
    return m_stateCount;
}


//! \brief  Retrieves the identifier of the currently active state.
//! \return The identifier of the currently active state.
inline int StateSystem::getActiveState() const
{
    return m_activeState;
}


//! \brief  Retrieves the index of the states currently waiting to be activated.
//! \return The index of the state waiting to be activated.
inline int StateSystem::getPendingState() const
{
    return m_pendingState;
}


////////////////////////////////////////////////////////////////////////////

#endif //!defined( STATE_SYSTEM_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
