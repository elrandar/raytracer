//
// Created by alexandre on 29/03/2021.
//

#ifndef RAYTRACER_GRASS_H
#define RAYTRACER_GRASS_H

#include "bezier.h"

namespace raytracer {
    class Grass {
    public:
        Point3 start;
        Point3 end;
        int count;

    public:
        Grass(const Point3 &start, const Point3 &anEnd, int count);

        std::vector<Triangle*> generate();
    };
}

#endif //RAYTRACER_GRASS_H
