//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

#include <ostream>
#include "point3.h"

namespace raytracer {

    class Vector3 {
    public:
        double m_x;
        double m_y;
        double m_z;

        Vector3();
        Vector3(double x, double y, double z);
        Vector3(const Point3 &start, const Point3 &end);

        double norm() const;
        Point3 to_point() const;
        Vector3 operator*(const double &constant) const;
        Vector3 operator/(const double &constant);
        Vector3 operator+(const Vector3 &other);
        Vector3 operator-(const Vector3 &other);
        Vector3 operator^(const Vector3 &other);
        double  operator*(const Vector3 &other);


    };
    Point3 operator+(const Point3 &pt, const Vector3 &vec);
    Point3 operator-(const Point3 &pt, const Vector3 &vec);
    std::ostream& operator<<(std::ostream &out, const Vector3& v);
}


#endif //RAYTRACER_VECTOR3_H
