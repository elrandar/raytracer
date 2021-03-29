//
// Created by alexandre on 15/03/2021.
//

#ifndef RAYTRACER_BLOB_H
#define RAYTRACER_BLOB_H
#include "../utils/point3.h"
#include "triangle.h"
#include <vector>

namespace raytracer {
    class Blob {
    public:
        Blob(double e);
        double find_potential(int x, int y);
        double find_potential(int x, int y, int z);
        std::vector<Triangle*> marchingSquares();
        std::vector<Triangle*> marchingCubes();
    public:
        std::vector<Point3> potential_points;
        Point3 corner;
        double e;
        double d;
        int nb_discretisation;
        double potential;
    };
}


#endif //RAYTRACER_BLOB_H
