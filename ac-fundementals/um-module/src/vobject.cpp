#include "vobject.hpp"
#include <iostream>

void Shape::draw() const {
    std::cout << "Shape Draw" << std::endl;
}

void Shape::printInfo() const {
    std::cout << "Shape Info: Area = " << area() << std::endl;
}

double Circle::area() const {
    return 3.14 * radius * radius;
}

void Circle::draw() const {
    std::cout << "Circle Draw - Radius: " << radius << std::endl;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    radius = r;
}

Circle* g_circle = new Circle(5.0);