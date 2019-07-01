#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	friend bool operator ==(const Cents& c1, const Cents& c2)
	{
		return c1._cents == c2._cents;
	}

	friend bool operator !=(const Cents& c1, const Cents& c2)
	{
		return c1._cents == c2._cents;
	}

	friend bool operator <(const Cents& c1, const Cents& c2) //sort를 구현할때는 좌변항이 더 작은지 물어보는 연산자로 오버로딩을 해줘야함
	{
		return c1._cents < c2._cents;
	}

	friend ostream& operator <<(ostream& out, const Cents& cents)
	{
		out << cents._cents;
		return out;
	}
};


int main()
{

	//Cents cents1(5);
	//Cents cents2(5);

	/*if (cents1 == cents2)
	{
		cout << "Equal" << endl;
	}
	cout << boolalpha;*/

	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
	{
		arr[i].getCents() = i;
	}
	random_shuffle(begin(arr), end(arr));

	for (auto& idx : arr)
		cout << idx << " ";
	cout << endl;

	sort(begin(arr), end(arr));
	for (auto& idx : arr)
		cout << idx << " ";


	return 0;
}

