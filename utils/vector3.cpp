//
// Created by alexandre on 25/02/2021.
//

#include "vector3.h"

raytracer::Vector3::Vector3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{}

raytracer::Vector3::Vector3() : Vector3(0, 0, 0)
{}

raytracer::Vector3 raytracer::Vector3::operator*(const double &constant) {
    m_x = m_x * constant;
    m_y = m_y * constant;
    m_z = m_z * constant;
    return raytracer::Vector3(m_x * constant,
                              m_y * constant,
                              m_z * constant);
}

raytracer::Vector3 raytracer::Vector3::operator+(const raytracer::Vector3 &other) {
    return raytracer::Vector3(m_x + other.m_x,
                              m_y + other.m_y,
                              m_z + other.m_z);
}

raytracer::Vector3 raytracer::Vector3::operator-(const raytracer::Vector3 &other) {
    return raytracer::Vector3(m_x - other.m_x,
                              m_y - other.m_y,
                              m_z - other.m_z);
}

raytracer::Vector3::Vector3(const raytracer::Point3 &start, const raytracer::Point3 &end)
    : Vector3(end.m_x - start.m_x,
              end.m_y - start.m_y,
              end.m_z - start.m_z){
}

std::ostream &raytracer::operator<<(std::ostream &out, const raytracer::Vector3 &v) {
    return out << "Vector3 {x=" << v.m_x << ", y=" << v.m_y << ", z=" << v.m_z << "}";
}