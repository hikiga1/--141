#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Функция для безопасного ввода числа
double getValidNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail()) {
            cout << "Ошибка ввода! Пожалуйста, введите число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

// Функция для получения значения (исправленная версия)
double getValue() {
    double radius = 0.0; // Инициализация переменной

    radius = getValidNumber("Введите радиус: ");
    return radius;
}

int main() {
    cout << "Программа вычисляет среднее арифметическое кубов двух чисел и среднее геометрическое их модулей.\n";
    
    // Ввод двух чисел с проверкой
    double num1 = getValidNumber("Введите первое число: ");
    double num2 = getValidNumber("Введите второе число: ");
    
    // Вычисление среднего арифметического кубов
    double cube1 = pow(num1, 3);
    double cube2 = pow(num2, 3);
    double arithmeticMean = (cube1 + cube2) / 2;
    
    // Вычисление среднего геометрического модулей
    double abs1 = abs(num1);
    double abs2 = abs(num2);
    double geometricMean = sqrt(abs1 * abs2);
    
    // Вывод результатов
    cout << "\nРезультаты вычислений:\n";
    cout << "Среднее арифметическое кубов: (" << cube1 << " + " << cube2 << ") / 2 = " << arithmeticMean << endl;
    cout << "Среднее геометрическое модулей: sqrt(" << abs1 << " * " << abs2 << ") = " << geometricMean << endl;
    
    return 0;
}