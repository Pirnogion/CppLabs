#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

unsigned encode(const char*, const char*, const char*, const int);

int main(int argc, char* argv[]) // ИСпользуем аргументы программы (argc - кол-во аргументов, argv - массив аргументов)
{
	if (argc < 3)
	{
		printf("Insufficient arguments!");
		return 1;
	}

	const char* key = argv[1]; // Секретный ключ взятый из аргументов
	const int length = strlen(key);

	const char* input = argv[2]; // Название файла, который нужно шифровать

	printf("Key is \"%s\".\n", key);
	printf("File is \"%s\".\n", input);

	const char* output1 = "files/lab53o1.txt";
	const char* output2 = "files/lab53o2.txt";

	if (!encode(input, output1, key, length))
	{
		printf("Could not open required files.");
		return 1;
	}

	if (!encode(output1, output2, key, length))
	{
		printf("Could not open required files.");
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

	FILE* in;
	if (fopen_s(&in, input, "rb") != 0)
	{
		return 0;
	}

	FILE* out;
	if (fopen_s(&out, output, "wb") != 0)
	{
		fclose(in);
		return 0;
	}

	unsigned offset = 0;
	int ch;
	while ((ch = getc(in)) != EOF) // Конструкция для чтения файла и чтобы не читать лишний байт в конце файла
	{
		char pt = key[offset++ % length];
		putc(ch^pt, out); // Кладем зашифрованный символ в выходной файл
	}

	fclose(in);
	fclose(out);

	return 1;
}