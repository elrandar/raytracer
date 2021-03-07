//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_UNIFORM_TEXTURE_H
#define RAYTRACER_UNIFORM_TEXTURE_H


#include "texture_material.h"
#include "../utils/color.h"

namespace raytracer {
    class UniformTexture : public TextureMaterial {

        double m_kd;
        double m_ks;
        Color m_color;

        TextureInfo get_info(double x, double y);

    public:
        UniformTexture(double kd, double ks, Color color);
    };
}

#endif //RAYTRACER_UNIFORM_TEXTURE_H
