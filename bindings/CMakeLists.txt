cmake_minimum_required(VERSION 3.14.1)
project(optotune-bindings LANGUAGES CXX)

## Dependencies
include(FetchContent)

## Pybind11
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.5.0
)

FetchContent_MakeAvailable(pybind11)

pybind11_add_module(pylensdriver SHARED
  pylensdriver.hpp
  pylensdriver.cpp
  bindings.cpp)

target_link_libraries(pylensdriver
  PRIVATE
  lensdriver-lib)

#cp pylensdriver.cpython-36m-x86_64-linux-gnu.so ~/.pyenv/versions/3.6.9/lib/python3.6/site-packages
