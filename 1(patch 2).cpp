#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Прототипы функций
/**
 * Функция для вычисления первого выражения a.
 * @param x - первый параметр (константа)
 * @param y - второй параметр (константа)
 * @param z - третий параметр (константа)
 * @return - результат вычисления выражения a
 */
double calculateA(double x, double y, double z);

/**
 * Функция для вычисления второго выражения b.
 * @param x - первый параметр (константа)
 * @param y - второй параметр (константа)
 * @param z - третий параметр (константа)
 * @return - результат вычисления выражения b
 */
double calculateB(double x, double y, double z);

/**
 * Функция для вывода результатов вычислений.
 * Выводит значения выражений a и b с пояснениями.
 * @param x - первый параметр (константа)
 * @param y - второй параметр (константа)
 * @param z - третий параметр (константа)
 */
void printResults(double x, double y, double z);

int main() {
    // Заданные константы
    const double x = 2.2;
    const double y = 9.2;
    const double z = 10.2;

    // Выводим результаты вычислений
    printResults(x, y, z);
    return 0;
}

// Реализация функции вычисления a
double calculateA(double x, double y, double z) {
    return log(z + pow(x, 2)) + pow(sin(x / y), 2);
}

// Реализация функции вычисления b
double calculateB(double x, double y, double z) {
    return exp(z * x + sqrt(x + z)) * sqrt(fabs(x - y));
}

// Реализация функции вывода результатов
void printResults(double x, double y, double z) {
    // Вычисляем значения a и b
    double a = calculateA(x, y, z);
    double b = calculateB(x, y, z);

    // Выводим константы
    cout << "Константы: x = " << x << ", y = " << y << ", z = " << z << endl;

    // Выводим результаты с пояснениями
    cout << "Результаты вычислений:" << endl;
    cout << fixed << setprecision(6);  // Устанавливаем точность вывода
    cout << "a = ln(z + x^2) + sin^2(x/y) = " << a << endl;
    cout << "b = e^(zx + √(x+z)) * √|x-y| = " << b << endl;
}