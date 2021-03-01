//
// Created by alexandre on 01/03/2021.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H
#include "../utils/point3.h"
#include "../utils/vector3.h"

namespace raytracer {
    class Camera {
    public:
        Point3 center;
        Point3 p;
        Vector3 up;
        double alpha;
        double beta;
        double z_min;
    };
}

#endif //RAYTRACER_CAMERA_H
