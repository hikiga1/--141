#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Прототипы функций
double calculateA(double x, double y, double z);
double calculateB(double x, double y, double z);
void printResults(double x, double y, double z);

int main() {
    const double x = 2.2;
    const double y = 9.2;
    const double z = 10.2;
    
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
    double a = calculateA(x, y, z);
    double b = calculateB(x, y, z);
    
    cout << "Константы: x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << "Результаты вычислений:" << endl;
    cout << fixed << setprecision(6);
    cout << "a = ln(z + x^2) + sin^2(x/y) = " << a << endl;
    cout << "b = e^(zx + √(x+z)) * √|x-y| = " << b << endl;
}