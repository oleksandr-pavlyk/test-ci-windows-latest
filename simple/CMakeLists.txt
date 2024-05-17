cmake_minimum_required(VERSION 3.29 FATAL_ERROR)

project(
   simples
   VERSION 1
   LANGUAGES C CXX
   DESCRIPTION "Fluff"
)

add_executable(simple_c simple_c.c)
install(TARGETS simple_c RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

add_executable(simple_cxx simple_cxx.cpp)
install(TARGETS simple_cxx RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
