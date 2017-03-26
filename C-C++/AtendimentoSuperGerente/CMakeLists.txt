cmake_minimum_required(VERSION 3.6)
project(AtendimentoSuperGerente)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Atendente.cpp Atendente.h)
add_executable(AtendimentoSuperGerente ${SOURCE_FILES})