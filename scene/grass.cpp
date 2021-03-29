//
// Created by alexandre on 29/03/2021.
//

#include "grass.h"
#include "grass_blade.h"

std::vector<raytracer::Triangle*> raytracer::Grass::generate() {
    auto triangles = std::vector<Triangle*>();

    double xdist = std::abs((start - end).m_x);
    double zdist = std::abs((start - end).m_z);
    double xstep = xdist / count;
    double zstep = zdist / count;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            auto blade = GrassBlade(start + Point3(xstep * i, 0, zstep * i),
                                    0.35, 0.1, 0.35 / 16,
                                    Vector3(1, 0,  0));
            auto triangles_b = blade.generate_triangles();
            triangles.insert(triangles.end(), triangles_b.begin(), triangles_b.end());
        }
    }
    return triangles;
}

raytracer::Grass::Grass(const raytracer::Point3 &start, const raytracer::Point3 &anEnd, int count) : start(start),
                                                                                                     end(anEnd),
                                                                                                     count(count) {}
