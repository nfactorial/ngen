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

#ifndef NGEN_DISPLAY_PIPELINE_H
#define NGEN_DISPLAY_PIPELINE_H


////////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include <ngen/renderer/draw_request.h>


////////////////////////////////////////////////////////////////////////////

namespace ngen {
    struct RenderArgs;

    class RenderLayer;
    class RequestProvider;

    //! \brief  Manages a rendering pipeline for a single display port.
    class DisplayPipeline {
    public:
        DisplayPipeline();
        ~DisplayPipeline();

        bool initialize( RequestProvider *requestProvider, size_t layerCount );

        void execute( const RenderArgs &renderArgs );

        void flush();

        bool addRequest(const DrawRequest &drawRequest);

    private:
        size_t m_layerCount;
        RenderLayer *m_layerList;
    };
}


////////////////////////////////////////////////////////////////////////////

#endif //NGEN_DISPLAY_PIPELINE_H
