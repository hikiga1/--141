#include<iostream>
#include<math.h>

using namespace std;

/*
  B-11
 *@brief - Функция для вычисления A по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z 
 *@return - возвращает рассчитанное значение
*/
double getA(const double x,const double y,const double z);

 /* *@brief - Функция для вычисления B по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z 
 *@return - возвращает рассчитанное значение
*/
double getB(const double x,const double y,const double z);

int main(){
const double x=2.2;
const double y=9.2;
const double z=10.2;
cout<<"A= "<<getA(x,y,z)<<endl;
cout<<"B= "<<getB(x,y,z);
    return 0;
}

double getA(const double x,const double y,const double z){
   return log(z+ pow(x,2) )+pow(sin(x/y),2);
}

double getB(const double x,const double y,const double z){
   return exp(-z)*( (x+sqrt(x+z))/(x-sqrt(abs(x-y)) ) );
}