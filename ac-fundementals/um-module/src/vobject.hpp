#pragma once

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const;
    void printInfo() const;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    
    double area() const override;
    void draw() const override;
    double getRadius() const;
    void setRadius(double r);
};

extern Circle* g_circle;