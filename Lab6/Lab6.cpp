#include <iostream>
#include <cstring>

using namespace std;

class Stroka {
	char* str;

	public:
		Stroka(const char*);
		Stroka();
		~Stroka();
		Stroka(const Stroka&);
		Stroka& operator=(const Stroka&);
		Stroka& operator+(const Stroka&);
		int operator==(const Stroka&) const;
		int dlina();
		void vvod();
		void vyvod();
};

Stroka::Stroka()
{
	str = new char[50];
}

Stroka::~Stroka()
{
	delete[] str;
}

Stroka::Stroka(const char* s) : Stroka()
{
	memcpy(str, s, strlen(s) + 1);
}

Stroka::Stroka(const Stroka& s) : Stroka()
{
	memcpy(str, s.str, strlen(s.str) + 1);
}

Stroka& Stroka::operator=(const Stroka& s)
{
	memcpy(str, s.str, strlen(s.str) + 1);
	return *this;
}

Stroka& Stroka::operator+(const Stroka& s)
{
	unsigned destlen = strlen(str);
	unsigned srclen = strlen(s.str);

	memcpy(str + destlen, s.str, srclen + 1);

	return *this;
}

int Stroka::operator==(const Stroka& s) const
{
	const unsigned char* p1 = reinterpret_cast<const unsigned char*>(str);
	const unsigned char* p2 = reinterpret_cast<const unsigned char*>(s.str);

	while (*p1 && *p1 == *p2) ++p1, ++p2;

	return (*p1 > *p2) - (*p2 > *p1);
}

int Stroka::dlina()
{
	const char* end = str;
	while (*end != '\0') ++end;

	return end - str;
}

void Stroka::vvod()
{
	cin.getline(str, 50);
}

void Stroka::vyvod()
{
	cout << str;
}

int main()
{
	Stroka s1("qwert"), s3, s4(s1), s5;

	cout << "Enter any string: "; s3.vvod();
	s3 = "asdfg";
	cout << "s3 is \""; s3.vyvod(); cout << "\"" << endl;
	s5 = s1 + s3 + s4;
	cout << "Length of s5 is " << s5.dlina() << endl;
	cout << "s5 is \""; s5.vyvod(); cout << "\"" << endl;
	if (s1 == s5) cout << "s1 equals to s5" << endl;
	else if (s1 == s4) cout << "s1 equals to s4" << endl;

	return 0;
}