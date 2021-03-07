//
// Created by alexandre on 07/03/2021.
//

#include "plane.h"
#include "uniform_texture.h"


raytracer::Vector3 raytracer::Plane::get_normal(raytracer::Point3 point3) {
    return normal;
}

raytracer::Point3 raytracer::Plane::find_intersection(raytracer::Ray3 ray) {
    auto a = normal.m_x;
    auto b = normal.m_y;
    auto c = normal.m_z;
    auto d = - a * point.m_x - b * point.m_y - c * point.m_z;

    auto ax = ray.point.m_x;
    auto ay = ray.point.m_y;
    auto az = ray.point.m_z;
    auto dx = ray.vector.m_x;
    auto dy = ray.vector.m_y;
    auto dz = ray.vector.m_z;

    if (a * dx + b * dy + c * dz == 0)
        return Point3(true);
    else
    {
        auto t = -(a * ax + b * ay + c * az + d) / (a * dx + b * dy + c * dz);
        return Point3(ax + t * dx,
                      ay + t * dy,
                      az + t * dz);
    }
}

raytracer::TextureInfo raytracer::Plane::get_texture_info(double x, double y) {
    return mat->get_info(x, y);
}

raytracer::Plane::Plane(raytracer::Vector3 v, raytracer::Point3 pt)
    : normal(v), point(pt) {
    mat = std::make_unique<UniformTexture>(1,1,Color(255, 255, 255));
}

