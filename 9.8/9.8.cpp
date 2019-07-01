#include <iostream>
using namespace std;


class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	void setCents(int cents) { _cents = cents; }

	operator int()
	{
		cout << "cast here" << endl;
		return _cents;
	}

};

class Dollar
{
private:
	int _dollars=0;


public:
	Dollar(const int& input): _dollars(input){}

	operator Cents()
	{
		return Cents(_dollars*100);
	}
};
void printInt(const int& value)
{
	cout << value << endl;

}


int main()
{
	/*Cents cents(7);
	int value = int(cents);
	value = int(cents);
	value = static_cast<int>(cents);

	printInt(cents);*/

	Dollar dol(20);
	Cents cents = dol;
	printInt(cents);

	return 0;
}

