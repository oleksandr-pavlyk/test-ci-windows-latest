cmake_minimum_required(VERSION 3.29 FATAL_ERROR)

project(test_ext VERSION 0.1 LANGUAGES CXX DESCRIPTION "Example of test")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Define CMAKE_INSTALL_xxx: LIBDIR, INCLUDEDIR
include(GNUInstallDirs)

# Fetch pybind11
include(FetchContent)

FetchContent_Declare(
    pybind11
    URL https://github.com/pybind/pybind11/archive/refs/tags/v2.12.0.tar.gz
    URL_HASH SHA256=bf8f242abd1abcd375d516a7067490fb71abd79519a282d22b6e4d19282185a7
)
FetchContent_MakeAvailable(pybind11)

find_package(Python REQUIRED COMPONENTS Development.Module)

set(py_module_name _test_ext)
set(_sources src/py.cpp)

pybind11_add_module(${py_module_name} MODULE ${_sources})

install(TARGETS ${py_module_name}
  DESTINATION test_ext
)

