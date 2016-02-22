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

#include <boost/crc.hpp>

#include "program_factory.h"
#include "program.h"


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    ProgramFactory::ProgramFactory()
    : m_capacity( 0 )
    {
        //
    }

    ProgramFactory::~ProgramFactory() {
        //
    }


    //! \brief  Prepares the object for use by the application.
    //! \param  programCapacity [in] -
    //!         Maximum number of programs that may be contained withiun the factory.
    //! \return <em>True</em> if the factory initialized successfully otherwise <em>false</em>.
    bool ProgramFactory::initialize( size_t programCapacity ) {
        return false;
    }


    //! \brief  Deletes a program from the factory object and releases any associated resources.
    //! \param  name [in] -
    //!         Name of the program to be deleted.
    void ProgramFactory::deleteProgram( const char *name ) {
        if ( name ) {
            const size_t nameLength = strlen( name );

            if ( nameLength > 0 ) {
                boost::crc_32_type crc;

                crc.process_block(name, &name[nameLength]);

                if ( m_programMap.end() != m_programMap.find( crc.checksum() ) ) {
                    m_programMap.erase( crc.checksum() );
                }
            }
        }
    }


    //! \brief  Attempts to create a new program using the supplied input.
    //! \param  name [in] -
    //!         The name to be associated with the program.
    //! \param  vertexShader [in] -
    //!         The source code for the vertex shader belonging to the program.
    //! \param  pixelShader [in] -
    //!         The source code for the pixel shader belonging to the program.
    //! \return <em>True</em> if the program created successfully otherwise <em>false</em>.
    bool ProgramFactory::createProgram( const char *name, const char *vertexShader, const char *pixelShader ) {
        if ( name ) {
            const size_t nameLength = strlen( name );
            if ( 0 != nameLength ) {
                GLProgram *program = findProgram(name);
                if (!program) {
                    program = new GLProgram();      // TODO: Use allocator
                    if (program->initialize(vertexShader, pixelShader)) {
                        // TODO: Add to collection
                        boost::crc_32_type crc;

                        crc.process_block(name, &name[nameLength]);

                        m_programMap.insert(ProgramMap::value_type(crc.checksum(), program));
                        return true;
                    }

                    delete program;
                } else {
                    // TODO: Verify the program we found contains the specified shaders.
                }
            }
        }

        return false;   // TODO: Still undecided whether to return true/false or the program pointer.
    }


    //! \brief  Attempts to locate a previously created program within the factory.
    //! \param  name [in] -
    //!         The name associated with the program to be retrieved.
    //! \return Pointer to the shader associated with the specified name or <em>nullptr</em> if one could not be found.
    GLProgram* ProgramFactory::findProgram( const char *name ) const {
        if ( name ) {
            const size_t nameLength = strlen( name );

            if ( 0 != nameLength ) {
                boost::crc_32_type crc;

                crc.process_block(name, &name[nameLength]);

                return findProgramById( crc.checksum() );
            }
        }

        return nullptr;
    }

    GLProgram* ProgramFactory::findProgramById( size_t id ) const {
        ProgramMap::const_iterator it = m_programMap.find( id );
        if ( it != m_programMap.end() ) {
            return it->second;
        }

        return nullptr;
    }
}
