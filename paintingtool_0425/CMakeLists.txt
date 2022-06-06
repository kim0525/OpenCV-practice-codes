cmake_minimum_required(VERSION 3.22)
project(paintingtool_0425)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp menu.hpp icon_flag.hpp)
add_executable(paintingtool_0425 ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(paintingtool_0425 ${OpenCV_LIBS})
