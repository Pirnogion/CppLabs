#include <iostream>

using namespace std;

// Реадизации различных сортировок
void minsort(int*, const int);
void maxsort(int*, const int);
void bubblesort(int*, const int);

void ascintquicksort(int*, const int, const int);
void dscintquicksort(int*, const int, const int);

void quicksort(int*, const int);
void quicksort_recursive_ascending(int*, const int, const int);
void quicksort_recursive_descending(int*, const int, const int);
int quicksort_partition_ascending(int*, const int, const int);
int quicksort_partition_descending(int*, const int, const int);

void oddevenbubblesort(int*, const int);
bool isEven(const int&);
bool isOdd(const int&);

void printArray(const int*, const int);

void main()
{
	int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
	int n = sizeof(mas) / sizeof(int);

	printArray(mas, n);
	//minsort(mas, n);
	//maxsort(mas, n);
	//bubblesort(mas, n);
	//quicksort(mas, n);
	//oddevenbubblesort(mas, n);
	//ascintquicksort(mas, 2, 8);
	//dscintquicksort(mas, 2, 8);
	printArray(mas, n);
}

void minsort(int* array, const int length)
{
	for (int i = 0, imin = 0; i < length - 1; ++i)
	{
		imin = i;

		for (int j = i + 1; j < length; ++j)
		{
			if (array[j] < array[imin]) imin = j;
		}

		swap(array[i], array[imin]);
	}
}

void maxsort(int* array, const int length)
{
	for (int i = 0, imax = 0; i < length - 1; ++i)
	{
		imax = i;

		for (int j = i + 1; j < length; ++j)
		{
			if (array[j] > array[imax]) imax = j;
		}

		swap(array[i], array[imax]);
	}
}

void bubblesort(int* array, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
		}
	}
}

void ascintquicksort(int* array, const int left, const int right)
{
	quicksort_recursive_ascending(array, left, right);
}

void dscintquicksort(int* array, const int left, const int right)
{
	quicksort_recursive_descending(array, left, right);
}

void quicksort(int* array, const int length)
{
	quicksort_recursive_ascending(array, 0, length - 1);
}

void quicksort_recursive_ascending(int* array, const int left, const int right)
{
	if (left >= right) return;

	int middle = quicksort_partition_ascending(array, left, right);
	quicksort_recursive_ascending(array, left, middle);
	quicksort_recursive_ascending(array, middle + 1, right);
}

void quicksort_recursive_descending(int* array, const int left, const int right)
{
	if (left >= right) return;

	int middle = quicksort_partition_descending(array, left, right);
	quicksort_recursive_descending(array, left, middle);
	quicksort_recursive_descending(array, middle + 1, right);
}

int quicksort_partition_ascending(int* array, const int left, const int right)
{
	int value = array[(left + right) / 2];

	int i = left, j = right;
	while (i <= j)
	{
		while (array[i] < value) ++i;
		while (array[j] > value) --j;
		if (i >= j) break;

		swap(array[i++], array[j--]);
	}

	return j;
}

int quicksort_partition_descending(int* array, const int left, const int right)
{
	int value = array[(left + right) / 2];

	int i = left, j = right;
	while (i <= j)
	{
		while (array[i] > value) ++i;
		while (array[j] < value) --j;
		if (i >= j) break;

		swap(array[i++], array[j--]);
	}

	return j;
}

void oddevenbubblesort(int* array, const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (isEven(array[j]) && isOdd(array[j + 1])) swap(array[j], array[j + 1]);
			else if (isEven(array[j]) && isEven(array[j + 1]) && array[j] > array[j + 1]) swap(array[j], array[j + 1]);
			else if (isOdd(array[j]) && isOdd(array[j + 1]) && array[j] < array[j + 1]) swap(array[j], array[j + 1]);
		}
	}
}

bool isEven(const int& value)
{
	return !isOdd(value);
}

bool isOdd(const int& value)
{
	return value & 1; // Аналогично x % 2 === 1
}

void printArray(const int* array, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}