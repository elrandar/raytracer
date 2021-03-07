//
// Created by alexandre on 25/02/2021.
//

#include <sstream>
#include "image.h"

raytracer::Image::Image(int width, int height)
    : m_height(height),
    m_width(width),
    m_pix_array(std::vector<Color>(height * width)) {

}

std::string raytracer::Image::to_PPM() {
    std::stringstream ss;
    ss  << "P3" << '\n'
        << m_width << '\n'
        << m_height << '\n'
        << 255 << '\n';

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            auto col = m_pix_array[m_width * i + j];
            ss  << std::to_string(col.m_R) << " "
                << std::to_string(col.m_G) << " "
                << std::to_string(col.m_B) << "  ";
        }
        ss << '\n';
    }
    std::string str = ss.str();
//    auto out = std::vector<std::byte>(str.length());
//    int i = 0;
//    for (char c : str)
//    {
//        out[i] = static_cast<std::byte>(c);
//    }

    return str;
}

void raytracer::Image::fill_white() {
    for (int i = 0; i < m_height * m_width; i++)
    {
        m_pix_array[i] = Color(0, 0, 0);
    }

}

void raytracer::Image::set_pixel(int x, int y, Color col) {
    m_pix_array[m_width * y + x] = col;
}
