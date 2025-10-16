#include <iostream>
using namespace std;

class Notification {
public:
    void send(string message, string type) {
        if (type == "email") {
            cout << "Sending EMAIL: " << message << endl;
        } 
        else if (type == "sms") {
            cout << "Sending SMS: " << message << endl;
        } 
        else if (type == "push") {
            cout << "Sending PUSH: " << message << endl;
        } 
        else {
            cout << "Unknown notification type!" << endl;
        }
    }
};

int main() {
    Notification n;
    n.send("Hello!", "email");
    n.send("Hi!", "sms");
    n.send("Hey!", "push");
}
