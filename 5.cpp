#include <iostream>

int getValue();
/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
size_t getSize();
/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
void checkN(const int n);
/**
 * @brief проверяет если число введен верно
*/
void fillArray(int* arr, const int n);
/**
 * @brief Пополнение массива с клавиатурой
*/
void printArray(int* arr, const int n);
/**
 * @brief Печать массива
*/
int sumOfElements(int* arr, const int n);
/**
 * @brief Вычисляет сумму четных чисел 
 * @return считанное значение
*/
size_t getIndexOfFirstCoupleofNumberswithdifferentssigns(int* arr, const int n);
/**
 * @brief Находит индекс первой пары соседних элементов с разными знаками 
 * @return считанное значение
*/
void multOfElements(int* arr, const int n);
/**
 * @brief Умножит все четные положительные элементы на последний элемент массива 
*/
int* copyArray(int* arr, const int n);
/**
 * @brief Делает копию исходного массива
 * @return новый массив
*/
using namespace std;

int main()
{
    size_t n = getSize();
    int* arr = new int [n];
    fillArray(arr, n);
    printArray(arr,n);
    cout<<"Sum of elements multiples 2: "<< sumOfElements(arr,n)<<endl;
    int index = getIndexOfFirstCoupleofNumberswithdifferentssigns(arr,n);
    if (index == n)
        {
            cout<<"No neighbor elements with differents signs"<<endl;
        }
    else
    {
        cout<<"Index of first couple of neighbor elements with differents signs: "<< index<<" and "<<index+1<<endl;
    }  
    int* freshArr = copyArray(arr,n);  
    multOfElements(freshArr, n);
    delete [] arr;
    delete [] freshArr;
	return 0;
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Error"<<endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    std::cout<<"Enter n ";
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n<=0)
    {
        cout<<"Error"<<endl;
        abort();
    }
}

void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter arr["<<i+1<<"] = ";
        arr[i] = getValue();
    }
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sumOfElements(int* arr, const int n)
{
    int result = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            result += arr[i];
        }
    }
    return result;
}

void multOfElements(int* arr, const int n)
{
    int result = 1;
    for (size_t i = 0; i < n; i++)
    {
        if ((arr[i] % 2 == 0) && (arr[i]>0))
        {
            result = arr[i]*arr[n-1];
            cout<<"The multiplication="<<result<<endl;
        }
    }
  
}

size_t getIndexOfFirstCoupleofNumberswithdifferentssigns(int* arr, const int n)
{
    for (size_t i = 1; i <= n; i++)
    {
        if ((arr[i] < 0)&& (arr[i-1]>0))
        {
            return i;
        }
        else if((arr[i-1] < 0)&& (arr[i]>0)){
        	return i;
		}
    }
    return n;
}

int* copyArray(int* arr, const int n)
{
    int* copyArr = new int [n];
    for (size_t i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}