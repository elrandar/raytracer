//
// Created by alexandre on 25/02/2021.
//
#include "point3.h"

raytracer::Point3::Point3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{
    m_is_none = false;
}

raytracer::Point3::Point3(bool is_none) {
    m_is_none = is_none;
}

raytracer::Point3 raytracer::Point3::operator*(const double &constant) {
    return raytracer::Point3(m_x * constant,
                             m_y * constant,
                             m_z * constant);
}

raytracer::Point3 raytracer::Point3::operator/(const double &constant) {
    return *this * (1 / constant);
}

raytracer::Point3 raytracer::Point3::operator+(const raytracer::Point3 &vec) const {
    return raytracer::Point3(m_x + vec.m_x,
                             m_y + vec.m_y,
                             m_z + vec.m_z);
}

raytracer::Point3 raytracer::Point3::operator-(const raytracer::Point3 &vec) const {
    return raytracer::Point3(m_x - vec.m_x,
                             m_y - vec.m_y,
                             m_z - vec.m_z);
}

const bool raytracer::Point3::operator==(const raytracer::Point3 &pt) const {
    return m_x == pt.m_x && m_y == pt.m_y && m_z == pt.m_z;
}

std::ostream& raytracer::operator<<(std::ostream &out, const Point3 &p) {
    return out << "Vector3 {x=" << p.m_x << ", y=" << p.m_y << ", z=" << p.m_z << "}";
}

