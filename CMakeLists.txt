cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracer main.cpp utils/color.cpp utils/color.h utils/vector3.cpp utils/vector3.h utils/point3.cpp utils/point3.h utils/image.cpp utils/image.h scene/scene.cpp scene/scene.h)