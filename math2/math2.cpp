#include <iostream>
#include <string>
#include "counter.h"

Counter::Counter() : value(1) {}

Counter::Counter(int initialValue) : value(initialValue) {}

void Counter::increment() {
    value++;
}

void Counter::decrement() {
    value--;
}

int Counter::getValue() const {
    return value;
}



using namespace std;

int main() {
    Counter* counter;
    string input;
    setlocale(LC_ALL, "Russian");


    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> input;

    if (input == "да") {
        int initialValue;
        cout << "Введите начальное значение счётчика: ";
        cin >> initialValue;
        counter = new Counter(initialValue);
    }
    else {
        counter = new Counter();
    }

    char command;
    while (true) {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;

        switch (command) {
        case '+':
            counter->increment();
            break;
        case '-':
            counter->decrement();
            break;
        case '=':
            cout << counter->getValue() << endl;
            break;
        case 'x':
            cout << "До свидания!" << endl;
            delete counter;
            return 0;
        default:
            cout << "Неверная команда!" << endl;
            break;
        }
    }

    delete counter;
    return 0;
}

