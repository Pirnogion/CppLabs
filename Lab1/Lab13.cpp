#include <iostream>

using namespace std;

// ���������� �������:
void obmen1(int, int); // ��������� ������� 
void obmen2(int*, int*);
void obmen3(int&, int&);

void main()
{
    int a = 2, b = 5;
    cout << "�� ������: a=" << a << ", b=" << b << endl;

    obmen1(a, b);
    cout << "����� ������ 1: a=" << a << ", b=" << b << endl;

    obmen2(&a, &b);
    cout << "����� ������ 2: a=" << a << ", b=" << b << endl;

    obmen3(a, b);
    cout << "����� ������ 3: a=" << a << ", b=" << b << endl;
}

void obmen1(int a, int b) // ����������� �������
{
   // ����� �� ��������� ���������, ��� ��� ������������ �������� �� ��������
}

void obmen2(int* a, int* b) // �������� �� ���������
{
    int t = *a;
    *a = *b;   
    *b = t;    
}

void obmen3(int& a, int& b) // �������� �� ������
{
    int t = a;
    a = b;    
    b = t;    
}