#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
	char fname[50], c;

	cout << "Enter an input filename: ";
	cin >> fname;
	ifstream ifs(fname);
	if (!ifs)
	{
		cout << "Could not open the file: " << fname << ".";
		return 1;
	}

	cout << "Enter an output filename: ";
	cin >> fname;
	ofstream ofs(fname);
	if (!ofs)
	{
		cout << "Could not open the file: " << fname << ".";
		return 1;
	}

	cout << "Copying... ";

	while (ifs && ofs)
	{
		ifs.get(c);
		c = toupper(c);
		ofs.put(c);
	}

	cout << "Done!" << endl;

	ifs.close();
	ofs.close();

	return 0;
}