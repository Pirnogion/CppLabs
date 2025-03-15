#include <cstdio>
#include <cctype>

#define FILENAME_SIZE 50
#define BUFFER_SIZE 1048576

using namespace std;

int find(const char*, int, const char*, int);
unsigned read(const char*, char*, const unsigned);

int main()
{
	char filename[FILENAME_SIZE];
	char* content = new char[BUFFER_SIZE];

	printf("Enter a filename: ");
	scanf_s("%s", filename, sizeof(filename));
	printf("\n");

	unsigned length = read(filename, content, BUFFER_SIZE * sizeof(char));
	if (length == 0)
	{
		printf("Could not open file: \"%s\".", filename);

		delete[] content;
		return 0;
	}

	printf("Content of the file (%d chars): \n", length);
	for (unsigned i = 0; i < length; ++i)
	{
		putchar(content[i]);
	}
	printf("\n\n");

	int letters = 0, whitespaces = 0;
	for (unsigned i = 0; i < length; ++i)
	{
		if (isspace(content[i])) ++whitespaces; else ++letters;
	}

	printf("Task #1. Letters: %d, whitespaces: %d.\n", letters, whitespaces);

	const char needle[] = "void";
	int pos = find(needle, sizeof(needle)-1, content, length);
	printf("Task #2. Position of \"%s\" is %d.\n", needle, pos);

	delete[] content;
	return 0;
}

int find(const char* needle, int nlength, const char* haystack, int hlength)
{
	if (needle == nullptr || haystack == nullptr || nlength <= 0 || hlength <= 0)
	{
		return -1;
	}

	for (int i = 0, origin = 0, length = 0; i < hlength; ++i)
	{
		if (haystack[i] == needle[length])
		{
			if (length++ == 0) origin = i;
			if (length == nlength) return origin;
		}
		else
		{
			length = 0;
		}
	}

	return -1;
}

unsigned read(const char* filename, char* buffer, const unsigned length)
{
	if (filename == nullptr || buffer == nullptr || length <= 0)
	{
		return 0;
	}

	FILE* in;
	if (fopen_s(&in, filename, "r") != 0)
	{
		return 0;
	}

	unsigned int offset = 0;
	while (!feof(in) && offset != length)
	{
		buffer[offset++] = getc(in);
	}

	fclose(in);

	return offset;
}