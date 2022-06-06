cmake_minimum_required(VERSION 3.22)
project(cv_test03)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp)
add_executable(cv_test03 ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(cv_test03 ${OpenCV_LIBS})
