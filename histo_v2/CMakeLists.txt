cmake_minimum_required(VERSION 3.22)
project(histo_v2)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp histo.hpp utils.hpp)
add_executable(histo_v2 ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(histo_v2 ${OpenCV_LIBS})
