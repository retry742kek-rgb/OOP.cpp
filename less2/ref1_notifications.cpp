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
        cout << "Sending EMAIL: " << message << endl;
    }
};

// Конкретная реализация: SMS уведомление
class SMSNotifier : public INotifier {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

// Класс, который рассылает уведомления всем добавленным уведомителям
class NotificationSender {
    vector<INotifier*> notifiers; // хранит указатели на уведомителей
public:
    // Метод добавляет новый объект уведомления в список (смс, емаил...)
    void addNotifier(INotifier* notifier) { // указатель на объект базового класса
        notifiers.push_back(notifier);
    }

    // Метод отправляет сообщение всем объектам из notifiers
    void notifyAll(const string& message) {
        for (auto notifier : notifiers)
            notifier->send(message); // вызываем метод send конкретного уведомителя
    }
};

int main() {
    // 1. Создаём рассыльщик уведомлений
    NotificationSender sender;

    // 2. Создаём конкретные уведомители (Email и SMS)
    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier;

    // 3. Добавляем их в рассыльщик
    // Метод addNotifier принимает указатель на базовый класс INotifier
    sender.addNotifier(&emailNotifier);
    sender.addNotifier(&smsNotifier);

    // 4. Отправляем сообщение всем уведомителям
    // Метод notifyAll принимает строку с текстом сообщения
    sender.notifyAll("Система обновлена!");

    return 0;
}
