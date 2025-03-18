#include <iostream>
#include <fstream>

using namespace std;

unsigned encode(const char*, const char*, const char*, const int);

int main()
{
	const char* key = "kashalot"; // СЕКРЕТНЫЙ ключ
	const int length = strlen(key);

	const char* input = "files/Lab85i.txt";

	cout << "Key is \"" << key << "\"." << endl;
	cout << "File is \"" << input << "\"." << endl;

	const char* output1 = "files/Lab85o1.txt";
	const char* output2 = "files/Lab85o2.txt";

	if (!encode(input, output1, key, length))
	{
		cout << "Could not open required files.";
		return 1;
	}

	if (!encode(output1, output2, key, length))
	{
		cout << "Could not open required files.";
		return 1;
	}

	return 0;
}

unsigned encode(const char* input, const char* output, const char* key, const int length)
{
	if (input == nullptr || output == nullptr || key == nullptr || length <= 0)
	{
		return 0;
	}

	ifstream in(input, ios::in | ios::binary);
	if (!in)
	{
		return 0;
	}

	ofstream out(output, ios::out | ios::binary);
	if (!out)
	{
		in.close();
		return 0;
	}

	unsigned offset = 0;
	char ch;
	while (in.get(ch))
	{
		char pt = key[offset++ % length]; // Кодируем символы
		out << static_cast<char>(ch ^ pt); // ch ^ pt - будет типа int и на вывод попадет мусор, поэтому изменяем тип с сохранением значения
	}

	in.close();
	out.close();

	return 1;
}