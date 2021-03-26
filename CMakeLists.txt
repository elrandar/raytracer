cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


add_executable(raytracer main.cpp utils/color.cpp utils/color.h utils/vector3.cpp
        utils/vector3.h utils/point3.cpp utils/point3.h utils/image.cpp utils/image.h
        scene/scene.cpp scene/scene.h scene/texture_material.h scene/object.h scene/light.h
        scene/uniform_texture.cpp scene/uniform_texture.h utils/ray3.cpp utils/ray3.h scene/sphere.cpp
        scene/sphere.h scene/point_light.cpp scene/point_light.h scene/camera.cpp scene/camera.h scene/plane.cpp scene/plane.h
        scene/triangle.cpp scene/triangle.h scene/blob.cpp scene/blob.h)

target_link_libraries(raytracer PRIVATE Threads::Threads)