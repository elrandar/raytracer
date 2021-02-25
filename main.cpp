#include <iostream>
#include "vector3.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto v = raytracer::Vector3(45, 68, -32);
    std::cout << v;
    return 0;
}
