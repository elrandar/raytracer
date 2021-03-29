//
// Created by alexandre on 29/03/2021.
//

#include "grass_blade.h"

raytracer::GrassBlade::GrassBlade(const raytracer::Point3 &basePoint, double height, double offset, double width,
                                  const raytracer::Vector3 &normalVec)
        : base_point(basePoint), height(height), offset(offset), width(width), normal_vec(normalVec){
    bezier_curve = Bezier(basePoint,
                          basePoint + Point3(0, height, offset),
                          basePoint + Point3(0, height / 3, 0),
                          basePoint + Point3(0, height * 2 / 3, 0));
}

raytracer::GrassBlade::GrassBlade(const raytracer::Point3 &basePoint, double height)
 : base_point(basePoint),
   height(height)
{
    offset = 0;
    width = height / 16;
    normal_vec = Vector3(1, 0, 0);
    bezier_curve = Bezier(basePoint, basePoint + Point3(0, height, offset),
           basePoint + Point3(0, height / 3, 0), basePoint + Point3(0, height * 2 / 3, 0));
}

std::vector<raytracer::Triangle *> raytracer::GrassBlade::generate_triangles() const {
    auto triangles = std::vector<raytracer::Triangle*>();

    std::vector<Point3> pairs = std::vector<Point3>();

//    auto step = Vector3(bezier_curve.p1, bezier_curve.p2).norm() / 1.3;
    auto step = 0.25;
    double t = 0;
    while (t <= 1)
    {
        auto point = bezier_curve.find_point_on_slope(t);
        auto derivative = bezier_curve.derivative_at_point(t);
        auto normal = derivative ^ normal_vec;
        normal = normal / normal.norm();

        auto point1 = point + normal * (width - 0.5 * width * t);
        auto point2 = point - normal * (width - 0.5 * width * t);


        pairs.push_back(point1);
        pairs.push_back(point2);
        t += step;
    }

    pairs.pop_back();
    pairs.pop_back();
    pairs.push_back(bezier_curve.find_point_on_slope(1));

    int i = 0;
    while (i < pairs.size())
    {
        if (pairs.size() - i >= 3)
        {
            auto col = Color(255, 0, 255);
            if (i % 2 == 0)
                col = Color(0, 255, 255);
            col = Color(13, 148, 101);
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
