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

#ifndef NGEN_SYSTEM_CRC_H
#define NGEN_SYSTEM_CRC_H


////////////////////////////////////////////////////////////////////////////

#include <boost/crc.hpp>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    //! \brief  Computes a checksum for the supplied block of data.
    //!
    //! The checksum is used within the factory instead of the raw string. This is to simplify the
    //! look-up. If collisions occur within different names, the checksum calculation can be changed
    //! or the name that is causing the collision.
    inline size_t calculateChecksum( const char *name, size_t length ) {
        // This function assumes the input has already been sanity checked
        boost::crc_32_type crc;

        crc.process_block(name, &name[length]);

        return crc.checksum();
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_SYSTEM_CRC_H
