#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода.
 * @return Введённое значение.
 */
double getValue();

/**
 * @brief Проверяет существование квадратного корня из произведения чисел.
 * @param a Первое число.
 * @param b Второе число.
 * @return true, если произведение положительное; иначе false.
 */
bool checkExist(const double a, const double b);

/**
 * @brief Рассчитывает среднее арифметическое кубов двух чисел.
 * @param a Первое число.
 * @param b Второе число.
 * @return Среднее арифметическое.
 */
double getRm(const double a, const double b);

/**
 * @brief Рассчитывает среднее геометрическое двух чисел.
 * @param a Первое число.
 * @param b Второе число.
 * @return Среднее геометрическое.
 */
double getRg(const double a, const double b);

/**
 * @brief Точка входа в программу.
 * @return 0 при успешном выполнении.
 */
int main()
{
    cout << "Enter first number: ";
    const double a = getValue();

    cout << "Enter second number: ";
    const double b = getValue();

    cout << "Rm = " << getRm(a, b) << endl;

    if (checkExist(a, b)) {
        cout << "Rg = " << getRg(a, b) << endl;
    } else {
        cout << "The square root of a negative number does not exist." << endl;
    }

    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail()) {
        cout << "Incorrect value." << endl;
        exit(1);
    }
    return value;
}

bool checkExist(const double a, const double b)
{
    return a * b > 0;
}

double getRm(const double a, const double b)
{
    return (pow(a, 3) + pow(b, 3)) / 2.0;
}

double getRg(const double a, const double b)
{
    return sqrt(abs(a * b));
}