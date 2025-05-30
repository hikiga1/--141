#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления переменных a и b
void computeAB(double x, double y, double z, double& a, double& b) {
    a = log(z + pow(x, 2)) + pow(sin(x / y), 2);
    b = exp(z * x + sqrt(x + z)) * sqrt(fabs(x - y));
}

void calculateVariant11() {
    // Константы по заданию
    const double x = 2.2;
    const double y = 9.2;
    const double z = 10.2;

    double a, b;
    computeAB(x, y, z, a, b);

    // Вывод результатов
    cout << "Вариант:" << endl;
    cout << "Константы: x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << "Результаты вычислений:" << endl;
    cout << fixed << setprecision(6);
    cout << "a = ln(z + x^2) + sin^2(x/y) = " << a << endl;
    cout << "b = e^(zx + √(x+z)) * √|x-y| = " << b << endl;
}

int main() {
    calculateVariant11();
    return 0;
}
