External Folder
===============
The external folder contains any dependency modules that are not a part of the actual library.

Currently this project expects the following projects to reside within this folder:

GoogleTest
==========
https://github.com/google/googletest

The project expects GoogleTest (Version 1.7.0) to reside within external/gtest-1-7.0/

Boost
=====
http://www.boost.org/

Boost version 1.6.0 should reside within external/boost_1_60_0

Vectormath
==========
https://github.com/erwincoumans/sce_vectormath

Optimised Vector math library.

Bullet Physics
==============
https://github.com/bulletphysics/bullet3

Physics library that will be used by the engine. nGen currently disables the unit tests for Bullet, as the Google
test framework inside bullet conflicts with nGen's. This will be addressed in the future.


I may provide a script in the future to ensure dependencies can be automatically installed. However, for now, please
install these manually.

