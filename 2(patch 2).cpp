#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/**
 * @brief Выполняет безопасный ввод числа с клавиатуры.
 *
 * Если ввод некорректен (не число), программа завершает выполнение.
 *
 * @param prompt Сообщение, которое отображается пользователю перед вводом.
 * @return Введённое пользователем число типа double.
 */
double getValidNumber(const string& prompt) {
    double number;
    cout << prompt;
    cin >> number;

    if (cin.fail()) {
        cout << "Ошибка ввода! Завершение программы.\n";
        exit(1);
    }

    return number;
}

/**
 * @brief Вычисляет среднее арифметическое кубов двух чисел.
 *
 * Формула: (num1^3 + num2^3) / 2
 *
 * @param num1 Первое число.
 * @param num2 Второе число.
 * @return Среднее арифметическое кубов.
 */
double calculateArithmeticMeanOfCubes(double num1, double num2) {
    return (pow(num1, 3) + pow(num2, 3)) / 2.0;
}

/**
 * @brief Вычисляет среднее геометрическое модулей двух чисел.
 *
 * Формула: sqrt(|num1| * |num2|)
 *
 * @param num1 Первое число.
 * @param num2 Второе число.
 * @return Среднее геометрическое модулей.
 */
double calculateGeometricMeanOfAbs(double num1, double num2) {
    return sqrt(abs(num1) * abs(num2));
}

/**
 * @brief Главная функция программы.
 *
 * Запрашивает у пользователя два числа, вычисляет:
 * - среднее арифметическое их кубов,
 * - среднее геометрическое модулей,
 * и выводит результаты.
 *
 * @return Код завершения программы (0).
 */
int main() {
    cout << "Программа вычисляет среднее арифметическое кубов двух чисел и среднее геометрическое их модулей.\n";

    // Ввод двух чисел
    double num1 = getValidNumber("Введите первое число: ");
    double num2 = getValidNumber("Введите второе число: ");

    // Вычисления
    double arithmeticMean = calculateArithmeticMeanOfCubes(num1, num2);
    double geometricMean = calculateGeometricMeanOfAbs(num1, num2);

    // Вывод
    cout << "\nРезультаты вычислений:\n";
    cout << "Среднее арифметическое кубов: " << arithmeticMean << endl;
    cout << "Среднее геометрическое модулей: " << geometricMean << endl;

    return 0;
}