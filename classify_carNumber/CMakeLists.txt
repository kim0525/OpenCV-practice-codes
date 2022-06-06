cmake_minimum_required(VERSION 3.22)
project(classify_carNumber)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp preprocess.hpp candiate.hpp SVM.hpp kNN.hpp classify_objects.hpp)
add_executable(classify_carNumber ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(classify_carNumber ${OpenCV_LIBS})
