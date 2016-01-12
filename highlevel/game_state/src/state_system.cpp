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

#include "state_system.h"
#include "game_system.h"
#include "init_args.h"
#include "state_description.h"
#include "game_system_ref.h"

const int kInvalidStateId       = -1;

StateSystem::StateSystem()
: m_systemFactory( nullptr )
, m_stateList( nullptr )
, m_systemCount( 0 )
, m_systemList( nullptr )
, m_updateTable( nullptr )
, m_childTable( nullptr )
, m_stateCount( 0 )
, m_activeState( kInvalidStateId )
, m_pendingState( kInvalidStateId )
{
}

StateSystem::~StateSystem()
{
}


//! \brief  Called when the state system should prepare itself for use by the title.
//! \param  factory [in] -
//!         Object that may be used to create game system objects for use by the title.
//! \return <em>True</em> if the state system initialized successfully otherwise <em>false</em>.
bool StateSystem::initialize( GameSystemFactory &factory )
{
    InitArgs initArgs;

    for ( size_t loop = 0; loop < m_systemCount; ++loop )
    {
        m_systemList[ loop ].instance->onInitialize( initArgs );
    }

    return false;
}


//! \brief  Performs any per-frame processing necessary as defined by the active state tree.
//! \param  updateArgs [in] -
//!         Per-frame parameters for the running title.
void StateSystem::update( const UpdateArgs &updateArgs )
{
    if ( kInvalidStateId != m_activeState )
    {
        const StateDescription &state = m_stateList[ m_activeState ];
        
//        NGEN_ASSERT( 0 != m_stateCount, "Active state was valid but there are no states available." );
//        NGEN_ASSERT( nullptr != m_stateList, "Active state was valid but there is no state table." );
        
        if ( 0 != state.updates )
        {
            const unsigned int count = state.updates;
            const unsigned int start = state.firstUpdate;
            
            for ( unsigned int loop = 0; loop < count; ++loop )
            {
//                m_updateList[ start + loop ]->onUpdate( updateArgs );
            }
        }
    }
}

//! \brief
bool StateSystem::requestState( uint32_t crc )
{
    //m_pendingState = //
    return false;
}
