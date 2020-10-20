cmake_minimum_required(VERSION 3.17)
project(CV_Lab2)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

add_executable(CV_Lab2 main.cpp " threshold_filter.cpp" " threshold_filter.h")

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(CV_Lab2 ${OpenCV_LIBS})