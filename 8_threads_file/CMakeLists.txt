cmake_minimum_required(VERSION 3.13)
project(myFirstThreads)

set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)

add_executable(8_threads_file main.cpp)
target_link_libraries(8_threads_file ${CMAKE_THREAD_LIBS_INIT} )