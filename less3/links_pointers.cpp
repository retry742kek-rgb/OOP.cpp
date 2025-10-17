#include <iostream>
using namespace std;

/*
    ======================================
           ТЕМА: ССЫЛКИ И УКАЗАТЕЛИ
    ======================================
*/

// 1 Передача по значению (копия)
void changeValue(int x) {
    x = 100; // изменяем копию
}

// 2 Передача по ссылке (оригинал)
void changeByReference(int &x) {
    x = 200; // изменяем оригинал
}

// 3 Передача по указателю (оригинал через адрес)
void changeByPointer(int *x) {
    *x = 300; // изменяем значение по адресу
}

// 4 Функция для обмена значениями через указатели
void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 5 Функции для прибавления
void addByReference(int &a) { a += 10; }
void addByPointer(int *a) { *a += 10; }

int main() {
    cout << "===== 1. Передача по значению =====" << endl;
    int a = 10;
    changeValue(a);
    cout << "a после changeValue: " << a << endl; // 10

    cout << "\n===== 2. Передача по ссылке =====" << endl;
    changeByReference(a);
    cout << "a после changeByReference: " << a << endl; // 200

    cout << "\n===== 3. Передача по указателю =====" << endl;
    changeByPointer(&a);
    cout << "a после changeByPointer: " << a << endl; // 300

    cout << "\n===== 4. Работа со ссылками =====" << endl;
    int x = 5;
    int &ref = x; // ref — ссылка на x
    cout << "До: x = " << x << ", ref = " << ref << endl;
    ref = 20;
    cout << "После: x = " << x << ", ref = " << ref << endl;

    cout << "\n===== 5. Работа с указателями =====" << endl;
    int y = 7;
    int *p = &y;
    cout << "Адрес y: " << p << ", значение по адресу: " << *p << endl;
    *p = 15;
    cout << "После изменения через указатель: y = " << y << endl;

    cout << "\n===== 6. Передача по ссылке и по указателю =====" << endl;
    int n1 = 5, n2 = 5;
    addByReference(n1);
    addByPointer(&n2);
    cout << "addByReference: " << n1 << endl;
    cout << "addByPointer: " << n2 << endl;

    cout << "\n===== 7. Функция swapValues (через указатели) =====" << endl;
    int m = 10, n = 20;
    cout << "До swap: m = " << m << ", n = " << n << endl;
    swapValues(&m, &n);
    cout << "После swap: m = " << m << ", n = " << n << endl;

    cout << "\n===== 8. Массивы и указатели =====" << endl;
    int arr[3] = {1, 2, 3};
    int *ptr = arr; // указатель на первый элемент массива
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << *(ptr + i) << endl;
    }

    cout << "\n===== 9. Динамическая память =====" << endl;
    int *dyn = new int;  // выделяем память
    *dyn = 42;
    cout << "Значение в динамической памяти: " << *dyn << endl;
    delete dyn;          // освобождаем память
    dyn = nullptr;       // безопасное обнуление указателя

    cout << "\n===== 10. Шпаргалка =====" << endl;
    cout << "& — взять адрес переменной" << endl;
    cout << "* — разыменовать указатель (получить значение)" << endl;
    cout << "new/delete — выделение и освобождение памяти" << endl;
    cout << "Ссылка (int &x) — алиас переменной, не может быть пустой" << endl;
    cout << "Указатель (int *x) — хранит адрес, может быть nullptr" << endl;

    return 0;
}
