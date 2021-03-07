//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_POINT3_H
#define RAYTRACER_POINT3_H

#include <ostream>

namespace raytracer {

    class Point3 {

    public:
        bool m_is_none{};
        double m_x{};
        double m_y{};
        double m_z{};

        Point3(double x, double y, double z);
        explicit Point3(bool is_none);
        Point3 operator*(const double &constant);
        Point3 operator/(const double &constant);
        Point3 operator+(const Point3 &pt) const;
        Point3 operator-(const Point3 &pt) const;
    };
    std::ostream& operator<<(std::ostream &out, const Point3& v);
   
}

#endif //RAYTRACER_POINT3_H
