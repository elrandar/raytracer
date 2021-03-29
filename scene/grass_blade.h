//
// Created by alexandre on 29/03/2021.
//

#ifndef RAYTRACER_GRASS_BLADE_H
#define RAYTRACER_GRASS_BLADE_H


#include "bezier.h"

namespace raytracer {
    class GrassBlade {
    public:
        Point3 base_point;
        double height;
        double offset;
        double width;
        Vector3 normal_vec;
        Bezier bezier_curve;

    public:
        GrassBlade(const Point3 &basePoint, double height);
        GrassBlade(const Point3 &basePoint, double height,
                   double offset, double width, const Vector3 &normalVec);

        std::vector<Triangle*> generate_triangles() const;
    };
}


#endif //RAYTRACER_GRASS_BLADE_H
