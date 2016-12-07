cmake_minimum_required(VERSION 3.6)
project(TrabalhoAlocamentoDeMemoria)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GerenciadorDeMemoria.cpp GerenciadorDeMemoria.h)
add_executable(TrabalhoAlocamentoDeMemoria ${SOURCE_FILES})