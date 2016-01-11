NGEN
====
This library contains some research code for a game engine. There is no particular goal, it's just a place to
try out some ideas for a framework.

Library Layers
==============
The ngen library structure is split into multiple layers. Libraries within each layer may only access other layers
that are higher up the hierarchy. eg. platform layer modules may access modules within ngen, but not other levels
(including the platform layer itself).

ngen
----
This folder contains global NGEN definitions used across all layers. Typically you will find asserts and other
macros defined here.

platform
--------
Here lies various platform wrappers for certain functionality.

core
----
The core libraries include very low level functionality such as memory management.

lowlevel
--------
Low level functionality.

highlevel
---------
High level functionality that may make use of other lower level libraries.