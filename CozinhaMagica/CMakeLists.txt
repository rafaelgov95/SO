cmake_minimum_required(VERSION 3.6)
project(CozinhaMagica)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/include/)
link_directories(/usr/include/)

set(SOURCE_FILES main.cpp Cozinheiro.cpp Cozinheiro.h Cardapio.cpp Cardapio.h)
add_executable(CozinhaMagica ${SOURCE_FILES})
target_link_libraries(CozinhaMagica pthread)