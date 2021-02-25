//
// Created by alexandre on 25/02/2021.
//

#include "uniform_texture.h"

raytracer::TextureInfo raytracer::UniformTexture::get_info(float x, float y) {
    return raytracer::TextureInfo(m_kd, m_ks, m_color);
}
