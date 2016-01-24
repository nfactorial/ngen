Render Layer
============
During rendering, objects are sorted into separate layers based on settings within their material. Once all
objects have requested their geometry to be rendered, the framework travels through each layer in an order
specified by the rendering configuration.

Rendering Pipeline
==================
The rendering pipeline is constructed from various stages, split into the following:

    * Display Provider
    * Display Port
    * Display Pipeline
    * Render Layer
    * Material
    * Geometry

The display provider is used to create display regions on the users display, each region is called a display port and
there may be multiple display ports in the running title. When a display port is created the title must specify a
display pipeline that will be used to render the contents of the display.
A display pipeline is split into multiple layers, layers are used to separate rendering into multiple divisions. Each
material must specify which layer it is to be rendered with. Layers may also contain a list of generators, where
a generator may perform some processing using the GPU. Generators typically perform a single stage of simple processing
such as copying a surface, or scaling a texture and so on.
Once a layers generators have completed, the layer processes any materials that have been queued for rendering.