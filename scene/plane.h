//
// Created by alexandre on 07/03/2021.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H
#include "object.h"
namespace raytracer {
    class Plane : public Object {
    public:
        Vector3 normal;
        Point3 point;

        Vector3 get_normal(Point3 point3) override;
        Point3 find_intersection(Ray3 ray) override;
        TextureInfo get_texture_info(double x, double y) override;

        Plane(Vector3 v, Point3 pt);

    };
}

#endif //RAYTRACER_PLANE_H
