#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

unsigned length1(const char*);
unsigned length2(const char*);
unsigned length3(const char*);
void copy(char*, const char*);
int compare(const char*, const char*);
void concat(char*, const char*);

void main()
{
	cout << "[ STDLIB ]" << endl << endl;

	const char str1[] = "Oleg", str2[] = "Ivanovich";
	char dest1[14]{ '\0' }, cpy1[5]{ '\0' }; // Инициализация пустых строк нулями
	char dest2[14]{ '\0' }, cpy2[5]{ '\0' };

	cout << "strlen(\"" << str1 << "\") => " << strlen(str1) << endl;

	strcat_s(dest1, str1);
	strcat_s(dest1, str2);

	cout << "strcat(<dest1>, \"" << str1 << "\"), strcat(<dest1>, \"" << str2 << "\") => \"" << dest1 << "\"" << endl;

	strcpy_s(cpy1, str1);

	cout << "strcpy(<cpy1>, \"" << str1 << "\") => \"" << cpy1 << "\"" << endl;

	cout << "strcmp(\"Hello\", \"World\") => " << strcmp("Hello", "World") << endl;
	cout << "strcmp(\"World\", \"Hello\") => " << strcmp("World", "Hello") << endl;
	cout << "strcmp(\"Hello\", \"Hello\") => " << strcmp("Hello", "Hello") << endl;

	cout << endl << "[ CUSTOM (stack) ]" << endl << endl;

	cout << "length1(\"" << str1 << "\") => " << length1(str1) << endl;
	cout << "length2(\"" << str1 << "\") => " << length2(str1) << endl;
	cout << "length3(\"" << str1 << "\") => " << length3(str1) << endl;

	copy(cpy2, str1);

	cout << "copy(<cpy2>, \"" << str1 << "\") => " << cpy2 << endl;

	concat(dest2, str1);
	concat(dest2, str2);

	cout << "concat(<dest2>, \"" << str1 << "\"), concat(<dest2>, \"" << str2 << "\") => \"" << dest2 << "\"" << endl;

	cout << "compare(\"" << str1 << "\", \"" << str2 << "\") => " << compare(str1, str2) << endl;
	cout << "compare(\"" << str2 << "\", \"" << str1 << "\") => " << compare(str2, str1) << endl;

	cout << endl << "[ CUSTOM (malloc) ]" << endl << endl;

	char* rhstr1 = static_cast<char*>(malloc(sizeof(char) * 5)); char* rhstr2 = static_cast<char*>(malloc(sizeof(char) * 10)); // Выделение памяти
	char* rhdest1 = static_cast<char*>(malloc(sizeof(char) * 14)); char* rhcpy1 = static_cast<char*>(malloc(sizeof(char) * 5)); // static_cast - преобразование типов с сохранением значения, если это возможно, это нужно так как malloc возвращает void*
	if (rhstr1 == nullptr || rhstr2 == nullptr || rhdest1 == nullptr || rhcpy1 == nullptr) // Проверяем что память выделена
	{
		cerr << "Could not allocate memory!" << endl;
		abort();
	}

	memcpy(rhstr1, "Ivan", sizeof(char) * 5); memcpy(rhstr2, "Ivanovich", sizeof(char) * 10); // sizeof размер типа в байтах
	memset(rhdest1, '\0', sizeof(char) * 14); memset(rhcpy1, '\0', sizeof(char) * 5);

	cout << "length1(\"" << rhstr1 << "\") => " << length1(rhstr1) << endl;
	cout << "length2(\"" << rhstr1 << "\") => " << length2(rhstr1) << endl;
	cout << "length3(\"" << rhstr1 << "\") => " << length3(rhstr1) << endl;

	copy(rhcpy1, rhstr1);

	cout << "copy(<rhcpy1>, \"" << rhstr1 << "\") => " << rhcpy1 << endl;

	concat(rhdest1, rhstr1);
	concat(rhdest1, rhstr2);

	cout << "concat(<rhdest1>, \"" << rhstr1 << "\"), concat(<rhdest1>, \"" << rhstr2 << "\") => \"" << rhdest1 << "\"" << endl;

	cout << "compare(\"" << rhstr1 << "\", \"" << rhstr2 << "\") => " << compare(rhstr1, rhstr2) << endl;
	cout << "compare(\"" << rhstr2 << "\", \"" << rhstr1 << "\") => " << compare(rhstr2, rhstr1) << endl;

	free(rhstr1); // Освобождение памяти
	free(rhstr2);
	free(rhdest1);
	free(rhcpy1);

	cout << endl << "[ CUSTOM (calloc) ]" << endl << endl;

	// calloc также выделяет динамическую память, но инициализирует ее нулями
	char* crhstr1 = static_cast<char*>(calloc(5, sizeof(char))); char* crhstr2 = static_cast<char*>(calloc(10, sizeof(char)));
	char* crhdest1 = static_cast<char*>(calloc(14, sizeof(char))); char* crhcpy1 = static_cast<char*>(calloc(5, sizeof(char)));
	if (crhstr1 == nullptr || crhstr2 == nullptr || crhdest1 == nullptr || crhcpy1 == nullptr)
	{
		cerr << "Could not allocate memory!" << endl;
		abort();
	}

	memcpy(crhstr1, "Peta", sizeof(char) * 5); memcpy(crhstr2, "Ivanovich", sizeof(char) * 10);

	cout << "length1(\"" << crhstr1 << "\") => " << length1(crhstr1) << endl;
	cout << "length2(\"" << crhstr1 << "\") => " << length2(crhstr1) << endl;
	cout << "length3(\"" << crhstr1 << "\") => " << length3(crhstr1) << endl;

	copy(crhcpy1, crhstr1);

	cout << "copy(<crhcpy1>, \"" << crhstr1 << "\") => " << crhcpy1 << endl;

	concat(crhdest1, crhstr1);
	concat(crhdest1, crhstr2);

	cout << "concat(<crhdest1>, \"" << crhstr1 << "\"), concat(<crhdest1>, \"" << crhstr2 << "\") => \"" << crhdest1 << "\"" << endl;

	cout << "compare(\"" << crhstr1 << "\", \"" << crhstr2 << "\") => " << compare(crhstr1, crhstr2) << endl;
	cout << "compare(\"" << crhstr2 << "\", \"" << crhstr1 << "\") => " << compare(crhstr2, crhstr1) << endl;

	free(crhstr1);
	free(crhstr2);
	free(crhdest1);
	free(crhcpy1);

	cout << endl << "[ CUSTOM (array of strings) ]" << endl << endl;

	const char* astr1[] { "Ivan", "Natasha", "Anton" };
	const char* astr2[] { "Petrovich", "Semyonovna", "Ivanovich" };

	// С++ оператор для выделения памяти (работает с ООП), с возможностью инициализации заданным значением, тоже может возвратить ошибку\исключение, но здесь она не проверяется
	char* adest1[] = { new char[14] {'\0'}, new char[18] {'\0'}, new char[15] {'\0'} };
	char* acpy1[] = { new char[5] {'\0'}, new char[8] {'\0'}, new char[6] {'\0'} };

	for (int i = 0; i < 3; ++i)
	{
		cout << "length1(\"" << astr1[i] << "\") = " << length1(astr1[i]) << endl;
		cout << "length2(\"" << astr1[i] << "\") = " << length2(astr1[i]) << endl;
		cout << "length3(\"" << astr1[i] << "\") = " << length3(astr1[i]) << endl;
		
		concat(adest1[i], astr1[i]);
		concat(adest1[i], astr2[i]);
		
		cout << "concat(<adest1[i]>, \"" << astr1[i] << "\"), concat(<adest1[i]>, \"" << astr2[i] << "\") => \"" << adest1[i] << "\"" << endl;

		copy(acpy1[i], astr1[i]);

		cout << "copy(<acpy1[i]>, \"" << astr1[i] << "\") => \"" << acpy1[i] << "\"" << endl;

		cout << "compare(\"" << astr1[i] << "\", \"" << astr2[i] << "\") => " << compare(astr1[i], astr2[i]) << endl;
		cout << "compare(\"" << astr2[i] << "\", \"" << astr1[i] << "\") => " << compare(astr2[i], astr1[i]) << endl;

		cout << endl;
	}

	for (int i = 0; i < 3; ++i)
	{
		delete[] adest1[i]; // Удаляет массив выделенной памяти
		delete[] acpy1[i];
	}
}

unsigned length1(const char* str)
{
	return strlen(str);
}

unsigned length2(const char* str)
{
	unsigned length = 0;
	while (str[length] != '\0') ++length;

	return length;
}

unsigned length3(const char* start)
{
	const char* end = start;
	while (*end != '\0') ++end;

	return end - start;
}

void copy(char* dest, const char* src)
{
	memcpy(dest, src, strlen(src)+1);
}

int compare(const char* str1, const char* str2)
{
	const unsigned char* p1 = reinterpret_cast<const unsigned char*>(str1);
	const unsigned char* p2 = reinterpret_cast<const unsigned char*>(str2);

	while (*p1 && *p1 == *p2) ++p1, ++p2;

	return (*p1 > *p2) - (*p2 > *p1);
}

void concat(char* dest, const char* src)
{
	unsigned destlen = strlen(dest);
	unsigned srclen = strlen(src);

	memcpy(dest+destlen, src, srclen+1);
}