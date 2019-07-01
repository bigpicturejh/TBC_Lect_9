#include <iostream>
using namespace std;

class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	Cents operator -() const
	{
		return Cents(-_cents);
	}
	
	bool operator !() const
	{
		return (_cents == 0) ? true : false;
	}
	friend ostream& operator <<(ostream& out, const Cents& cents)
	{
		out << cents._cents;
		return out;
	}
};


int main()
{
	Cents cents1(6);
	Cents cents2(0);

	//int a = 3;
	//cout << -a << endl;
	//cout << !a << endl;

	//cout << cents1 << endl;
	//cout << -cents1 << endl;
	//cout << -Cents(-10) << endl;

	auto temp = !cents1;

	cout << !cents1 << " " << !cents2 << endl;
	return 0;
}

