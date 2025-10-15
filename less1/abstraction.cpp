#include <iostream>
using namespace std;

// Абстрактный класс
class Shape {
public:
    virtual double area() const = 0;  // чисто виртуальные функции
    virtual void draw() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
    void draw() const override { cout << "Рисуем круг" << endl; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() const override { return w * h; }
    void draw() const override { cout << "Рисуем прямоугольник" << endl; }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);

    s1->draw();
    cout << "Площадь: " << s1->area() << endl;

    s2->draw();
    cout << "Площадь: " << s2->area() << endl;

    delete s1;
    delete s2;
}
