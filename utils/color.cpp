//
// Created by alexandre on 25/02/2021.
//

#include "color.h"

raytracer::Color::Color(uint8_t R, uint8_t G, uint8_t B) {
    m_R = R;
    m_G = G;
    m_B = B;
    m_A = 0;
}

raytracer::Color::Color()
    : m_R(0), m_G(0), m_B(0), m_A(0)
{}

raytracer::Color::Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A) : Color(R, G, B) {
    m_A = A;
}

bool raytracer::Color::operator==(const raytracer::Color &other) const {
    return other.m_R == m_R && other.m_B == m_B && other.m_G == m_G;
}

raytracer::Color raytracer::Color::operator*(const double &nb) const {
    auto r = m_R * nb;
    auto g = m_G * nb;
    auto b = m_B * nb;

    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    return raytracer::Color(r, g, b);
}

void raytracer::Color::clamp() {
    if (m_R > 255)
        m_R = 255;
    if (m_G > 255)
        *this = *this - Color(1, 1, 1) * m_G;
    if (m_B > 255)
        *this = *this - Color(1, 1, 1) * m_B;
}

raytracer::Color raytracer::Color::operator+(const raytracer::Color &color) const {
    auto r = m_R + color.m_R;
    auto g = m_G + color.m_G;
    auto b = m_B + color.m_B;
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    return raytracer::Color(r, g, b);
}

raytracer::Color raytracer::Color::operator-(const raytracer::Color &color) const {
    auto r = m_R - color.m_R;
    auto g = m_G - color.m_G;
    auto b = m_B - color.m_B;
    if (r < 0)
        r = 0;
    if (g < 0)
        g = 0;
    if (b < 0)
        b = 0;
    return raytracer::Color(r, g, b);
}

std::ostream &raytracer::operator<<(std::ostream &out, const raytracer::Color &c) {
    return out << "Vector3 {R=" << c.m_R << ", G=" << c.m_G << ", B=" << c.m_B << "}";
}
