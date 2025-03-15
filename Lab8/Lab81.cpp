#include <iostream>

using namespace std;

class Stroka {
	char* str;

public:
	Stroka()
	{
		str = new char[50];
	}

	~Stroka()
	{
		delete[] str;
	}

	Stroka(const char* s) : Stroka()
	{
		memcpy(str, s, strlen(s) + 1);
	}

	Stroka(const Stroka& s) : Stroka()
	{
		memcpy(str, s.str, strlen(s.str) + 1);
	}

	Stroka& operator=(const Stroka& s)
	{
		memcpy(str, s.str, strlen(s.str) + 1);
		return *this;
	}

	Stroka& operator+(const Stroka& s)
	{
		unsigned destlen = strlen(str);
		unsigned srclen = strlen(s.str);

		memcpy(str + destlen, s.str, srclen + 1);

		return *this;
	}

	int operator==(const Stroka& s) const
	{
		const unsigned char* p1 = reinterpret_cast<const unsigned char*>(str);
		const unsigned char* p2 = reinterpret_cast<const unsigned char*>(s.str);

		while (*p1 && *p1 == *p2) ++p1, ++p2;

		return (*p1 > *p2) - (*p2 > *p1);
	}

	friend istream& operator>>(istream& is, Stroka& s)
	{
		is.getline(s.str, 50);
		return is;
	}

	friend ostream& operator<<(ostream& os, const Stroka& s)
	{
		os << s.str;
		return os;
	}

	int dlina()
	{
		const char* end = str;
		while (*end != '\0') ++end;

		return end - str;
	}
};

int main()
{
	Stroka s1("stroka"), s2("");

	cout << "Stroka 1: " << s1 << endl;
	
	cout << "Enter any string: ";
	cin >> s2;
	cout << "Stroka 2: " << s2 << endl;

	return 0;
}