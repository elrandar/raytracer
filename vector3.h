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
        float m_x;
        float m_y;
        float m_z;

        Vector3();
        Vector3(float x, float y, float z);
        Vector3(const Point3 &start, const Point3 &end);

        Vector3 operator*(const float &constant);
        Vector3 operator+(const Vector3 &other);
        Vector3 operator-(const Vector3 &other);


    };

    std::ostream& operator<<(std::ostream &out, const Vector3& v);
}


#endif //RAYTRACER_VECTOR3_H
