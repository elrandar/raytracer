//
// Created by alexandre on 25/02/2021.
//
#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <cstdint>
#include <ostream>
/*
 * A simple color class containing information about a RGB encoding of a color.
 * Also contains the Alpha channel.
 */
namespace raytracer {
    class Color {
    public:
        uint8_t m_R;
        uint8_t m_G;
        uint8_t m_B;
        uint8_t m_A;

        Color();
        Color(uint8_t R, uint8_t G, uint8_t B);
        Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A);

        bool operator==(const Color& other) const;
        Color operator*(const double &nb) const;
    };

    std::ostream& operator<<(std::ostream& out, const Color &c);
}


#endif //RAYTRACER_COLOR_H
