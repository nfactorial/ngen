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

#include "display_pipeline.h"
#include "render_layer.h"
#include <ngen/renderer/render_args.h>


namespace ngen {
    DisplayPipeline::DisplayPipeline()
    : m_layerCount(0)
    {
        //
    }

    DisplayPipeline::~DisplayPipeline() {
        //
    }


    //! \brief  Prepares the pipeline for use by the application.
    //! \param  requestProvider [in] -
    //!         Pointer to the request provider that is to be used by the pipeline.
    //! \param  layerCount [in] -
    //!         Number of render layers contained within this pipeline.
    //! \return <em>True</em> if the pipeline initialized successfully otherwise <em>false</em>.
    bool DisplayPipeline::initialize( RequestProvider *requestProvider, size_t layerCount ) {
        if ( requestProvider && !m_layerList ) {
            assert( 1 == layerCount );      // We currently only support a single layer, this will be improved
                                            // once rendering is actually working.

            m_layerList = std::make_unique< RenderLayer[] >( layerCount );  // TODO: Use allocator
            for ( size_t loop = 0; loop < layerCount; ++loop ) {
                if ( !m_layerList[ loop ].initialize( requestProvider ) ) {
                    m_layerList.reset();
                    return false;
                }
            }

            m_layerCount = layerCount;
            return true;
        }

        return false;
    }


    //! \brief  Removes all queued rendering operations from the pipeline.
    void DisplayPipeline::flush() {
        for (size_t loop = 0; loop < m_layerCount; ++loop) {
            m_layerList[ loop ].flush();
        }
    }


    //! \brief  Performs all render operations currently queued within the pipeline.
    //! \param  renderArgs [in] -
    //!         Miscellaneous variables associated with the view being rendered.
    void DisplayPipeline::execute( const RenderArgs &renderArgs ) {
        for (size_t loop = 0; loop < m_layerCount; ++loop) {
            m_layerList[ loop ].execute( renderArgs );
        }
    }


    //! \brief  Adds a new draw request to the rendering pipeline.
    bool DisplayPipeline::addRequest( const DrawRequest &drawRequest ) {
        if (drawRequest.material) {
            for (size_t loop = 0; loop < m_layerCount; ++loop) {
                if (m_layerList[loop].getId() == drawRequest.layerId) {
                    return m_layerList[loop].addRequest( drawRequest );
                }
            }
        }

        return false;
    }
}
