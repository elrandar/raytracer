//
// Created by alexandre on 25/02/2021.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <vector>
#include "color.h"
namespace raytracer {

    class Image {
    public:

        int m_width;
        int m_height;
        std::vector<Color> m_pix_array;

        Image(int width, int height);

        void fill_white();
        std::string to_PPM();
    };

}

#endif //RAYTRACER_IMAGE_H
