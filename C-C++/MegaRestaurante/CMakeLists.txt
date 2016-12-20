cmake_minimum_required(VERSION 3.6)
project(MegaRestaurante)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Mesa.cpp Mesa.h Cozinheiro.cpp Cozinheiro.h)
add_executable(MegaRestaurante ${SOURCE_FILES})