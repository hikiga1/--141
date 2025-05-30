#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

using namespace std;

/**
 * @brief - Вычисляет факториал числа
 * @param k - целое неотрицательное число
 * @return - возвращает значение факториала
 */
double Factorial(const int k);

/**
 * @brief - Вычисляет сумму первых n членов последовательности
 * @param n - количество членов
 * @return - возвращает сумму членов
 */
double SumN(const int n);

/**
 * @brief - Вычисляет сумму членов с модулем >= e
 * @param e - минимальное значение модуля
 * @return - возвращает сумму подходящих членов
 */
double SumE(const double e);

/**
 * @brief - Проверяет корректность ввода целого числа
 * @return - возвращает введенное число, если оно корректно
 */
int getIntValue();

/**
 * @brief - Проверяет корректность ввода вещественного числа
 * @return - возвращает введенное число, если оно корректно
 */
double getDoubleValue();

int main() {
    cout << "Введите количество членов n: ";
    int n = getIntValue();
    
    cout << "Введите минимальный модуль e: ";
    double e = getDoubleValue();

    cout << "Результаты вычислений:" << endl;
    cout << "Сумма первых " << n << " членов: " << SumN(n) << endl;
    cout << "Сумма членов с модулем >= " << e << ": " << SumE(e) << endl;

    return 0;
}

double Factorial(const int k) {
    double result = 1.0;
    for (int i = 1; i <= k; ++i) {
        result *= i;
    }
    return result;
}

double SumN(const int n) {
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {
        sum += pow(-1, k) * pow(k + 1, 3) / Factorial(k);
    }
    return sum;
}

double SumE(const double e) {
    double sum = 0.0;
    int k = 1;
    double term;
    
    do {
        term = pow(-1, k) * pow(k + 1, 3) / Factorial(k);
        if (abs(term) >= e) {
            sum += term;
        }
        k++;
    } while (abs(term) >= e || k < 100);

    return sum;
}

int getIntValue() {
    int value;
    cin >> value;
    if (cin.fail() || (value <= 0)) {
        cout << "Ошибка: введите целое положительное число" << endl;
        exit(EXIT_FAILURE);
    }
    return value;
}

double getDoubleValue() {
    double value;
    cin >> value;
    if (cin.fail() || (value <= 0)) {
        cout << "Ошибка: введите положительное число" << endl;
        exit(EXIT_FAILURE);
    }
    return value;
}