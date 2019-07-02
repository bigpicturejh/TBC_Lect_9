#include <iostream>
#include<cassert>
using namespace std;

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	Fraction(char) = delete;// 프로그램의 버전이 변경되어 이전에 사용하던 매개변수 혹은 다른 값을 사용하지 못하도록 막아두는 기능

	explicit Fraction(int num = 0, int den = 1)
		:_numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction) //copy constructor
		:_numerator(fraction._numerator), _denominator(fraction._denominator)
	{
		cout << "cpoy constructor is called" << endl;
	}

	friend ostream& operator <<(ostream& out, const Fraction& f)
	{
		out << f._numerator << " / " << f._denominator << endl;
		return out;
	}
};

void ds(Fraction frac)
{
	cout << frac << endl;
}
int main()
{

	Fraction frac(7);
	ds(Fraction(7));
	//ds(7);//위와 같음, 하지만 explicit이 있을 경우 더 엄격하게 매개변수를 입력해줘야 함
	ds(Fraction(7));

	Fraction fract2('c');

	return 0;
}

