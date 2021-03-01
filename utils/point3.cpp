//
// Created by alexandre on 25/02/2021.
//

#include "point3.h"

raytracer::Point3::Point3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{
    is_none = false;
}

raytracer::Point3::Point3() : Point3(0, 0, 0){}

raytracer::Point3::Point3(bool is_none) {
    is_none = is_none;
}

std::ostream& raytracer::operator<<(std::ostream &out, const Point3 &p) {
    return out << "Vector3 {x=" << p.m_x << ", y=" << p.m_y << ", z=" << p.m_z << "}";
}

