//
// Created by alexandre on 25/02/2021.
//

#include "uniform_texture.h"

raytracer::TextureInfo raytracer::UniformTexture::get_info(double x, double y) {
    return raytracer::TextureInfo(m_kd, m_ks, m_color);
}

raytracer::UniformTexture::UniformTexture(double kd, double ks, raytracer::Color color) : m_kd(kd), m_ks(ks), m_color(color){

}
