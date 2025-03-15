#include <cstdio>
#include <cctype>

#define BUFFER_SIZE 1048576

using namespace std;

int main()
{	
	const char* input = "files/lab52i.txt";
	const char* output = "files/lab52o.txt";

	char* buffer = new char[BUFFER_SIZE];

	FILE* in;
	if (fopen_s(&in, input, "r") != 0)
	{
		printf("Could not open required files.");

		delete[] buffer;
		return 0;
	}

	FILE* out;
	if (fopen_s(&out, output, "w") != 0)
	{
		printf("Could not open required files.");

		fclose(in);
		delete[] buffer;
		return 0;
	}

	bool isPageNumber = true;
	unsigned offset = 0;

	while (!feof(in))
	{
		char ch = getc(in);

		if (isPageNumber)
		{
			if (isdigit(ch))
			{
				buffer[offset++] = ch;
			}
			else if (offset != 0 && (ch == '\n' || ch == '\r'))
			{
				isPageNumber = false;
			}
		}
		else
		{
			if (ch == '\f')
			{
				putc('\n', out);

				for (int i = 0; i < offset; ++i)
				{
					putc(buffer[i], out);
				}

				putc('\f', out);
				putc('\n', out);

				isPageNumber = true;
				offset = 0;
			}
			else
			{
				putc(ch, out);
			}
		}
	}

	fclose(in);
	fclose(out);

	delete[] buffer;
	return 0;
}