cmake_minimum_required(VERSION 3.6)
project(Restaurante)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp RestauranteApp.cpp RestauranteApp.h Restaurante.cpp Restaurante.h ChefeCozinha.cpp ChefeCozinha.h)
add_executable(Restaurante ${SOURCE_FILES})