//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include <vector>
#include "light.h"
#include "camera.h"
#include "object.h"
#include "../utils/image.h"

namespace raytracer {
    class Scene {
    public:
        std::vector<Light*> lights;
        std::vector<Object*> objects;
        Camera camera;

        raytracer::Image generate_image(int nb_cols, int nb_rows);
        Color cast_ray(Ray3 ray) const;
        bool is_blocked(Ray3 ray, Object *pObject) const;

        void process_part(int start_col, int end_col,
                          int start_row, int end_row,
                          const Vector3 &y_a_scaled, const Vector3 &x_a_scaled,
                          const Point3 &top_left, std::vector<Color> *vec) const;
    };
}

#endif //RAYTRACER_SCENE_H
