cmake_minimum_required(VERSION 3.6)
project(CozinhaMagica2)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/include/)
link_directories(/usr/include/)

set(SOURCE_FILES main.cpp )
add_executable(CozinhaMagica2 ${SOURCE_FILES})
target_link_libraries(CozinhaMagica2 pthread -lm -lrt)