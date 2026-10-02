#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#pragma execution_character_set("utf-8")
using namespace std;


// Игра "Угадай число" 
void Game() {
    srand(time(0));
    int secret = rand() % 101; // от 0 до 100
    int guess;
    int attempts = 0;

    cout << "\n Игра 'Угадай число' \n";
    cout << "Я загадал число от 0 до 100. Попробуй угадать!\n";

    while (true) {
        cout << "Введи число: ";
        cin >> guess;
        attempts++;

        if (guess == secret) {
            cout << "Победа! Ты угадал число " << secret
                << " за " << attempts << " попыток.\n";
            break;
        }
        else if (guess < secret) {
            cout << "Загаданное число больше.\n";
        }
        else {
            cout << "Загаданное число меньше.\n";
        }
    }
}

//  Таблица умножения 
void Table() {
    const int N = 10;
    int table[N][N];

    // Заполняем матрицу с помощью циклов
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    // Вывод таблицы
    cout << "\n Таблица умножения \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout.width(5);
            cout << table[i][j];
        }
        cout << "\n";
    }
}

//  Вывод делителей числа 
void Divisors() {
    int number;
    cout << "\nВывод делителей числа \n";
    cout << "Введи число: ";
    cin >> number;

    if (number == 0) {
        cout << "Любое число делит 0. Введите ненулевое число.\n";
        return;
    }

    // Работаем с модулем для отрицательных чисел
    int absNum = (number < 0) ? -number : number;

    cout << "Делители числа " << number << ": ";
    for (int i = 1; i <= absNum; i++) {
        if (absNum % i == 0) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

//  Меню 
int main() {
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF - 8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF - 8


    int choice;
    do {
        cout << "\n МЕНЮ \n";
        cout << "1. Игра 'Угадай число'\n";
        cout << "2. Таблица умножения\n";
        cout << "3. Вывод делителей числа\n";
        cout << "0. Выход\n";
        cout << "Выбери пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: Game(); break;
        case 2: Table(); break;
        case 3: Divisors(); break;
        case 0: cout << "Пока!\n"; break;
        default: cout << "Неверный пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}
    