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

#include "render_layer.h"
#include "gtest/gtest.h"

TEST( RenderLayer, Construction ) {
    RenderLayer layer;

    EXPECT_EQ( 0, layer.getId() );
    EXPECT_EQ( 0, layer.getRequestCount() );
    EXPECT_FALSE( layer.addRequest() );         // We cannot add a request to an uninitialized layer
}


TEST( RenderLayer, Flush ) {
    RenderLayer layer;

    // TODO: Add some requests so flush actually has something to do

    layer.flush();

    EXPECT_EQ( 0, layer.getRequestCount() );
}