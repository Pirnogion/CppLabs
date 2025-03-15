#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const char fname[] = "files/Lab84.txt";
	
	ofstream ofs(fname, ios::out | ios::_Noreplace);
	if (!ofs)
	{
		cout << "The file already exsists!";
		return 1;
	}

	ofs << "STRING";
	ofs.close();

	fstream fs;
	fs.open(fname, ios::out | ios::ate);
	if (!fs)
	{
		cout << "Could not open the file!";
		return 1;
	}

	fs << "APPEND";
	fs.close();

	fstream ifs(fname);
	if (!ifs)
	{
		cout << "Could not open the file!";
		return 1;
	}

	cout << "Content of the file: " << endl;
	char line[80];
	ifs.getline(line, sizeof(line));
	cout << line;
	ifs.close();

	return 0;
}