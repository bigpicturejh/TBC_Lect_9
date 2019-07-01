#include <iostream>
using namespace std;

class Digit
{
private:
	int _digit;

public:
	Digit(int digit = 0)
		:_digit(digit)
	{}

	// prefix type
	Digit& operator ++()
	{
		++_digit;
		return *this;
	}

	//postfix type
	Digit operator ++(int) //post형을 구현할 때, 매개변수에 dummy로 int나 다른 값이 들어간다(암기사항)
	{
		Digit temp(_digit); //현재상태의 값을 저장
		++(*this); //현재상태의 값에 1을 더함

		return temp; //현재상태의 값을 반환 
	}
	

	friend ostream& operator <<(ostream& out, const Digit& d)
	{
		out << d._digit;
		return out;
	}
};


int main()
{
	Digit d(10);

	cout << ++d << endl;
	cout << d << endl;

	cout << d++ << endl;
	cout << d << endl;

	return 0;
}

