//
// Created by alexandre on 01/03/2021.
//

#include "sphere.h"
#include "uniform_texture.h"
#include <cmath>

namespace raytracer {
    Point3 raytracer::Sphere::find_intersection(raytracer::Ray3 ray) {
        auto r = radius;
        auto x_0 = center.m_x;
        auto y_0 = center.m_y;
        auto z_0 = center.m_z;

        auto d_x = ray.vector.m_x;
        auto d_y = ray.vector.m_y;
        auto d_z = ray.vector.m_z;

        auto a_x = ray.point.m_x;
        auto a_y = ray.point.m_y;
        auto a_z = ray.point.m_z;

        double a = d_x * d_x + d_y * d_y + d_z * d_z;
        double b = 2 * (d_x * (a_x - x_0) + d_y * (a_y - y_0) + d_z * (a_z - z_0));
        double c = a_x * a_x + a_y * a_y + a_z * a_z + x_0 * x_0 + y_0 * y_0 + z_0 * z_0;
        c = c - 2 * (a_x * x_0 + a_y * y_0 + a_z * z_0) - r * r;

        double delta = b * b - 4 * a * c;

        if (delta < 0)
            return Point3(true);
        else if (delta == 0) {
            double t = -b/ (2 * a);
            return Point3(a_x + t * d_x, a_y + t * d_y, a_z + t * d_z);
        }
        else
        {
            double t_1 = (-b + sqrt(delta)) / (2 * a);
            double t_2 = (-b - sqrt(delta)) / (2 * a);

            double t;
            if (std::abs(t_1) > std::abs(t_2))
                t = t_2;
            else
                t = t_1;
            return Point3(a_x + t * d_x, a_y + t * d_y, a_z + t * d_z);
        }
    }

    raytracer::Vector3 raytracer::Sphere::get_normal(raytracer::Point3 point) {
        return raytracer::Vector3(point.m_x - center.m_x,
                                  point.m_y - center.m_y,
                                  point.m_z - center.m_z);
    }

    raytracer::TextureInfo raytracer::Sphere::get_texture_info(double x, double y) {
        return mat->get_info(x, y);
    }

    Sphere::Sphere(double radius, Point3 center) : radius(radius), center(center) {
        mat = std::make_unique<UniformTexture>(1,1,Color(0, 0, 255));
    }

    Sphere::Sphere(double radius, Point3 center, Color color) : radius(radius), center(center){
        mat = std::make_unique<UniformTexture>(1,1,color);
    }
}