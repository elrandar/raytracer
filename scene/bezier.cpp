//
// Created by alexandre on 28/03/2021.
//

#include "bezier.h"
#include "uniform_texture.h"
#include <memory>
#include <limits>
#include <cmath>


raytracer::Bezier::Bezier(raytracer::Point3 p1, raytracer::Point3 p2,
                          raytracer::Point3 pc1, raytracer::Point3 pc2)
                          : p1(p1), p2(p2), pc1(pc1), pc2(pc2){
}

std::vector<raytracer::Sphere *> raytracer::Bezier::generate_spheres() const {
    auto spheres = std::vector<raytracer::Sphere*>();


    auto sphere_rad = Vector3(p1, p2).norm() / 16;
    double t = 0;
    int i = 0;
    while (t <= 1)
    {
        std::vector<Color> cols = {Color(0, 255, 0), Color(255, 0, 0),
                                Color(255, 255, 0), Color(255, 255, 255),
                                Color(0, 0, 255)};
        spheres.push_back(new Sphere(sphere_rad, find_point_on_slope(t), cols[0]));
        t += 0.01;
        i++;
    }

    return spheres;
}

std::vector<raytracer::Triangle*> raytracer::Bezier::generate_triangles() const {
    auto triangles = std::vector<raytracer::Triangle*>();

    std::vector<Point3> pairs = std::vector<Point3>();

    auto step = Vector3(p1, p2).norm() / 3;
    auto width = Vector3(p1, p2).norm() / 16;
    double t = 0;
    while (t <= 1)
    {
        auto point = find_point_on_slope(t);
        auto derivative = derivative_at_point(t);
        auto normal = derivative ^ Vector3(1, 0, 0);
        normal = normal / normal.norm();

        auto point1 = point + normal * (width - 0.5 * width * t);
        auto point2 = point - normal * (width - 0.5 * width * t);


        pairs.push_back(point1);
        pairs.push_back(point2);
        t += step;
    }

    pairs.pop_back();
    pairs.pop_back();
    pairs.push_back(find_point_on_slope(1));

    int i = 0;
    while (i < pairs.size())
    {
        if (pairs.size() - i >= 3)
        {
            auto col = Color(255, 0, 255);
            if (i % 2 == 0)
                col = Color(0, 255, 255);
            triangles.push_back(new Triangle(pairs[i], pairs[i + 1],  pairs[i + 2], col));
            i++;
        }
        else if (pairs.size() - i <= 2)
        {
            break;
        }
    }

    return triangles;
}

raytracer::Point3 raytracer::Bezier::find_point_on_slope(double t) const {
    if (t > 1 || t < 0)
        throw std::runtime_error("t must be between 0 and 1");
    return p1 * pow(1 - t, 3)
            + pc1 * 3 * t * pow(1 - t, 2)
            + pc2 * 3 * t * t * (1 - t)
            + p2 * pow(t, 3);
}

raytracer::Vector3 raytracer::Bezier::derivative_at_point(double t) const {
    auto v = Vector3();

    Point3 derivative = p1 * -3 * pow(1 - t, 2)
                    + pc1 * 3 * (pow(1 - t, 2) - 2 * (t - t * t))
                    + pc2 * 3 * (2 * t - 3 * t * t)
                    + p2 * 3 * pow(t, 2);

    return Vector3(Point3(0, 0, 0), derivative);
}

std::vector<raytracer::Sphere *> raytracer::Bezier::control_points() const {
    auto spheres = std::vector<Sphere*>();
    spheres.push_back(new Sphere(0.005, pc1, Color(255, 0, 0)));
    spheres.push_back(new Sphere(0.005, pc2, Color(255, 0, 0)));
    return spheres;
}

raytracer::Bezier::Bezier()
:   p1(Point3(true)),
    p2(Point3(true)),
    pc1(Point3(true)),
    pc2(Point3(true))
{

}




