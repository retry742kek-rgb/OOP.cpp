#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    // Конструктор
    Book(const std::string& title, const std::string& author, int year)
        : title(title), author(author), year(year) {}

    // Метод для отображения информации о книге
    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }

    // Метод для получения названия книги
    std::string getTitle() const {
        return title;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    // Метод для добавления книги
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Метод для удаления книги по названию
    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                return;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }

    // Метод для отображения всех книг
    void displayBooks() const { //  метод не будет изменять объект класса, на котором вызывается.
        if (books.empty()) {
            std::cout << "No books in the library." << std::endl;
            return;
        }
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;

    // Добавление книг
    library.addBook(Book("1984", "George Orwell", 1949));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));

    // Отображение всех книг
    std::cout << "Books in the library:" << std::endl;
    library.displayBooks();

    // Удаление книги
    library.removeBook("1984");

    // Отображение всех книг после удаления
    std::cout << "Books in the library after removal:" << std::endl;
    library.displayBooks();

    return 0;
}