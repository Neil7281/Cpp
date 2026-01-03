#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;   // pure virtual
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) {
        r = radius;
    }

    double area() const override {
        const double pi = 3.14;
        return pi * r * r;
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height){
        w= width;
        h = height;
    }

    double area() const override {
        return w * h;
    }
};


void printArea(const Shape& s) {
    cout << "Area = " << s.area() << "\n";
}

int main() {
    Circle c(5.0);
    Rectangle r(4.0, 3.0);

    printArea(c);   // polymorphism 
    printArea(r);  

    return 0;
}
