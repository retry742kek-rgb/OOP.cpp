#include <iostream>
#include <vector>
using namespace std;

// Интерфейс уведомителя
class INotifier {
public:
    virtual void send(const string& message) = 0; // метод для отправки уведомления
    virtual ~INotifier() = default; // виртуальный деструктор для корректного удаления
};

// Конкретная реализация: Email уведомление
class EmailNotifier : public INotifier {
public:
    void send(const string& message) override {
        cout << "EMAIL: " << message << endl;
    }
};

// Конкретная реализация: SMS уведомление
class SMSNotifier : public INotifier {
public:
    void send(const string& message) override {
        cout << "SMS: " << message << endl;
    }
};

// Новый класс: Push уведомление
class PushNotifier : public INotifier {
public:
    void send(const string& message) override {
        cout << "PUSH: " << message << endl;
    }
};

// Класс, который рассылает уведомления всем добавленным уведомителям
class NotificationSender {
    vector<INotifier*> notifiers; // хранит указатели на уведомителей
public:
    void addNotifier(INotifier* notifier) { // добавление нового уведомителя
        notifiers.push_back(notifier);
    }

    void notifyAll(const string& message) {
        for (auto notifier : notifiers)
            notifier->send(message); // вызываем метод send конкретного уведомителя
    }
};

int main() {
    NotificationSender sender;

    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier;
    PushNotifier pushNotifier; // новый тип уведомления

    // Добавляем все уведомители в рассыльщик
    sender.addNotifier(&emailNotifier);
    sender.addNotifier(&smsNotifier);
    sender.addNotifier(&pushNotifier); // добавление без изменения NotificationSender

    // Отправляем сообщение всем уведомителям
    sender.notifyAll("Система обновлена!");

    return 0;
}
