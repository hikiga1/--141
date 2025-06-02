#include <iostream>
#include <cmath>
#include<locale>
#include<windows.h>
#include<string>
using namespace std;
/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
int getValue();

/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
double getDouble();

/*
 * @brief проверяет, что введенное значение удовлетваряет условию n>=1
 * @param n считанное значение
*/
void checkN(const int n);

/**
 * @brief Рассчитывает сумму n первых членов ряда
 * @param n заданное число членов
 * @return сумму n первых членов ряда
*/
double sumN(const int n);

/**
 * @brief Рассчитывает следующий член ряда через рекуррентное выражение
 * @param curent текущий член ряда
 * @param i текущий индекс
 * @return следующий член ряда
*/
double getNext(const double current, const int i);

/**
 * @brief проверяет, что введенное значение удовлетваряет условию e>0
 * @param e считанное значение
*/
void checkE(const double e);

/**
 * @brief Рассчитывает сумму первых членов ряда, не превышающих по модулю e
 * @param e заданная точность
 * @return сумму первых членов ряда, не превышающих по модулю e
*/
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main()
{
	setlocale(LC_ALL, "Russian");
    cout<<"Enter the number of terms of the series to calculate the sequence: ";
    int n = getValue();
    checkN(n);
    cout<<"Sum "<<n<<" terms of the series= "<<sumN(n)<<endl;
    cout<<"Enter error to calculate the series: ";
    double e = getDouble();
    checkE(e);
    cout<<"Sum of the terms with error e =  "<<sumE(e)<<endl;;
    return 0;
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
}

double getDouble()
{
    double value = 0.0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
}

void checkN(const int n)
{
    if (n < 1)
    {
        cout << "Ошибка ввода"<< endl;
        abort();
    }
}

double sumN(const int n)
{
    
    double current = (-8.0)/1.0;
    double result = current;
    for (int i = 1; i < n ; i++)
    {
        current = getNext(current, i);
        result += current;
    }
    return result;
}


double getNext(const double current, const int i)
{
    return current * (-1.0)*pow(i+2,3)/pow(i+1,4);
}

void checkE(const double e)
{
        if (!(e > 0))
        {
        cout << "Ошибка ввода"<< endl;
        abort();
        }
}

double sumE(const double e)
{
    double current = (-8.0)/1.0;
    double result = 0;
    for (int i = 1; abs(current) > e ; i++)
    {
        result += current;
        current = getNext(current, i);
        
    }
    return result;
}