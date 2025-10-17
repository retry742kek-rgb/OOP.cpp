#include <QApplication>   // Qt класс для управления приложением
#include <QWidget>        // Базовый класс всех GUI-окон
#include <QPushButton>    // Кнопка Qt
#include <QVBoxLayout>    // Вертикальный менеджер компоновки Qt
#include <QLineEdit>      // Однострочное текстовое поле Qt
#include <QTextEdit>      // Многострочное текстовое поле Qt
#include <vector>
#include <iostream>
using namespace std;

// Интерфейс уведомителя
class INotifier {
public:
    virtual void send(const string& message) = 0;
    virtual ~INotifier() = default;
};

// Email уведомление
class EmailNotifier : public INotifier {
public:
    void send(const string& message) override {
        cout << "Sending EMAIL: " << message << endl;
    }
};

// SMS уведомление
class SMSNotifier : public INotifier {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

// Класс рассыльщика уведомлений
class NotificationSender {
    vector<INotifier*> notifiers;
public:
    void addNotifier(INotifier* notifier) {
        notifiers.push_back(notifier);
    }

    // Использование QTextEdit из Qt для вывода логов в GUI
    void notifyAll(const string& message, QTextEdit* logWidget = nullptr) {
        for (auto notifier : notifiers) {
            notifier->send(message);
            if (logWidget)
                // append() и QString — классы Qt
                logWidget->append(QString::fromStdString("Sent: " + message));
        }
    }
};

// Главное окно GUI
// Наследование от QWidget — базового элемента интерфейса Qt
class MainWindow : public QWidget {
public:
    MainWindow() {
        // QVBoxLayout — Qt менеджер компоновки (вертикально)
        auto layout = new QVBoxLayout(this);

        // QLineEdit — поле ввода Qt
        input = new QLineEdit(this);
        input->setPlaceholderText("Введите сообщение...");
        layout->addWidget(input); // Добавление в layout через метод Qt

        // QPushButton — кнопка Qt
        sendButton = new QPushButton("Отправить уведомление", this);
        layout->addWidget(sendButton);

        // QTextEdit — многострочный текстовый виджет для логов Qt
        log = new QTextEdit(this);
        log->setReadOnly(true);
        layout->addWidget(log);

        // Настраиваем уведомителей
        sender.addNotifier(&emailNotifier);
        sender.addNotifier(&smsNotifier);

        // Использование системы сигналов и слотов Qt
        // connect() связывает событие нажатия кнопки с методом класса
        connect(sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);
    }

private:
    // Указатели на виджеты Qt
    QLineEdit* input;
    QPushButton* sendButton;
    QTextEdit* log;

    NotificationSender sender;
    EmailNotifier emailNotifier;
    SMSNotifier smsNotifier;

    // Метод Qt-слот, вызываемый при нажатии кнопки
    void sendMessage() {
        // QString — тип строки Qt
        QString msg = input->text();
        if (!msg.isEmpty()) {
            // Конвертация QString → std::string через метод Qt
            sender.notifyAll(msg.toStdString(), log);
            input->clear(); // Очистка поля ввода через метод Qt
        }
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv); // QApplication — главный объект Qt-приложения

    MainWindow window; // Экземпляр главного окна Qt
    window.setWindowTitle("Notifier GUI"); // Метод Qt для заголовка окна
    window.resize(400, 300); // Метод Qt для изменения размера окна
    window.show(); // Показ окна Qt

    return app.exec(); // Запуск основного цикла событий Qt
}
