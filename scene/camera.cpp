//
// Created by alexandre on 01/03/2021.
//

#include "camera.h"
#include "../utils/point3.h"

raytracer::Camera::Camera() :
center(Point3(0,-0.35,0)),
p(Point3(10,0,0)){
    alpha = 0.7;
    beta = (double)16/(double)9 * alpha;
    up = Vector3(0, 1.0, 0);
    z_min = 1;
}
