#include <iostream>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()

/**
 * @brief Считывает целое число с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int getValue();

/**
 * @brief Считывает размер массива с клавиатуры
 * @return Размер массива
 */
size_t getSize();

/**
 * @brief Проверяет корректность введенного размера массива
 * @param n Введенное значение
 */
void checkN(const int n);

/**
 * @brief Заполняет массив либо вручную, либо случайными числами в заданном диапазоне
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void fillArray(int* arr, const int n);

/**
 * @brief Печатает массив в консоль
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief Вычисляет сумму четных элементов массива
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Сумма четных элементов
 */
int sumOfElements(const int* arr, const int n);

/**
 * @brief Находит индекс первой пары соседних элементов с разными знаками
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Индекс первой пары или n, если такой пары нет
 */
size_t getIndexOfFirstCoupleofNumberswithdifferentssigns(const int* arr, const int n);

/**
 * @brief Умножает все четные положительные элементы на последний элемент массива и выводит результат
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void multOfElements(int* arr, const int n);

/**
 * @brief Копирует содержимое одного массива в другой
 * @param arr Указатель на исходный массив
 * @param n Размер массива
 * @return Указатель на новый массив
 */
int* copyArray(const int* arr, const int n);

using namespace std;

int main()
{
    size_t n = getSize();
    int* arr = new int[n];
    fillArray(arr, n);
    printArray(arr, n);

    cout << "Sum of elements multiples 2: " << sumOfElements(arr, n) << endl;

    int index = getIndexOfFirstCoupleofNumberswithdifferentssigns(arr, n);
    if (index == n)
    {
        cout << "No neighbor elements with different signs" << endl;
    }
    else
    {
        cout << "Index of first couple of neighbor elements with different signs: " << index << " and " << index + 1 << endl;
    }

    int* freshArr = copyArray(arr, n);
    multOfElements(freshArr, n);

    delete[] arr;
    delete[] freshArr;

    return 0;
}

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Error: invalid input" << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    cout << "Enter n: ";
    int n = getValue();
    checkN(n);
    return static_cast<size_t>(n);
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Error: size must be positive" << endl;
        abort();
    }
}

void fillArray(int* arr, const int n) {
    cout << "Choose filling method:\n";
    cout << "1 - Manual input\n";
    cout << "2 - Random values\n";
    cout << "Your choice: ";
    
    int choice = getValue();
    
    if (choice == 1) {
        for (size_t i = 0; i < n; i++) {
            cout << "Enter arr[" << i + 1 << "] = ";
            arr[i] = getValue();
        }
    }
    else if (choice == 2) {
        cout << "Enter minimum value: ";
        int minVal = getValue();
        cout << "Enter maximum value: ";
        int maxVal = getValue();
        
        if (minVal > maxVal) {
            cout << "Error: min must be <= max\n";
            abort();
        }
        
        srand(time(0));
        for (size_t i = 0; i < n; i++) {
            arr[i] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
    else {
        cout << "Error: invalid choice\n";
        abort();
    }
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumOfElements(const int* arr, const int n)
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

size_t getIndexOfFirstCoupleofNumberswithdifferentssigns(const int* arr, const int n)
{
    for (size_t i = 1; i < static_cast<size_t>(n); i++)
    {
        if ((arr[i] < 0 && arr[i - 1] > 0) || (arr[i] > 0 && arr[i - 1] < 0))
        {
            return i - 1;
        }
    }
    return n;
}

void multOfElements(int* arr, const int n)
{
    bool found = false;
    int lastElement = arr[n - 1];
    
    // Сначала модифицируем массив
    for (size_t i = 0; i < n; i++)
    {
        if ((arr[i] % 2 == 0) && (arr[i] > 0))
        {
            arr[i] *= lastElement;
            found = true;
        }
    }
    
    // Затем выводим результат
    cout << "Array after multiplication: ";
    printArray(arr, n);
    
    if (!found)
    {
        cout << "No even positive elements were found to multiply" << endl;
    }
}

int* copyArray(const int* arr, const int n)
{
    int* copyArr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}