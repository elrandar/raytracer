#include <iostream>
#include <fstream>
#include "utils/vector3.h"
#include "utils/image.h"
#include "scene/sphere.h"
#include "scene/scene.h"
#include "scene/plane.h"
#include "scene/point_light.h"
#include "cmath"
#include "scene/triangle.h"
#include "scene/blob.h"

int main() {
    bool test = true;
    test = false;
    if (test)
    {
        auto v = raytracer::Vector3(45, 68, -32);
        std::cout << v;

        auto img = raytracer::Image(200, 300);
        img.fill_black();

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
    }
    else
    {
        using namespace raytracer;
        auto scene = Scene();

        auto blob = Blob(0.5);
        blob.potential_points.emplace_back(1.75, 0.25, -0.25);
        blob.potential_points.emplace_back(1.75, 0.25, 0.25);
        auto triangles = blob.marching_cubes();
        std::cout << triangles.size();
        for (auto tri : triangles)
        {
            scene.objects.push_back(tri);
        }

        scene.objects.push_back(new Sphere(0.01, Point3(1.5, 0, -0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(1.5, 0, 0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(1.5, 0.5, -0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(1.5, 0.5, 0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(2, 0, -0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(2, 0, 0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(2, 0.5, -0.25)));
        scene.objects.push_back(new Sphere(0.01, Point3(2, 0.5, 0.25)));

        scene.camera = Camera();
//        scene.objects.emplace_back(new Sphere(0.1, Point3(1, 0, 0),
//                                              Color(0, 0, 255)));
//        scene.objects.emplace_back(new Sphere(0.1, Point3(1, 0, -0.3), Color(255, 0, 0)));
//        scene.objects.emplace_back(new Sphere(0.1, Point3(1, 0, 0.3), Color(0, 255, 100)));
//        scene.objects.emplace_back(new Triangle(Point3(1, -0.1, -0.1), Point3(1.2, 0.1, 0), Point3(1, -0.1, 0.1)));
        scene.objects.emplace_back(new Plane(Vector3(0, 1, 0), Point3(0, -0.10, 0)));
//        scene.objects.emplace_back(new Plane(Vector3(1, 0, 0), Point3(7, 0, 0)));
//        scene.lights.emplace_back(new PointLight(0.5, Point3(0, 3, -2)));
        scene.lights.emplace_back(new PointLight(0.5, Point3(0, 1, -1)));
        scene.lights.emplace_back(new PointLight(0.2, Point3(0, 1, 2)));
//        scene.lights.emplace_back(new PointLight(0.5, Point3(1, 0, 0.15)));

        int nb_cols = 1280;
        int nb_rows = 720;

        auto im = scene.generate_image(nb_cols, nb_rows);

//        std::cout << "up=  " << scene.camera.up << "\n up.norm() = " << scene.camera.up.norm();
//        std::cout << "\nImg_height =  " <<img_height << "\nImg_width = " << img_width;
//        std::cout << "\ny_a = " << y_a_scaled << "\nx_a = " << x_a_scaled;
//        std::cout << "\np = " << p << "\n p.norm() = " << p.norm();
//
//        std::cout << "\ntopleft = " << top_left;
//        std::cout << "\nbottomright = " << top_left - (x_a_scaled * nb_cols).to_point()
//                                                    - (y_a_scaled * nb_rows).to_point();

        std::ofstream f;
        f.open("../out.ppm");
        f << im.to_PPM();
        f.close();
    }

    return 0;
}
