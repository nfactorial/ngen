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

#if !defined( GAME_SYSTEM_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
#define GAME_SYSTEM_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

struct InitArgs;
struct UpdateArgs;


////////////////////////////////////////////////////////////////////////////

//! \brief  Base class for all game systems available within the title.
class GameSystem
{
public:
    GameSystem();
    virtual ~GameSystem();

    virtual bool onInitialize( InitArgs &initArgs );

    virtual void onExit();
    virtual void onEnter();
    
    virtual void onUpdate( const UpdateArgs &updateArgs );
};


////////////////////////////////////////////////////////////////////////////

#endif //!defined( GAME_SYSTEM_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
