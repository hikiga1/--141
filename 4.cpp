#include <iostream>
#include<math.h>
#include <limits>
#define _USE_MATH_DEFINES

double getValue();
/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/

double getY(const double x);
/**
 * @brief Рассчитывает функцию
 * @return значение функции
*/

void checkStep(const double step);

using namespace std;
int main()
{
	 cout<<"Enter xn: ";
    double xstart = getValue();
    cout<<"Enter xk: ";
    double xend = getValue();
    cout<<"Enter step: ";
    double step = getValue();
    checkStep(step);
    for (double x = xstart; x<xend+step; x+=step)
    {
        cout<< "x = "<<x;
        cout<< " y = "<<getY(x)<<endl;
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

void checkStep(const double step)
{
    if(step <= 0 )
    {
        cout<<"Error value"<< endl;
        abort();
    }
}

double getY(const double x)
{
    return x + cos((pow(x,0.52) +2)*(180/M_PI) );
}