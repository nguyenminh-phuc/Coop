#include <iostream>
#include <memory>
#include "shapes.hpp"

static void try_stack() {
    const Triangle triangle(1, 2);
    triangle.get_type();
}

static void try_heap() {
    const std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(1, 2);
    rectangle->get_area();
}

int main() {
    try_stack();
    std::cout << std::endl;
    try_heap();

    return 0;
}
