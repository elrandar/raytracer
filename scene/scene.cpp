//
// Created by alexandre on 25/02/2021.
//

#include "scene.h"
#include "cmath"
#include "point_light.h"

raytracer::Image raytracer::Scene::generate_image(int nb_cols, int nb_rows) {
    auto im = Image(nb_cols, nb_rows);
    im.fill_black();

    auto img_width = 2 * camera.z_min * tan(camera.beta / 2);
    auto img_height = 2 * camera.z_min * tan(camera.alpha / 2);
    auto step_w = img_width / nb_cols;
    auto step_h = img_height / nb_rows;
    
    auto p = Vector3(camera.center, camera.p);
    auto y_a_scaled = camera.up / camera.up.norm() * step_h;
    auto x_a_scaled = (camera.up / camera.up.norm() ^ (p / p.norm())) * step_w;

    Vector3 shift_x = x_a_scaled * ((double) nb_cols / 2 - 0.5);
    Vector3 shift_y = y_a_scaled * ((double) nb_rows / 2 - 0.5);
    Point3 top_left = (camera.p / p.norm()) + shift_x.to_point() + shift_y.to_point();

    for (int x = 0; x < nb_cols; x++)
    {
        for (int y = 0; y < nb_rows; y++)
        {
            auto ray = Ray3(camera.center,
                            Vector3(camera.center,
                                    top_left - (x_a_scaled * x).to_point()
                                    - (y_a_scaled * y).to_point()));
            auto color = cast_ray(ray);
            im.set_pixel(x, y, color);
        }
    }
    return im;
}

raytracer::Color raytracer::Scene::cast_ray(Ray3 ray) {
    auto p = Vector3(camera.center, camera.p);
    Object* best_point_obj;
    auto best_point = Point3(true);
    double best_point_distance = -1;
    for (auto object : objects)
    {
        Point3 intersection_point = object->find_intersection(ray);

        if (p * Vector3(camera.center, intersection_point) < 0)
        {
            intersection_point.m_is_none = true;
        }
        if (!intersection_point.m_is_none) {
            auto point_distance = Vector3(camera.center, intersection_point).norm();
            if (best_point_distance == -1 || point_distance < best_point_distance) {
                best_point_obj = object;
                best_point_distance = point_distance;
                best_point = intersection_point;
            }
        }
    }
    if (best_point_distance != -1) {
        auto i = Color(0, 0, 0);
        for (auto light : lights)
        {
            auto L = Vector3(best_point, light->position);


            if (is_blocked(Ray3(best_point, L), best_point_obj))
                continue;
            L = L / L.norm();
            auto texture_info = best_point_obj->get_texture_info(0, 0);
            auto norm = best_point_obj->get_normal(best_point, Vector3(camera.center, best_point));
            auto d = Vector3(camera.center, best_point);
            d = d / d.norm();
            norm = norm / norm.norm();
            Vector3 r = d - norm * (d * norm) * 2;
            auto sc = norm * L;
            if (sc < 0)
                sc = 0;
            auto id = texture_info.k_d * sc * light->intensity;
            auto dot_reflected = r * L;
            if (dot_reflected < 0)
                dot_reflected = 0;
            auto is = texture_info.k_s * light->intensity * (dot_reflected);
            auto ns = 1.3;

            auto color = texture_info.m_color * id + Color(255, 255, 255) * pow(is, ns);

            i = i + color;
        }
        auto fd = 1 / sqrt(best_point_distance);
        return i * fd;
    }
    return Color(0,0,0);
}

bool raytracer::Scene::is_blocked(Ray3 ray, Object *pObject) {

    auto point_distance = ray.vector.norm();
    for (auto object : objects)
    {
        Point3 intersection_point = object->find_intersection(ray);

        Vector3 intersection_vector = Vector3(ray.point, intersection_point);
        if (intersection_vector * ray.vector < 0 || intersection_vector.norm() > point_distance)
            intersection_point.m_is_none = true;
        if (!intersection_point.m_is_none && object != pObject) {
            return true;
        }
    }
    return false;
}
