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

#include "application.h"
#include "ikeyboard_handler.h"

#include <SDL.h>
#include <application_info.h>

namespace ngen {
    Application::Application()
    : m_isWindowed( false )
    , m_isActive( false )
    , m_error( 0 )
    , m_window( nullptr )
    , m_renderer( nullptr )
    {
    }

    Application::~Application() {
        //
    }


    //! \brief  Prepares the application for use by the running title.
    //! \param  info [in] -
    //!         Description of the application being created.
    //! \return <em>True</em> if the application initialized successfully otherwise <em>false</em>.
    bool Application::initialize( const ApplicationInfo &info ) {
        if ( nullptr == m_window ) {
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, info.glMajorVersion );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, info.glMinorVersion );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

            // TODO: Handle info.windowed appropriately

            m_window = SDL_CreateWindow(  "nGen - Example"
                                        , SDL_WINDOWPOS_UNDEFINED
                                        , SDL_WINDOWPOS_UNDEFINED
                                        , 640
                                        , 480
                                        , SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
            if (m_window) {
                m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );
                if ( m_renderer ) {
                    SDL_SetRenderDrawColor( m_renderer, 0x00, 0x00, 0x00, 0xFF );
                    return true;
                }
            }
        }

        return false;
    }


    //! \brief  Signals the application to exist and stores the specified error code.
    //! \param  error [in] -
    //!         The error code the application should exit with.
    void Application::quit( int error ) {
        if ( m_isActive ) {
            m_error = error;
            m_isActive = false;
        }
    }

    //! \brief  Executes the application, does not return until the application has exited.
    void Application::run() {
        m_isActive = true;

        while ( m_isActive ) {
            processEvents();

            if ( m_isActive ) {
                processFrame();
                SDL_Delay(1);
            }
        }

        // TODO: Move into a dispose method
        if ( m_renderer ) {
            SDL_DestroyRenderer( m_renderer );
            m_renderer = nullptr;
        }

        if ( m_window ) {
            SDL_DestroyWindow( m_window );
            m_window = nullptr;
        }
    }


    //! \brief  Processes any pending events for the application.
    void Application::processEvents() {
        SDL_Event event;

        // https://wiki.libsdl.org/SDL_EventType
        while ( SDL_PollEvent( &event ) ) {
            switch ( event.type ) {
                case SDL_KEYDOWN:
                    if ( m_keyboardHandler ) {
                        KeyEventArgs args;

                        //args.keyCode = event.keysym;

                        m_keyboardHandler->onKeyDown( args );
                    }
                    break;

                case SDL_KEYUP:
                    if ( m_keyboardHandler ) {
                        KeyEventArgs args;

                        //args.keyCode = event.keysym;

                        m_keyboardHandler->onKeyUp( args );
                    }
                    break;

                case SDL_QUIT:
                    quit( 0 );
                    break;

                default:
                    break;
            }
        }
    }


    //! \brief  Performs any per-frame processing necessary.
    void Application::processFrame() {
        SDL_RenderClear( m_renderer );
        SDL_RenderPresent( m_renderer );
    }
}
