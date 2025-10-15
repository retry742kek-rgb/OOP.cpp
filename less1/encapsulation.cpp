#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance; // закрытое поле, нельзя менять напрямую

public:
    BankAccount(double initial) {
        balance = initial;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);
    acc.deposit(500);
    acc.withdraw(200);
    cout << "Баланс: " << acc.getBalance() << endl;
}
