//
// Created by alexandre on 01/03/2021.
//

#ifndef RAYTRACER_POINT_LIGHT_H
#define RAYTRACER_POINT_LIGHT_H
#include "light.h"
#include "../utils/point3.h"

namespace raytracer {
    class PointLight : public Light {
    public:

        explicit PointLight(double i, Point3 pos);
    };
}

#endif //RAYTRACER_POINT_LIGHT_H
