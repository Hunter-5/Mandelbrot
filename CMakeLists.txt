cmake_minimum_required(VERSION 2.8)

project(Mandelbrot)

find_package(X11 REQUIRED)

FILE(GLOB_RECURSE LibFiles "cplane.hpp")
add_custom_target(headers SOURCES ${LibFiles})
add_executable(${PROJECT_NAME} "main.cpp" "cplane.cpp")

include_directories(${X11_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})
