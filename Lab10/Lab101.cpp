#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class List
{
protected:
	struct Node
	{
		const T& value;
		Node* next = nullptr;
	};

	size_t size = 0;

	Node* first = nullptr;
	Node* last = nullptr;

public:
	~List()
	{
		Node* current = first;
		while (current)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void append(const T& value)
	{
		Node* node = new Node{ value };

		if (size == 0) last = first = node;
		else last = last->next = node;

		++size;
	}

	void remove(const T& value)
	{
		if (size == 0) return;

		Node* previous = nullptr;
		Node* current = first;
		while (current && current->value != value)
		{
			previous = current;
			current = current->next;
		}

		if (!current) return;

		if (!previous) {
			first = current->next;
			if (!first) last = nullptr;
		}
		else if (!current->next)
		{
			last = previous;
			previous->next = nullptr;
		}
		else
		{
			previous->next = current->next;
		}

		--size;

		delete current;
	}

	const T* find(const T& value) const
	{
		Node* current = first;
		while (current && current->value != value)
		{			
			current = current->next;
		}

		return (current) ? &current->value : nullptr;
	}

	friend ostream& operator<<(ostream& os, const List& list)
	{
		os << "[ " << endl;

		Node* current = list.first;
		while (current)
		{
			os << "\t" << current->value << " " << endl;
			current = current->next;
		}

		os << "]";

		return os;
	}
};

struct Bus
{
	string id;
	string driver;
	string track;

	friend ostream& operator<<(ostream& os, const Bus& bus)
	{
		os << "{ id: \"" << bus.id << "\", driver: \"" << bus.driver << "\", track: \"" << bus.track << "\" }";
		return os;
	}

	int operator !=(const Bus& bus) const
	{
		return id != bus.id;
	}
};

class Dispatcher
{
protected:
	List<Bus> inner, outer;

public:
	Dispatcher(Bus buses[], size_t length)
	{
		for(size_t i = 0; i < length; ++i) inner.append(buses[i]);
	}

	void sendBus(const Bus& bus)
	{
		const Bus* found = inner.find(bus);
		if (found)
		{
			inner.remove(*found);
			outer.append(*found);
		}
	}

	void acceptBus(const Bus& bus)
	{
		const Bus* found = outer.find(bus);
		if (found)
		{
			outer.remove(*found);
			inner.append(*found);
		}
	}

	void printInner()
	{
		cout << "Inner: " << inner << endl;
	}

	void printOuter()
	{
		cout << "Outer: " << outer << endl;
	}
};

int main()
{
	Bus buses[] {
		{ "AZ492I", "Vesnuxin O. G.",  "AMZU-956" },
		{ "AT211O", "Trubnoi A. S.",   "AMZU-312" },
		{ "JS498I", "Vesnuxin I. I.",  "BKJQ-103" },
		{ "PO752V", "Stolarov P. V.",  "PPPO-554" },
		{ "AA791K", "Goncharov G. G.", "FCGK-132" },
		{ "AB652F", "Stupkin E. S.",   "PKFS-217" },
		{ "HG917Z", "Ytugova S. O.",   "PEVK-486" },
		{ "BK452J", "Telepatov I. S.", "QVNS-385" },
	};

	Dispatcher dispatcher(buses, sizeof(buses) / sizeof(Bus));

	string command;

	cout << "Enter any command: " << endl;
	while (true)
	{
		cout << "> "; cin >> command;

		if (command == "print")
		{
			bool hasArgument = cin.peek() == 32;
			if (hasArgument)
			{
				cin >> command;
				if (command == "inner") dispatcher.printInner();
				else if (command == "outer") dispatcher.printOuter();
				else if (command == "all") for (size_t i = 0; i < sizeof(buses) / sizeof(Bus); ++i) cout << buses[i] << endl;
				else cout << "Unknown argument! Use: 'inner', 'outer'." << endl;
			}
			else
			{
				cout << "Invalid argument! Use: 'all', 'inner', 'outer'." << endl;
			}
		}
		else if (command == "send")
		{
			bool hasArgument = cin.peek() == 32;
			if (hasArgument)
			{
				cin >> command;

				bool wasSent = false;
				for (size_t i = 0; i < sizeof(buses) / sizeof(Bus); ++i)
				{
					if (command == buses[i].id)
					{
						dispatcher.sendBus(buses[i]);
						wasSent = true;
						cout << "Bus '" << buses[i].id << "' was sent." << endl;
						break;
					}
				}

				if (!wasSent) cout << "The bus id not found!" << endl;
			}
			else
			{
				cout << "Invalid argument! Use 'send [id]'." << endl;
			}
		}
		else if (command == "accept")
		{
			bool hasArgument = cin.peek() == 32;
			if (hasArgument)
			{
				cin >> command;

				bool wasAccepted = false;
				for (size_t i = 0; i < sizeof(buses) / sizeof(Bus); ++i)
				{
					if (command == buses[i].id)
					{
						dispatcher.acceptBus(buses[i]);
						wasAccepted = true;
						cout << "Bus '" << buses[i].id << "' was accepted." << endl;
						break;
					}
				}

				if (!wasAccepted) cout << "The bus id not found!" << endl;
			}
			else
			{
				cout << "Invalid argument! Use 'accept [id]'." << endl;
			}
		}
		else if (command == "help")
		{
			cout << "Available commands: - print [all|inner|outer]; - send [id]; - accept [id]; - help; -bye|exit;" << endl;
		}
		else if (command == "bye" || command == "exit")
		{
			cout << "Bye!" << endl;
			break;
		}
		else
		{
			cout << "Unknown command! Use 'help'." << endl;
		}
	}

	return 0;
}