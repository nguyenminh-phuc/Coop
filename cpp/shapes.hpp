#ifndef COOP_SHAPES_HPP
#define COOP_SHAPES_HPP

#include <iostream>

class Shape {
public:
    Shape(int a, int b) : a{a}, b{b} {
        std::cout << "Shape::Shape" << std::endl;
        // Call to pure virtual member function 'get_area' has undefined behavior
        // try_call_get_area();
    }

    virtual ~Shape() {
        std::cout << "Shape::~Shape" << std::endl;
    };

    void try_call_get_area() const {
        get_area();
    }

    virtual const char *get_type() const {
        std::cout << "Shape::get_type" << std::endl;
        return "shape";
    }

    virtual int get_area() const = 0;

    int a;
    int b;
};

class Rectangle final : public Shape {
public:
    Rectangle(int a, int b) : Shape(a, b) {
        std::cout << "Rectangle::Rectangle" << std::endl;
    }

    ~Rectangle() final {
        std::cout << "Rectangle::~Rectangle" << std::endl;
    }

    const char *get_type() const final {
        std::cout << "Rectangle::get_type" << std::endl;
        return "rectangle";
    }

    int get_area() const final {
        std::cout << "Rectangle::get_area" << std::endl;
        return a * b;
    }
};

class Triangle final : public Shape {
public:
    Triangle(int a, int b) : Shape(a, b) {
        std::cout << "Triangle::Triangle" << std::endl;
    }

    ~Triangle() final {
        std::cout << "Triangle::~Triangle" << std::endl;
    }

    const char *get_type() const final {
        std::cout << "Triangle::get_type" << std::endl;
        return "triangle";
    }

    int get_area() const final {
        std::cout << "Triangle::get_area" << std::endl;
        return (a * b) / 2;
    }
};

#endif
