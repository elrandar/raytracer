#include <iostream>
#include <fstream>
#include "utils/vector3.h"
#include "utils/image.h"
#include "scene/sphere.h"
#include "scene/scene.h"
#include "scene/plane.h"
#include "scene/point_light.h"
#include "cmath"
int main() {
    bool test = true;
    test = false;
    if (test)
    {
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
    }
    else
    {
        using namespace raytracer;
        auto scene = Scene();
        scene.camera = Camera();
        scene.objects.emplace_back(new Sphere(1, Point3(10, 0.7, 0),
                                              Color(0, 0, 255)));
        scene.objects.emplace_back(new Sphere(0.3, Point3(9, 0, -1), Color(255, 0, 0)));
        scene.objects.emplace_back(new Sphere(0.6, Point3(5, 0.1, 2), Color(0, 255, 100)));
        scene.objects.emplace_back(new Plane(Vector3(0, 1, 0), Point3(0, -200, 0)));
        double nb_cols = 1280;
        double nb_rows = 680;
        auto im = Image(nb_cols, nb_rows);
        im.fill_white();
        auto img_width = 2 * scene.camera.z_min * tan(scene.camera.beta / 2);
        auto img_height = 2 * scene.camera.z_min * tan(scene.camera.alpha / 2);
        auto step_w = img_width / nb_cols;
        auto step_h = img_height / nb_rows;


        auto p = Vector3(scene.camera.center, scene.camera.p);
        auto y_a_scaled = scene.camera.up * step_h;
        auto x_a_scaled = (scene.camera.up ^ (p / p.norm())) * step_w;
        std::cout << "up=  " << scene.camera.up << "\n up.norm() = " << scene.camera.up.norm();
        std::cout << "\nImg_height =  " <<img_height << "\nImg_width = " << img_width;
        std::cout << "\ny_a = " << y_a_scaled << "\nx_a = " << x_a_scaled;
        std::cout << "\np = " << p << "\n p.norm() = " << p.norm();

        Vector3 shift_x = x_a_scaled * (nb_cols / 2 - 0.5);
        Vector3 shift_y = y_a_scaled * (nb_rows / 2 - 0.5);
        Point3 top_left = (scene.camera.p / p.norm()) + shift_x.to_point() + shift_y.to_point();
        std::cout << "\ntopleft = " << top_left;
        std::cout << "\nbottomright = " << top_left - (x_a_scaled * nb_cols).to_point()
                                                    - (y_a_scaled * nb_rows).to_point();

        for (int x = 0; x < nb_cols; x++)
        {
            for (int y = 0; y < nb_rows; y++)
            {
                auto ray = Ray3(scene.camera.center,
                                Vector3(scene.camera.center,
                                        top_left - (x_a_scaled * x).to_point()
                                                 - (y_a_scaled * y).to_point()));
                Object* best_point_obj;
                double best_point_distance = -1;
                for (auto object : scene.objects)
                {
                    Point3 intersection_point = object->find_intersection(ray);

                    if (!intersection_point.m_is_none) {
                        auto point_distance = Vector3(scene.camera.center, intersection_point).norm();
                        if (best_point_distance == -1 || point_distance < best_point_distance) {
                            best_point_obj = object;
                            best_point_distance = point_distance;
                        }
                    }
                    if (best_point_distance != -1)
                        im.set_pixel(x, y, best_point_obj->get_texture_info(0,0).m_color);

                }
            }
        }

        std::ofstream f;
        f.open("../out.ppm");
        f << im.to_PPM();
        f.close();
    }

    return 0;
}
