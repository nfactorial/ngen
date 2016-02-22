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

#ifndef NGEN_PROGRAM_FACTORY_H
#define NGEN_PROGRAM_FACTORY_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include <unordered_map>

#include "program.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    class GLProgram;

    //!< \brief Provides access to a set of shader programs.
    class ProgramFactory {
        typedef std::unordered_map< size_t, GLProgram* > ProgramMap;

    public:
        ProgramFactory();
        ~ProgramFactory();

        bool initialize( size_t programCapacity );

        void deleteProgram( const char *name );
        bool createProgram( const char *name, const char *vertexShader, const char *pixelShader );

        GLProgram* findProgramById( size_t id ) const;
        GLProgram* findProgram( const char *name ) const;

        size_t getCount() const;
        size_t getCapacity() const;

    private:
        size_t m_capacity;

        ProgramMap  m_programMap;
    };


    //! \brief  Retrieves the number of programs currently contained within the factory.
    //! \return The number of programs currently contained within the factory.
    inline size_t ProgramFactory::getCount() const {
        return m_programMap.size();
    }


    //! \brief  Retrieves the maximum number of programs the factory object may contain.
    //! \return The maximum number of programs that may be contained within the factory.
    inline size_t ProgramFactory::getCapacity() const {
        return m_capacity;
    }
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_PROGRAM_FACTORY_H
