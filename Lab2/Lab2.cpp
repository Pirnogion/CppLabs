#include <conio.h>

#include <cassert>

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>

#define N 5

using namespace std; // Подулючение к области видимости стандартной библиотеки

using t_matrix = const float (&)[N][N]; // Определение типа ссылки на неизменяемую матрицу дробных чисел размера NxN

// Много всяких разных функций для работы с матрицей
float getMax(t_matrix);
float getMin(t_matrix);
float getUpperTriangleMax(t_matrix);
float getUpperTriangleMin(t_matrix);
float getLowerTriangleMax(t_matrix);
float getLowerTriangleMin(t_matrix);
float getMajorDiagonalMax(t_matrix);
float getMajorDiagonalMin(t_matrix);
float getMinorDiagonalMax(t_matrix);
float getMinorDiagonalMin(t_matrix);
float getAverage(t_matrix);
float getUpperTriangleAverage(t_matrix);
float getLowerTriangleAverage(t_matrix);
float getUpperTriangleSum(t_matrix);
float getLowerTriangleSum(t_matrix);
float getNearestToAverage(t_matrix);

// Используется контейнер из стандартной библиотеки С++
vector<float> getRowsSum(t_matrix);
vector<float> getColsSum(t_matrix);
vector<float> getRowsMin(t_matrix);
vector<float> getColsMin(t_matrix);
vector<float> getRowsMax(t_matrix);
vector<float> getColsMax(t_matrix);
vector<float> getRowsAverage(t_matrix);
vector<float> getColsAverage(t_matrix);

string printVector(vector<float>);

void main()
{
	float m[N][N];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			m[i][j] = rand() / 10.0f;
		}
	}

	cout << "[ MATRIX ]" << endl << endl;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << setw(8) << setprecision(5) << m[i][j];
		}

		cout << endl;
	}

	cout << endl << endl << "[ RESULTS ]" << endl << endl;

	cout << "Max: (" << getMax(m) << ")" << endl;
	cout << "Min: (" << getMin(m) << ")" << endl;
	cout << "Upper triangle max: (" << getUpperTriangleMax(m) << ")" << endl;
	cout << "Upper triangle min: (" << getUpperTriangleMin(m) << ")" << endl;
	cout << "Lower triangle max: (" << getLowerTriangleMax(m) << ")" << endl;
	cout << "Lower triangle min: (" << getLowerTriangleMin(m) << ")" << endl;
	cout << "Major diagonal max: (" << getMajorDiagonalMax(m) << ")" << endl;
	cout << "Major diagonal min: (" << getMajorDiagonalMin(m) << ")" << endl;
	cout << "Minor diagonal max: (" << getMinorDiagonalMax(m) << ")" << endl;
	cout << "Minor diagonal min: (" << getMinorDiagonalMin(m) << ")" << endl;
	cout << "Average: (" << getAverage(m) << ")" << endl;
	cout << "Upper triangle average: (" << getUpperTriangleAverage(m) << ")" << endl;
	cout << "Lower triangle average: (" << getLowerTriangleAverage(m) << ")" << endl;
	cout << "Upper triangle sum: (" << getUpperTriangleSum(m) << ")" << endl;
	cout << "Lower triangle sum: (" << getLowerTriangleSum(m) << ")" << endl;
	cout << "Nearest to average: (" << getNearestToAverage(m) << ")" << endl;

	cout << "Rows sum: (" << printVector( getRowsSum(m) ) << ")" << endl;
	cout << "Cols sum: (" << printVector( getColsSum(m) ) << ")" << endl;
	cout << "Rows min: (" << printVector( getRowsMin(m) ) << ")" << endl;
	cout << "Cols min: (" << printVector( getColsMin(m) ) << ")" << endl;
	cout << "Rows max: (" << printVector( getRowsMax(m) ) << ")" << endl;
	cout << "Cols max: (" << printVector( getColsMax(m) ) << ")" << endl;
	cout << "Rows average: (" << printVector(getRowsAverage(m)) << ")" << endl;
	cout << "Cols average: (" << printVector(getColsAverage(m)) << ")" << endl;

	_getch();
}

float getMax(t_matrix matrix)
{
	float maximum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			maximum = max(maximum, matrix[i][j]);
		}
	}

	return maximum;
}

float getMin(t_matrix matrix)
{
	float minimum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			minimum = min(minimum, matrix[i][j]);
		}
	}

	return minimum;
}

float getUpperTriangleMax(t_matrix matrix)
{
	float maximum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			maximum = max(maximum, matrix[i][j]);
		}
	}

	return maximum;
}

float getUpperTriangleMin(t_matrix matrix)
{
	float minimum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			minimum = min(minimum, matrix[i][j]);
		}
	}

	return minimum;
}

float getLowerTriangleMax(t_matrix matrix)
{
	float maximum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			maximum = max(maximum, matrix[i][j]);
		}
	}

	return maximum;
}

