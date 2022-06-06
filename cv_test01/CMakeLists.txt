cmake_minimum_required(VERSION 3.21)
project(cv_test01)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED) # 추가1
set(SOURCE_FILES main.cpp)  # 내용 수정

add_executable(${PROJECT_NAME}${SOURCE_FILES}) # 추가
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}${OpenCV_LIBS})
