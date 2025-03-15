#include <iostream>
#include <algorithm>

using namespace std;

class Money
{
	long dollars;
	int cents;

public:
	Money() {}
	Money(long d, int c)
	{
		dollars = d;
		cents = c;
	}

	int operator<(const Money& amt) const
	{
		return (dollars < amt.dollars) || ((dollars == amt.dollars) && (cents < amt.cents));
	}

	friend ostream& operator<<(ostream& os, Money& amt)
	{
		os << "$" << amt.dollars << "." << amt.cents;
		return os;
	}
};

int main()
{
	Money mas[] = {
		Money(19, 10),
		Money(99, 99),
		Money(99, 95),
		Money(19, 95),
	};

	sort(begin(mas), end(mas));
	for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); ++i)
	{
		cout << "mas[" << i << "] = " << mas[i] << endl;
	}

	return 0;
}