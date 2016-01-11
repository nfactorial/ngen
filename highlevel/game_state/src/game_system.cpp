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


#include "game_system.h"

GameSystem::GameSystem()
{
    //
}

GameSystem::~GameSystem()
{
    //
}


//! \brief  Called when the object has been created and external references may be resolved.
//! \param  initArgs [in] -
//!         Structure providing access tot he rest of the framework.
//! \return <em>True</em> if the system initialized successfully otherwise <em>false</em>.
bool GameSystem::onInitialize( InitArgs &initArgs )
{
    return true;
}


//! \brief  Called when the system becomes active within the title.
void GameSystem::onExit()
{
}


//! \brief  Called when the system is no longer active within the title.
void GameSystem::onEnter()
{
}


//! \brief  Called when the system should system should perform any per-frame processing.
//! \param  updateArgs [in] -
//!         Per-frame parameters available for use by the system.
void GameSystem::onUpdate( const UpdateArgs &updateArgs )
{
}
