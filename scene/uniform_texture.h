//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_UNIFORM_TEXTURE_H
#define RAYTRACER_UNIFORM_TEXTURE_H


#include "texture_material.h"
#include "../utils/color.h"

namespace raytracer {
    class UniformTexture : public TextureMaterial {

        float m_kd;
        float m_ks;
        Color m_color;

        TextureInfo get_info(float x, float y);
    };
}

#endif //RAYTRACER_UNIFORM_TEXTURE_H
