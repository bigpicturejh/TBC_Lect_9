#include <iostream>
#include<cassert>
using namespace std;

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	Fraction(int num = 0, int den = 1)
		:_numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

	//복사 생성자
	Fraction(const Fraction& fraction)
		:_numerator(fraction._numerator), _denominator(fraction._denominator)
	{
		cout << "Copy constructor is called" << endl; 
	}

	friend ostream& operator <<(ostream& out, const Fraction& f)
	{
		out << f._numerator << " / " << f._denominator << endl;
		return out;
	}

};

Fraction ds()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

int main()
{

	//Fraction frac(3, 5);

	////Fraction fr_copy(frac);
	////Fraction fr_copy=frac; //위에거랑 동일
	//Fraction fr_copy(Fraction(3,10)); //복사생성자가 생성 안됨, 컴파일러가 알아서 Fraction을 없애고 3, 10만 넣어줌

	//cout << frac << " " << fr_copy << endl;


	Fraction result = ds(); //ds함수 안에서 생성자로 만들어지고 result에 초기화할 때 복사생성자를 통해 초기화함
	cout << &result << endl;
	cout << result << endl;
	return 0;
}

