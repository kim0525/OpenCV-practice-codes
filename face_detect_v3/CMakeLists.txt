cmake_minimum_required(VERSION 3.22)
project(face_detect_v3)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp preprocess.hpp correct_angle.hpp detect_area.hpp)
add_executable(face_detect_v3 ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(face_detect_v3 ${OpenCV_LIBS})
