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

std::ostream &raytracer::operator<<(std::ostream &out, const raytracer::Color &c) {
    return out << "Vector3 {R=" << c.m_R << ", G=" << c.m_G << ", B=" << c.m_B << "}";
}