float getLowerTriangleMin(t_matrix matrix)
{
	float minimum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j <= i; ++j)
		{
			minimum = min(minimum, matrix[i][j]);
		}
	}

	return minimum;
}

float getMajorDiagonalMax(t_matrix matrix)
{
	float maximum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		maximum = max(maximum, matrix[i][i]);
	}

	return maximum;
}

float getMajorDiagonalMin(t_matrix matrix)
{
	float minimum = matrix[0][0];
	for (int i = 0; i < N; ++i)
	{
		minimum = min(minimum, matrix[i][i]);
	}

	return minimum;
}

float getMinorDiagonalMax(t_matrix matrix)
{
	float maximum = matrix[0][N-1];
	for (int i = 0; i < N; ++i)
	{
		maximum = max(maximum, matrix[i][N-1-i]);
	}

	return maximum;
}

float getMinorDiagonalMin(t_matrix matrix)
{
	float minimum = matrix[0][N-1];
	for (int i = 0; i < N; ++i)
	{
		minimum = min(minimum, matrix[i][N-1-i]);
	}

	return minimum;
}

float getAverage(t_matrix matrix)
{
	float average = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			average += matrix[i][j];
		}
	}

	return average / N;
}

float getUpperTriangleAverage(t_matrix matrix)
{
	float average = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			average += matrix[i][j];
		}
	}

	return average / N;
}

float getLowerTriangleAverage(t_matrix matrix)
{
	float average = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			average += matrix[i][j];
		}
	}

	return average / N;
}

float getUpperTriangleSum(t_matrix matrix)
{
	float sum = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			sum += matrix[i][j];
		}
	}

	return sum;
}

float getLowerTriangleSum(t_matrix matrix)
{
	float sum = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			sum += matrix[i][j];
		}
	}

	return sum;
}

float getNearestToAverage(t_matrix matrix)
{
	float average = getAverage(matrix);

	float mindiff = numeric_limits<float>::infinity();
	float nearest = matrix[0][0];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			float value = matrix[i][j];
			float diff = abs(average - value);

			if (diff < mindiff)
			{
				mindiff = diff;
				nearest = value;
			}
		}
	}

	return nearest;
}

vector<float> getRowsSum(t_matrix matrix)
{
	vector<float> vector;

	for (int i = 0; i < N; ++i)
	{
		float sum = 0.0f;

		for (int j = 0; j < N; ++j)
		{
			sum += matrix[i][j];
		}

		vector.push_back(sum);
	}

	return vector;
}

vector<float> getColsSum(t_matrix matrix)
{
	vector<float> vector;

	for (int j = 0; j < N; ++j)
	{
		float sum = 0.0f;

		for (int i = 0; i < N; ++i)
		{
			sum += matrix[i][j];
		}

		vector.push_back(sum);
	}

	return vector;
}

vector<float> getRowsMin(t_matrix matrix)
{
	vector<float> vector;

	for (int i = 0; i < N; ++i)
	{
		float minimum = matrix[i][0];

		for (int j = 0; j < N; ++j)
		{
			minimum = min(minimum, matrix[i][j]);
		}

		vector.push_back(minimum);
	}

	return vector;
}

vector<float> getColsMin(t_matrix matrix)
{
	vector<float> vector;

	for (int j = 0; j < N; ++j)
	{
		float minimum = matrix[0][j];

		for (int i = 0; i < N; ++i)
		{
			minimum = min(minimum, matrix[i][j]);
		}

		vector.push_back(minimum);
	}

	return vector;
}

vector<float> getRowsMax(t_matrix matrix)
{
	vector<float> vector;

	for (int i = 0; i < N; ++i)
	{
		float maximum = matrix[i][0];

		for (int j = 0; j < N; ++j)
		{
			maximum = max(maximum, matrix[i][j]);
		}

		vector.push_back(maximum);
	}

	return vector;
}

vector<float> getColsMax(t_matrix matrix)
{
	vector<float> vector;

	for (int j = 0; j < N; ++j)
	{
		float maximum = matrix[0][j];

		for (int i = 0; i < N; ++i)
		{
			maximum = max(maximum, matrix[i][j]);
		}

		vector.push_back(maximum);
	}

	return vector;
}

vector<float> getRowsAverage(t_matrix matrix)
{
	vector<float> vector;

	for (int i = 0; i < N; ++i)
	{
		float average = 0.0f;

		for (int j = 0; j < N; ++j)
		{
			average += matrix[i][j];
		}

		vector.push_back(average / N);
	}

	return vector;
}

vector<float> getColsAverage(t_matrix matrix)
{
	vector<float> vector;

	for (int j = 0; j < N; ++j)
	{
		float average = 0.0f;

		for (int i = 0; i < N; ++i)
		{
			average += matrix[i][j];
		}

		vector.push_back(average / N);
	}

	return vector;
}

string printVector(vector<float> vector)
{
	ostringstream output;

	output << "vector{ ";

	for (int i = 0; i < vector.size() - 1; ++i)
	{
		output << vector.at(i) << ", ";
	}

	output << vector.back() << " }";

	return output.str();
}