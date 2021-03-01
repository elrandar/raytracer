//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_POINT3_H
#define RAYTRACER_POINT3_H

#include <ostream>

namespace raytracer {
    class Point3 {

    public:
        bool is_none{};
        double m_x{};
        double m_y{};
        double m_z{};

        Point3(double x, double y, double z);
        Point3();
        explicit Point3(bool is_none);
    };

    std::ostream &operator<<(std::ostream &out, const Point3 &p);
}

#endif //RAYTRACER_POINT3_H
