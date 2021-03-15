//
// Created by alexandre on 15/03/2021.
//

#include "blob.h"
#include "../utils/vector3.h"

raytracer::Blob::Blob(double e)
    : e(e),
      corner(Point3(0,0,0)){
    nb_discretisation = 10;
    d = e / nb_discretisation;
    corner = Point3(-0.5, -0.5, -0.5);
}

double raytracer::Blob::find_potential(int x, int y) {
    potential = 0;
    Point3 point_evaluated = corner + Point3(e / 2, y * d, x * d);
    for (auto point : potential_points)
    {
        potential += 1 / Vector3(point, point_evaluated).norm();
    }
}

std::vector<raytracer::Triangle> raytracer::Blob::marching_cubes() {
    auto triangles = std::vector<Triangle>();

    std::vector<std::vector<int>> configurations =
            {
                {1, 2},{}} ;

    for (int x = 0; x < nb_discretisation - 1; x++)
    {
        for (int y = 0; y < nb_discretisation - 1; y++)
        {
            auto down_left = find_potential(x, y);
            auto down_right = find_potential(x + 1, y);
            auto up_left = find_potential(x,y + 1);
            auto up_right = find_potential(x + 1, y);
            int index = 0;
            if (down_left < potential) index |= 1;
            if (down_right < potential) index |= 2;
            if (up_left < potential) index |= 4;
            if (up_right < potential) index |= 8;
        }
    }
    return std::vector<Triangle>();
}

