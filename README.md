# Template For C++ Projects

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20%2F23-blue)
![License](https://camo.githubusercontent.com/890acbdcb87868b382af9a4b1fac507b9659d9bf/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)
![Linux Build](https://github.com/franneck94/CppProjectTemplate/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/franneck94/CppProjectTemplate/branch/master/graph/badge.svg)](https://codecov.io/gh/franneck94/CppProjectTemplate)

This is a template for C++ projects. What you get:

- Library, executable and test code separated in distinct folders
- Use of modern CMake for building and compiling
- External libraries installed and managed by
  - CMake's [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) OR
  - [Conan](https://conan.io/) Package Manager OR
  - [VCPKG](https://github.com/microsoft/vcpkg) Package Manager
- Unit testing using [Catch2](https://github.com/catchorg/Catch2)
- General purpose libraries: [JSON](https://github.com/nlohmann/json), [spdlog](https://github.com/gabime/spdlog), [cxxopts](https://github.com/jarro2783/cxxopts) and [fmt](https://github.com/fmtlib/fmt)
- Continuous integration testing with Github Actions and [pre-commit](https://pre-commit.com/)
- Code coverage reports, including automatic upload to [Codecov](https://codecov.io)
- Code documentation with [Doxygen](https://doxygen.nl/) and [Github Pages](https://franneck94.github.io/CppProjectTemplate/)

## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src
│   ├── CMakesLists.txt
│   ├── my_lib.h
│   └── my_lib.cc
└── tests
    ├── CMakeLists.txt
    └── main.cc
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Software Requirements

- CMake 3.16+
- GNU Makefile
- Doxygen
- Conan or VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)
- Code Coverage (only on GNU|Clang): lcov, gcovr

## Building

First, clone this repo and do the preliminary work:

```shell
git clone --recursive https://github.com/franneck94/CppProjectTemplate
make prepare
```

- App Executable

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target main
cd app
./main
```

- Unit testing

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target unit_tests
cd tests
./unit_tests
```

- Documentation

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target docs
```

- Code Coverage (Unix only)

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..
cmake --build . --config Debug --target coverage
```

For more info about CMake see [here](./CMakeGuide.md).

# How to install VCPKG

Official Link: <https://vcpkg.io/en/index.html>

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat # windows
./vcpkg/bootstrap-vcpkg.sh # Unix
```

# Formatter and Static Analyzer

## Tooling

Clang-Format: Formatting tool for your C/C++ code
Clang-Tidy: Static linting tool for your C/C++ code

- Documentation for Clang-Format: [Link](https://clang.llvm.org/docs/ClangFormat.html)
- Documentation for Clang-Tidy: [Link](https://clang.llvm.org/extra/clang-tidy/)

## Install

Linux

```bash
sudo apt-get install clang-format
sudo apt-get install clang-tidy
```

MacOS

```bash
brew install clang-format
brew install clang-tidy
```

Windows

```bash
choco install llvm
````
