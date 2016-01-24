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

DisplayPipeline::DisplayPipeline()
: m_layerCount( 0 )
, m_layerList( nullptr )
{
    //
}

DisplayPipeline::~DisplayPipeline() {
    //
}


//! \brief  Removes all queued rendering operations from the pipeline.
void DisplayPipeline::flush() {
    for ( size_t loop = 0; loop < m_layerCount; ++loop ) {
        //m_layerList[ loop ]->flush();
    }
}


//! \brief  Performs all render operations currently queued within the pipeline.
void DisplayPipeline::execute() {
    for ( size_t loop = 0; loop < m_layerCount; ++loop ) {
        //m_layerList[ loop ]->execute();
    }
}


//! \brief  Adds a new draw request to the rendering pipeline.
bool DisplayPipeline::addRequest( )
{
/*
    if ( drawRequest.material ) {
        const int layerId = drawRequest.material->getLayerId();

        for (size_t loop = 0; loop < m_layerCount; ++loop) {
            if (m_layerList[loop]->getId() == drawRequest.id) {
                m_layerList[loop]->addRequest( drawRequest );
            }
        }
    }
*/
}
