//
// Created by alexandre on 01/03/2021.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H
#include "object.h"
#include "../utils/point3.h"
namespace raytracer {

    class Sphere : public Object {
    public:
        Point3 center;
        double radius;

        Point3 find_intersection(Ray3 ray) override;
        Vector3 get_normal(Point3 point, Vector3 in_vec) override;
        TextureInfo get_texture_info(double x, double y) override;


        Sphere(double radius, Point3 center);
        Sphere(double radius, Point3 center, Color color);
    };
}


#endif //RAYTRACER_SPHERE_H
