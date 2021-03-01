#include <iostream>
#include <fstream>
#include "utils/vector3.h"
#include "utils/image.h"
#include "scene/sphere.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    auto v = raytracer::Vector3(45, 68, -32);
    std::cout << v;

    auto img = raytracer::Image(200, 300);
    img.fill_white();

    for (int i = 50; i < 100; i++)
    {
        for (int j = 50; j < 100; j++)
        {
            img.m_pix_array[i * img.m_width + j] = raytracer::Color(255, 0, 0);
        }
    }

    std::ofstream f;
    f.open("../out.ppm");
    f << img.to_PPM();
    f.close();

    auto sph = raytracer::Sphere(0.10, raytracer::Point3(-10, 0, 0));
    auto p = sph.find_intersection(raytracer::Ray3(raytracer::Point3(0, 0, 0),
                                          raytracer::Vector3(2, 0, 0)));
    std::cout << '\n' << p;
    return 0;
}
