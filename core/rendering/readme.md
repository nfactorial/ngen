NGEN Renderer
=============
This folder and sub-folders contains the implementation of the rendering system for nGen.

The renderer is split into two main sections:

Display
=======
This folder contains the generic cross-platform rendering implementation, it does not contain the actual rendering
code but, instead, contains code for managing display ports and rendering layers.

ngen_opengl
===========
This folder contains the OpenGL rendering implementation.

Whilst only OpenGL rendering is currently supported, it is intended for different rendering API's to be targettable
via the introduction of new API specific folders.

It is not currently intended for different API targets to be chosen dynamically at run-time, but should be chosen
at compile time for the appropriate platform. However, for now, only OpenGL is currently supported.
