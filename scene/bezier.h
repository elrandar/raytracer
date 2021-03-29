//
// Created by alexandre on 28/03/2021.
//

#ifndef RAYTRACER_BEZIER_H
#define RAYTRACER_BEZIER_H

#include <vector>
#include "object.h"
#include "sphere.h"
#include "triangle.h"

namespace raytracer {
    class Bezier {
    public:
        Point3 p1;
        Point3 p2;
        Point3 pc1;
        Point3 pc2;
    public:
        Bezier();
        Bezier(Point3 p1, Point3 p2, Point3 pc1, Point3 pc2);
        std::vector<Sphere*> generate_spheres() const;
        std::vector<Sphere*> control_points()const;
        std::vector<Triangle*> generate_triangles() const;

        Point3 find_point_on_slope(double t) const;

        Vector3 derivative_at_point(double t) const;
    };
}


#endif //RAYTRACER_BEZIER_H
