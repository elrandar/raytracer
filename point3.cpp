//
// Created by alexandre on 25/02/2021.
//

#include "point3.h"

raytracer::Point3::Point3(float x, float y, float z)
    : m_x(x), m_y(y), m_z(z)
{}

raytracer::Point3::Point3() : Point3(0, 0, 0){}

std::ostream& raytracer::operator<<(std::ostream &out, const Point3 &p) {
    return out << "Vector3 {x=" << p.m_x << ", y=" << p.m_y << ", z=" << p.m_z << "}";
}

