#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
/**
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return введенное значение
 */
 
double getValue();
/**
 * @brief проверяет существование квадратичного корня
 * @param a - первое число
 * @param b - второе число
 * return false если не существует, true если существует
 */
 
bool checkExist( double a,  double b);
/**
* * @brief рассчитивает среднее арифметическое
 * @param a - первое число
 * @param b - второе число
 * @return среднее арифметическое
 */
 
double getRm( double a,  double b);
/**
* * @brief рассчитивает среднее геометрическое
 * @param a - первое число
 * @param b - второе число
 * @return среднее геометрическое
 */
 
double getRg( double a,  double b);
/**
 * @brief точка входа в программу
 * @return 0, если прогамма выполнена корректно, иначе 1 
 */
int main()
{
    cout<<"Enter first number ";
    double a = getValue();
    cout<<"Enter second number ";
    double b = getValue();
    bool F=checkExist(a, b);
   
    cout<<"Rm= "<<getRm(a,b)<<endl;

    if(checkExist(a,b)){
        cout<<"Rg= "<<getRg(a,b);
    }
    else{
    	cout<<"The square root of a negative number does not exist";
       
    }

    return 0;
}
double getValue()
{
    double value=0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Incorrect value"<<endl;
        abort();
    }
    return value;
}

bool checkExist( double a,  double b)
{
  return a*b>0;
}

double getRm( double a,  double b){
    return (pow(a,3)+pow(b,3) )/2;
}

double getRg( double a,  double b){
    return sqrt(a*b);
}