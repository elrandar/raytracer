//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_TEXTURE_MATERIAL_H
#define RAYTRACER_TEXTURE_MATERIAL_H
#include "../utils/color.h"
namespace raytracer {
    class TextureInfo {
    public:
        TextureInfo(float k_d, float k_s, Color color)
            : k_d(k_d), k_s(k_s) {
            m_color = color;
        }
        float k_d;
        float k_s;
        Color m_color;
    };

    class TextureMaterial {

    public:
        virtual TextureInfo get_info(float x, float y) = 0;
    };
}

#endif //RAYTRACER_TEXTURE_MATERIAL_H
