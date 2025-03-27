#include <random>
#include <ctime>
#include <iostream>

#define TESTS 100
#define LENGTH 15
#define MAX_WEIGHT 100

using namespace std;

template<class T>
class Stack // Сущность обобщенного стека
{
protected:
	int capacity, count;
	T* items;

public:
	Stack(const T* initial, size_t length) : Stack(length / sizeof(T))
	{
		count = capacity;
		memcpy_s(items, length, initial, length);
	}
	
	Stack(const int capacity = 10) : capacity(capacity)
	{
		count = 0;
		items = new T[capacity];
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

	T top() const
	{
		return items[count - 1];
	}

	int getSize() const
	{
		return count;
	}

	int getCapacity() const
	{
		return capacity;
	}

	bool isEmpty() const
	{
		return count == 0;
	}

	bool isSorted() const
	{
		if (count <= 1) return true;

		T previous = items[0];
		for (int i = 1; i < count; ++i)
		{
			const T current = items[i];

			if (previous < current)
			{
				return false;
			}

			previous = current;
		}

		return true;
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
bool tsort(Stack<T>& input, Stack<T>& output) // Сортировка стеком
{
	if (input.getCapacity() > output.getCapacity()) return false;

	Stack<T> deadend(input.getSize());

	while (true)
	{
		// Обнвружена некорректная последовательность
		// Перегоняем все вагоны с выхода на вход, которые "легче", чем вагон в тупике
		while (!output.isEmpty() && !deadend.isEmpty() && output.top() < deadend.top())
		{
			input.push(output.pop());
		}

		// Если на входе не осталось вагонов
		if (input.isEmpty()) break;

		// Перегоняем все вагоны из тупика на выход, которые "тяжелее" чем вагон на входе
		while (!deadend.isEmpty() && input.top() < deadend.top())
		{
			output.push(deadend.pop());
		}

		// Перегоняем вагон со входа на тупик
		deadend.push(input.pop());
	}

	// Перегоняем все оставшиеся вагоны на выход
	while (!deadend.isEmpty())
	{
		output.push(deadend.pop());
	}

	return true;
}

int map(int x, int in_min, int in_max, int out_min, int out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int iRandom(int max)
{
	return map(rand(), 0, RAND_MAX, 0, max);
}

int main()
{
	std::srand(std::time({}));

	int failed = 0;

	int values[LENGTH];
	for (int j = 0; j < TESTS; ++j)
	{
		for (int i = 0; i < LENGTH; ++i)
		{
			values[i] = iRandom(MAX_WEIGHT);
		}

		cout << "Test #" << j + 1 << endl;

		Stack<int> input(values, sizeof(values)), output(input.getSize());

		cout << "I: " << input << endl;
		if (!tsort(input, output)) cout << "O: " << "Error!" << endl;
		else cout << "O: " << output << endl;

		bool isSorted = output.isSorted();
		if (!isSorted) ++failed;

		cout << "ok: " << (isSorted ? "true" : "false") << endl;

		cout << endl;
	}

	cout << "failed: " << failed << endl;

	return 0;
}