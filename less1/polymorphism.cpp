#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Животное издает звук" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Собака лает" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Кошка мяукает" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); // Собака лает
    a2->speak(); // Кошка мяукает

    delete a1;
    delete a2;
}
