cmake_minimum_required(VERSION 3.6)
project(Thread )

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include/)
link_directories(/usr/include/)


set(SOURCE_FILES main.cpp pedido.cpp pedido.h)
add_executable(Thread ${SOURCE_FILES})
target_link_libraries(Thread pthread)