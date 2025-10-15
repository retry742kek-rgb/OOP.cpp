#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Животное ест" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Собака лает" << endl;
    }
};

int main() {
    Dog d;
    d.eat();  // метод родителя
    d.bark(); // метод потомка
}
