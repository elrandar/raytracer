//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_POINT3_H
#define RAYTRACER_POINT3_H

#include <ostream>

namespace raytracer {
    class Point3 {

    public:
        float m_x;
        float m_y;
        float m_z;

        Point3(float x, float y, float z);
        Point3();
    };

    std::ostream &operator<<(std::ostream &out, const Point3 &p);
}

#endif //RAYTRACER_POINT3_H
