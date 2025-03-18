#include <iostream>

using namespace std;

float power(float, int); // Прототип функции

void main()
{
    float k; // Объявление переменной, не инициализируется
    for (int i = 0; i < 10; i++) // Определение переменной цикла, цикл от 0 до 9 включительно с инкрементом счетчика
    {
        k = power(1.5f, i);
        cout << "i = " << i << ", k = " << k << endl; // Вывод данны в выходной поток
    }
}

float power(float x, int n) // Функция возведения в степень
{
    float p = 1.0f;
    for (int i = 1; i <= n; i++)
        p *= x;

    return p;
}