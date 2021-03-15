//
// Created by alexandre on 15/03/2021.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H
#include "object.h"
namespace raytracer {
    class Triangle : public Object {
    public:
        Triangle(Point3 a,  Point3 b, Point3 c);
        Vector3 get_normal(Point3 point, Vector3 in_vec) override;
        TextureInfo get_texture_info(double x, double y) override;
        Point3 find_intersection(Ray3 ray) override;

    public:
        Point3 a;
        Point3 b;
        Point3 c;
    };
}

#endif //RAYTRACER_TRIANGLE_H
