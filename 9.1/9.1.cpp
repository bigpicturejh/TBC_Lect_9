#include <iostream>
using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents=0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	//friend Cents operator + (const Cents& c1, const Cents& c2)
	//{
	//	return Cents(c1.getCents() + c2.getCents());
	//}


	//멤버함수로만 지정해야하는 연산자 overloading : =, [], (), ->
	 Cents operator + (const Cents& c2)
	{
		return Cents(this->_cents + c2._cents);
	}
};

//void add(const Cents& c1, const Cents& c2, Cents &c_out)
//{
//	c_out.getCents() = c1.getCents() + c2.getCents();
//}

//매개변수로 결과값을 받기보다 클래스 타입 리턴으로 결과를 받는 방법이 현재 경향
//Cents operator + (const Cents& c1, const Cents& c2 ) 
//{
//	return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(13);
	Cents cents2(14);
	
	/*Cents sum;
	add(cents1, cents2, sum);*/

	/*cout << sum.getCents() << endl;*/
	//cout << add(cents1, cents2).getCents() << endl;
	cout << (cents1 + cents2+ Cents(10)+Cents(2)).getCents() << endl;

	return 0;




	///////////////////아래 연산자는 연산자 overloading이 안됨!!///////////////////
	// ?: "" sizeof . .*
	// ^ <- 이 연산자는 우선순위가 굉장히 낮으므로 ()로 표현해줘야 함
}

