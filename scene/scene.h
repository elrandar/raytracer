//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include <vector>
#include "light.h"
#include "camera.h"
#include "object.h"

namespace raytracer {
    class Scene {
    public:
        std::vector<Light*> lights;
        std::vector<Object*> objects;
        Camera camera;
    };
}

#endif //RAYTRACER_SCENE_H
