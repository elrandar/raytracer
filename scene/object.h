//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include <memory>
#include "texture_material.h"
#include "../utils/ray3.h"

namespace raytracer {
    class Object {

        virtual Point3 find_intersection(Ray3 ray) = 0;
        virtual Vector3 get_normal(Point3 point) = 0;
        virtual TextureInfo get_texture_info(double x, double y) = 0;

    protected:
        std::unique_ptr<TextureMaterial> mat;
    };
}


#endif //RAYTRACER_OBJECT_H
