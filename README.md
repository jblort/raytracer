Raytracer
====================

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/10dbe5e10ca1460fa51f53d29d84c5e1)](https://www.codacy.com/app/jblort/raytracer?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jblort/raytracer&amp;utm_campaign=Badge_Grade)
[![Build Status](https://travis-ci.org/jblort/raytracer.svg?branch=master)](https://travis-ci.org/jblort/raytracer)

A simple raytracer project to toy with the concept.

## Build instructions

This project depends on CMake and Conan, which need to be installed prior to building this project.
* [CMake installation instructions](https://cmake.org/install/)
* [Conan installation instructions](http://docs.conan.io/en/latest/installation.html)

Additionally, this projects depends on my public conan repository for now, which can be added via:

    conan remote add <REMOTE-NAME> https://bintray.com/jblort/public-jbl

### Unix/MacOS

From the root of the project (for an out of source build, heavily recommended):

1. `mkdir build && cd build`
2. `conan install .. && cmake .. && cmake --build .`
3. Run tests with `ctest -V`

### Windows

Not supported for now
