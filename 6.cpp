#include <iostream>

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
 * @brief Заполняет массив с клавиатуры
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void fillArray(int* arr, const int n);

/**
 * @brief Печатает массив в консоль
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void printArray(int* arr, const int n);

/**
 * @brief Вычисляет сумму четных элементов массива
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Сумма четных элементов
 */
int sumOfElements(int* arr, const int n);

/**
 * @brief Находит индекс первой пары соседних элементов с разными знаками
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Индекс первой пары или n, если такой пары нет
 */
size_t getIndexOfFirstCoupleofNumberswithdifferentssigns(int* arr, const int n);

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
int* copyArray(int* arr, const int n);

/**
 * @brief Использование пространства имён std
 */
using namespace std;

/**
 * @brief Главная функция программы
 * @return Код завершения
 */
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

void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i + 1 << "] = ";
        arr[i] = getValue();
    }
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int result;
    for (size_t i = 0; i < n; i++)
    {
        if ((arr[i] % 2 == 0) && (arr[i] > 0))
        {
            result = arr[i] * arr[n - 1];
            cout << "The multiplication = " << result << endl;
        }
    }
}

size_t getIndexOfFirstCoupleofNumberswithdifferentssigns(int* arr, const int n)
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

int* copyArray(int* arr, const int n)
{
    int* copyArr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}