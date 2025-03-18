#include <iostream>

using namespace std;

template<class T>
class Stack // Сущность обобщенного стека
{
protected:
	int count;
	T* items;

public:
	Stack(size_t size = 10)
	{
		count = 0;
		items = new T[size];
	}

	~Stack()
	{
		delete[] items;
	}

	void push(T t)
	{
		items[count++] = t;
	}

	T pop()
	{
		return items[--count];
	}

	T top()
	{
		return items[count - 1];
	}

	bool isEmpty()
	{
		return count == 0;
	}

	friend ostream& operator<<(ostream& os, Stack<T>& s)
	{
		os << "{ ";
		for (int i = 0; i < s.count; ++i) os << s.items[i] << " ";
		os << "}";

		return os;
	}
};

template<class T>
void tsort(T src[], T dst[], size_t length) // Сортировка стеком
{
	Stack<T> deadend;
	size_t vacancy = 0;

	for (int i = 0; i < length; ++i)
	{
		T val = src[i];

		while (!deadend.isEmpty() && val < deadend.top())
		{
			dst[vacancy++] = deadend.pop();
		}

		deadend.push(val);
	}

	while (!deadend.isEmpty())
	{
		dst[vacancy++] = deadend.pop();
	}
}

int main()
{
	int ints[] = { 1, 5, 3, 9 };
	const size_t length = sizeof(ints) / sizeof(int);

	int dst[length];
	tsort(ints, dst, length); // Сортирует не любой массив, есть теоретические ограничения на такакого рода сортировку

	for (int i = 0; i < length; ++i) cout << dst[i] << " ";

	return 0;
}