//
// Created by alexandre on 01/03/2021.
//

#ifndef RAYTRACER_POINT_LIGHT_H
#define RAYTRACER_POINT_LIGHT_H
#include "light.h"

class PointLight : public Light {
public:
    double intensity;
    explicit PointLight(double i);
};


#endif //RAYTRACER_POINT_LIGHT_H
