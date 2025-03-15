#include <iostream>

using namespace std;

float power(float, int);

void main()
{
    float k;
    for (int i = 0; i < 10; i++)
    {
        k = power(1.5f, i);
        cout << "i = " << i << ", k = " << k << endl;
    }
}

float power(float x, int n)
{
    float p = 1.0f;
    for (int i = 1; i <= n; i++)
        p *= x;

    return p;
}