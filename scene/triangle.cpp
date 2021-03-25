//
// Created by alexandre on 15/03/2021.
//

#include "triangle.h"
#include "plane.h"
#include "uniform_texture.h"
using namespace raytracer;

double signed_volume(Point3 a, Point3 b, Point3 c, Point3 d)
{
    double dot = (Vector3(a, b) ^ Vector3(a, c)) * (Vector3(a, d));
    return 1.0/6.0 * dot;
}

int get_sign(double val)
{
    return (val > 0) ? 1 : ((val < 0) ? -1 : 0);
}

raytracer::TextureInfo raytracer::Triangle::get_texture_info(double x, double y) {
    return mat->get_info(x, y);
}

raytracer::Triangle::Triangle(Point3 a, Point3 b, Point3 c)
    :   a(a),
        b(b),
        c(c)
    {
    mat = std::make_unique<UniformTexture>(1,1,Color(255, 0, 0));
}

Vector3 raytracer::Triangle::get_normal(Point3 point, Vector3 in_vec) {
    Vector3 n = (Vector3(a, b) ^ Vector3(b, c));
    if (n * in_vec > 0)
        n = n * -1;
    return n;
}

raytracer::Point3 raytracer::Triangle::find_intersection(raytracer::Ray3 ray) {
    Point3 q1 = ray.point - ray.vector * 1000;
    Point3 q2 = ray.point + ray.vector * 1000;

    auto s1 = signed_volume(q1, a, b, c);
    auto s2 = signed_volume(q2, a, b, c);
    auto s3 = signed_volume(q1, q2, a, b);
    auto s4 = signed_volume(q1, q2, b, c);
    auto s5 = signed_volume(q1, q2, c, a);

    bool intersection = false;
    if (get_sign(s1) != get_sign(s2) && get_sign(s3) == get_sign(s4) && get_sign(s4) == get_sign(s5))
        intersection = true;

    if (!intersection)
        return Point3(true);

    auto plane = Plane(get_normal(a, Vector3()), a);

    return plane.find_intersection(ray);
}

Triangle::Triangle(Point3 a, Point3 b, Point3 c, Color col) : Triangle(a, b, c){
    mat = std::make_unique<UniformTexture>(1,1,col);
}
