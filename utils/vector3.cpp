//
// Created by alexandre on 25/02/2021.
//

#include "vector3.h"
#include <cmath>
raytracer::Vector3::Vector3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{}

raytracer::Vector3::Vector3() : Vector3(0, 0, 0)
{}

raytracer::Vector3 raytracer::Vector3::operator*(const double &constant) const {
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

raytracer::Vector3 raytracer::Vector3::operator^(const raytracer::Vector3 &other) {
    return raytracer::Vector3(m_y * other.m_z - m_z * other.m_y,
                              m_z * other.m_x - m_x * other.m_z,
                              m_x * other.m_y - m_y * other.m_x);
}

double raytracer::Vector3::norm() const {
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

raytracer::Vector3 raytracer::Vector3::operator/(const double &constant) {
    return *this * (1/constant);
}

raytracer::Point3 raytracer::Vector3::to_point() const {
    return Point3(m_x, m_y, m_z);
}

double raytracer::Vector3::operator*(const raytracer::Vector3 &other) {
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

std::ostream &raytracer::operator<<(std::ostream &out, const raytracer::Vector3 &v) {
    return out << "Vector3 {x=" << v.m_x << ", y=" << v.m_y << ", z=" << v.m_z << "}";
}

raytracer::Point3 raytracer::operator+(const raytracer::Point3 &pt, const raytracer::Vector3 &vec) {
    return raytracer::Point3(pt.m_x + vec.m_x, pt.m_y + vec.m_y, pt.m_z + vec.m_z);
}

raytracer::Point3 raytracer::operator-(const raytracer::Point3 &pt, const raytracer::Vector3 &vec) {
    return raytracer::Point3(pt.m_x - vec.m_x, pt.m_y - vec.m_y, pt.m_z - vec.m_z);
}
