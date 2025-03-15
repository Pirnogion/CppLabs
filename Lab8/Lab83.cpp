#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	char fname[50], c;
	fstream fin;

	cout << "Enter an filename: ";
	cin >> fname;
	
	fin.open(fname, ios::in);
	if (!fin)
	{
		cout << "Could not open the file: " << fname;
		return 1;
	}

	cout << "The file was opened!" << endl;
	fin.close();

	return 0;
}