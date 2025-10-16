#include <iostream>
#include <vector>
using namespace std;

// ------------------ Drink ------------------
class Drink {
protected:
    string name;
    double price;
public:
    Drink(string n, double p) : name(n), price(p) {}
    virtual void prepare() = 0;
    double getPrice() { return price; }
};

class Coffee : public Drink {
public:
    Coffee() : Drink("Coffee", 3.5) {}
    void prepare() override { cout << "Preparing Coffee..." << endl; }
};

class Tea : public Drink {
public:
    Tea() : Drink("Tea", 2.5) {}
    void prepare() override { cout << "Preparing Tea..." << endl; }
};

// ------------------ Food ------------------
class Food {
protected:
    string name;
    double price;
public:
    Food(string n, double p) : name(n), price(p) {}
    virtual void prepare() = 0;
    double getPrice() { return price; }
};

class Burger : public Food {
public:
    Burger() : Food("Burger", 5.0) {}
    void prepare() override { cout << "Preparing Burger..." << endl; }
};

class Salad : public Food {
public:
    Salad() : Food("Salad", 4.0) {}
    void prepare() override { cout << "Preparing Salad..." << endl; }
};

// ------------------ Payment Strategy ------------------
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CardPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " by Card." << endl;
    }
};

class CashPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid " << amount << " in Cash." << endl;
    }
};

// ------------------ Order ------------------
class Order {
    vector<Drink*> drinks;
    vector<Food*> foods;
    PaymentStrategy* payment;
public:
    void addDrink(Drink* d) { drinks.push_back(d); }
    void addFood(Food* f) { foods.push_back(f); }
    void setPayment(PaymentStrategy* p) { payment = p; }

    void prepareOrder() {
        for (auto d : drinks) d->prepare();
        for (auto f : foods) f->prepare();
    }

    void payOrder() {
        double total = 0;
        for (auto d : drinks) total += d->getPrice();
        for (auto f : foods) total += f->getPrice();
        payment->pay(total);
    }
};

// ------------------ Customer ------------------
class Customer {
    string name;
public:
    Customer(string n) : name(n) {}
    void placeOrder(Order& order) {
        cout << name << " places order:" << endl;
        order.prepareOrder();
        order.payOrder();
    }
};

// ------------------ main ------------------
int main() {
    Customer c("Alice");
    Order order;

    order.addDrink(new Coffee());
    order.addFood(new Burger());
    order.setPayment(new CardPayment());

    c.placeOrder(order);
    return 0;
}
