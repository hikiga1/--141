#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

/**
* Вычисляет значение функции y = x + cos(x^0.52 + 2)
* @param x - аргумент функции
* @return значение функции в точке x
*/
double functionY(double const x);

/**
* Табулирует функцию на интервале [x0, xend] с шагом step
* @param x0 - начальное значение x
* @param xend - конечное значение x
* @param step - шаг табуляции
*/
void tabulateFunction(double const x0, double const xend, double const step);

/**
* @brief Считывает значение с клавиатуры
* @return Введенное значение
*/
double getInput();

int main() {
    cout << "Введите начальное значение x: ";
    double x0 = getInput();
    cout << "Введите конечное значение x: ";
    double xend = getInput();
    cout << "Введите шаг ∆x: ";
    double step = getInput();

    if (step <= 0) {
        cout << "Шаг должен быть положительным" << endl;
        return 1;
    }
    if (x0 > xend) {
        cout << "Начальное значение не может быть больше конечного" << endl;
        return 1;
    }

    tabulateFunction(x0, xend, step);
    return 0;
}

double functionY(double const x) {
    return x + cos(pow(x, 0.52) + 2);
}

void tabulateFunction(double const x0, double const xend, double const step) {
    cout << "     x     |      y(x)" << endl;

    for (double x = x0; x <= xend + 1e-9; x += step) {
        cout << fixed << setprecision(4) << setw(10) << x << " | ";
        if (x < 0) {
            cout << "  не определено";
        } else {
            double y = functionY(x);
            cout << setw(10) << y;
        }
        cout << endl;
    }
}

double getInput() {
    double value = 0;  // Инициализация нулем
    cin >> value;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}