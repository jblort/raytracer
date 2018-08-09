Raytracer
====================

A simple raytracer project to toy with the concept.

## Build instructions

This project depends on CMake and Conan, which need to be installed prior to building this project.
* [CMake installation instructions](https://cmake.org/install/)
* [Conan installation instructions](http://docs.conan.io/en/latest/installation.html)

### Unix/MacOS

From the root of the project:

1. `mkdir build && cd build`
2. `conan install .. && cmake .. && cmake --build .`
3. Run tests with `ctest -V`

### Windows

Not supported for now
