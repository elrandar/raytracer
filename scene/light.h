    //
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H
#include "../utils/point3.h"
namespace raytracer {
    class Light {

    public:
        Light() : position(Point3(true)){

        }

        double intensity;
        Point3 position;
    };
}

#endif //RAYTRACER_LIGHT_H
