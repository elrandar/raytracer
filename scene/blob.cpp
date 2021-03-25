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
    corner = Point3(1.5, 0, -0.25);
    potential = 8;
}

double raytracer::Blob::find_potential(int x, int y) {
    double pt_potential = 0;
    Point3 point_evaluated = corner + Point3(e / 2, y * d, x * d);
    for (auto point : potential_points)
    {
        pt_potential += 1 / Vector3(point, point_evaluated).norm();
    }
    return std::abs(pt_potential);
}

std::vector<raytracer::Triangle*> raytracer::Blob::marching_cubes() {
    auto triangles = std::vector<Triangle*>();

    auto x_center = e / 2;
    for (int x = 0; x < nb_discretisation; x++)
    {
        for (int y = 0; y < nb_discretisation; y++)
        {
            auto down_left = find_potential(x, y);
            auto down_right = find_potential(x + 1, y);
            auto up_left = find_potential(x,y + 1);
            auto up_right = find_potential(x + 1, y + 1);
            int index = 0;

            auto pt_dl = corner + Point3(x_center, y * d, x * d);
            auto pt_dr = corner + Point3(x_center, (y) * d, (x + 1) * d);
            auto pt_ul = corner + Point3(x_center, (y + 1) * d, (x) * d);
            auto pt_ur = corner + Point3(x_center, (y + 1) * d, (x + 1) * d);
            auto pt_dm = corner + Point3(x_center, y * d, (x + 0.5) * d);
            auto pt_lm = corner + Point3(x_center, (y + 0.5) * d, x * d);
            auto pt_um = corner + Point3(x_center, (y + 1) * d, (x + 0.5) * d);
            auto pt_rm = corner + Point3(x_center, (y + 0.5) * d, (x + 1) * d);

            auto dlp = down_left > potential;
            auto drp = down_right > potential;
            auto ulp = up_left > potential;
            auto urp = up_right > potential;

            if (dlp && !drp && !ulp && !urp)
            {
                auto col = Color(0, 255, 255);
                triangles.push_back(new Triangle(pt_dl, pt_dm, pt_lm, col));
            }
            else if (dlp && drp && !ulp && !urp)
            {
                auto col = Color(0, 0, 255);
                triangles.push_back(new Triangle(pt_dl, pt_dr, pt_lm, col));
                triangles.push_back(new Triangle(pt_dr, pt_lm, pt_rm, col));
            }
            else if (dlp && drp && ulp && !urp)
            {
                auto col = Color(255, 255, 0);
                triangles.push_back(new Triangle(pt_dl, pt_ul, pt_um, col));
                triangles.push_back(new Triangle(pt_dl, pt_um, pt_rm, col));
                triangles.push_back(new Triangle(pt_dr, pt_rm, pt_dl, col));
            }
            else if (dlp && drp && ulp && urp)
            {
                auto col = Color(0, 255, 0);
                triangles.push_back(new Triangle(pt_dl, pt_ul, pt_dr, col));
                triangles.push_back(new Triangle(pt_ur, pt_ul, pt_dr, col));
            }
            else if (!dlp && drp && !ulp && !urp)
            {
                auto col = Color(0, 255, 255);
                triangles.push_back(new Triangle(pt_dm, pt_dr, pt_rm, col));
            }
            else if (!dlp && drp && ulp && urp)
            {
                auto col = Color(255, 255, 0);
                triangles.push_back(new Triangle(pt_ur, pt_ul, pt_lm, col));
                triangles.push_back(new Triangle(pt_ur, pt_lm, pt_dm, col));
                triangles.push_back(new Triangle(pt_dm, pt_dr, pt_ur, col));
            }
            else if (!dlp && !drp && ulp && !urp)
            {
                auto col = Color(0, 255, 255);
                triangles.push_back(new Triangle(pt_ul, pt_um, pt_lm, col));
            }
            else if (!dlp && !drp && !ulp && urp)
            {
                auto col = Color(0, 255, 255);
                triangles.push_back(new Triangle(pt_ur, pt_um, pt_rm, col));
            }
            else if (dlp && !drp && ulp && urp)
            {
                auto col = Color(255, 255, 0);
                triangles.push_back(new Triangle(pt_ur, pt_ul, pt_rm, col));
                triangles.push_back(new Triangle(pt_ul, pt_rm, pt_dm, col));
                triangles.push_back(new Triangle(pt_dm, pt_dl, pt_ul, col));
            }
            else if (dlp && drp && !ulp && urp)
            {
                auto col = Color(255, 255, 0);
                triangles.push_back(new Triangle(pt_um, pt_dr, pt_ur, col));
                triangles.push_back(new Triangle(pt_dr, pt_um, pt_lm, col));
                triangles.push_back(new Triangle(pt_lm, pt_dl, pt_dr, col));
            }
            else if (!dlp && !drp && ulp && urp)
            {
                auto col = Color(0, 0, 255);
                triangles.push_back(new Triangle(pt_ul, pt_ur, pt_lm, col));
                triangles.push_back(new Triangle(pt_ur, pt_lm, pt_rm, col));
            }
            else if (dlp && !drp && ulp && !urp)
            {
                auto col = Color(0, 0, 255);
                triangles.push_back(new Triangle(pt_dl, pt_ul, pt_um, col));
                triangles.push_back(new Triangle(pt_dl, pt_um, pt_dm, col));
            }
            else if (!dlp && drp && !ulp && urp)
            {
                auto col = Color(0, 0, 255);
                triangles.push_back(new Triangle(pt_dr, pt_ur, pt_um, col));
                triangles.push_back(new Triangle(pt_dr, pt_um, pt_dm, col));
            }
        }
    }
    return triangles;
}

