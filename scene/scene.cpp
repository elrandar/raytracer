//
// Created by alexandre on 25/02/2021.
//

#include "scene.h"
#include "cmath"
#include "point_light.h"
#include <thread>

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

    auto thread_list = std::vector<std::thread>();
    auto results_list = std::vector<std::vector<Color>*>();
    int nb_thread = 8;

    int row_step = nb_rows / nb_thread;

    for (int i = 0; i < nb_thread; i++)
    {
        int row_start = i * row_step;
        int row_end = i == nb_thread - 1 ? nb_rows : (i + 1) * row_step;
        int col_start = 0;
        int col_end = nb_cols;

        results_list.push_back(new std::vector<Color>());
        thread_list.emplace_back(&Scene::process_part, this, col_start, col_end,
                                 row_start, row_end,
                                 y_a_scaled, x_a_scaled, top_left,
                                 results_list[i]);
    }

    for (auto &t : thread_list)
    {
        t.join();
    }

    for (auto res : results_list)
    {
        for (auto col : *res)
        {
            im.set_pixel(col.x, col.y, col);
        }
    }

    return im;
}

void raytracer::Scene::process_part(int start_col, int end_col, int start_row, int end_row,
                                    const raytracer::Vector3 &y_a_scaled, const raytracer::Vector3 &x_a_scaled,
                                    const raytracer::Point3 &top_left, std::vector<Color> *vec) const {
    for (int x = start_col; x < end_col; x++)
    {
        for (int y = start_row; y < end_row; y++)
        {
            auto ray = Ray3(camera.center,
                            Vector3(camera.center,
                                    top_left - (x_a_scaled * x).to_point()
                                    - (y_a_scaled * y).to_point()));
            auto color = cast_ray(ray);
            color.x = x;
            color.y = y;
            vec->push_back(color);
        }
    }
}

raytracer::Color raytracer::Scene::cast_ray(Ray3 ray) const {
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

bool raytracer::Scene::is_blocked(Ray3 ray, Object *pObject) const {

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
