cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracer main.cpp color.cpp color.h vector3.cpp vector3.h point3.cpp point3.h)