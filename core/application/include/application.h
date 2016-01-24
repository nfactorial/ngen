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

#ifndef NGEN_APPLICATION_H
#define NGEN_APPLICATION_H

struct SDL_Window;
struct SDL_Renderer;
struct IKeyboardHandler;

namespace ngen {
    struct ApplicationInfo;

    class Application {
    public:
        Application();
        ~Application();

        bool initialize( const ApplicationInfo &info );

        void quit( int error );

        void run();

        int getError() const;

        SDL_Window* getWindow() const;

    private:
        void processFrame();
        void processEvents();

    private:
        bool    m_isWindowed;
        bool    m_isActive;
        int     m_error;

        SDL_Window  *m_window;
        SDL_Renderer *m_renderer;       // TEMP

        IKeyboardHandler *m_keyboardHandler;
    };


    //! \brief  Retrieves the error state of the application.
    //! \return The error state of the application.
    inline int Application::getError() const {
        return m_error;
    }


    //! \brief  Retreives the applications window object.
    //! \return The window currently associated with the application.
    inline SDL_Window* Application::getWindow() const {
        return m_window;
    }
}


#endif //NGEN_APPLICATION_H
