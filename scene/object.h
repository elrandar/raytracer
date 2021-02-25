//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "texture_material.h"
#include "../utils/ray3.h"

namespace raytracer {
    class object {

        TextureMaterial mat;

        virtual bool is_intersected(Ray3 ray) = 0;
        virtual Vector3 get_normal(float x, float y) = 0;
        
    };
}


#endif //RAYTRACER_OBJECT_H
