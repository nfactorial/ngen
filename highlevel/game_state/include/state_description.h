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

#if !defined( STATE_DESCRIPTION_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
#define STATE_DESCRIPTION_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL


////////////////////////////////////////////////////////////////////////////

//! \brief  Describes a single game state within our state hierarchy
struct StateDescription
{
    uint32_t    name;           // Offset into string table for state name
    uint32_t    crc;            // CRC value for name string
    uint32_t    systems;        // Number of systems within this state
    uint32_t    updates;        // NUmber of systems to be updated
    uint32_t    children;       // Number of child states
    uint32_t    firstChild;     // Index into state table of our first child 
    uint32_t    firstSystem;    // Index into system table for our first system
    uint32_t    firstUpdate;    // Index into update table for our first update
};


////////////////////////////////////////////////////////////////////////////

#endif //!defined( STATE_DESCRIPTION_HEADER_INCLUDED_JANUARY_2016_NFACTORIAL )
