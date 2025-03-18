#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	char fname[50], c;
	fstream fin; // Файловый поток

	cout << "Enter an filename: ";
	cin >> fname;
	
	fin.open(fname, ios::in); // Открытие файловго потока на чтение
	if (!fin)
	{
		cout << "Could not open the file: " << fname;
		return 1;
	}

	cout << "The file was opened!" << endl;
	fin.close();

	return 0;
}