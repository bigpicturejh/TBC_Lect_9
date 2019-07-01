#include <iostream>
#include<cassert>
using namespace std;

class IntList
{
private:
	int _list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	//void setItem(int index, int value)
	//{
	//	_list[index] = value;
	//}

	//int getItem(int index)
	//{
	//	return _list[index];
	//}

	//int* getList()
	//{
	//	return _list;
	//}

	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);

		return _list[index];
	}

	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);

		return _list[index];
	}

};


int main()
{
	//IntList my_list;
	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl;
	//my_list.getList()[3] = 111;
	//cout << my_list.getList()[3] << endl;

	const IntList my_list;
	//my_list[3] = 10; //const class가 반환타입이기 때문에 값을 변환하는것이 불가능
	cout << my_list[3] << endl; //const class가 반환타입이지만 오버로딩을 통해 값을 읽는것은 const임에도 접근이 가능함


	//pointer를 사용해서 리스트 인자에 []을 사용해서 접근할때 dereferencing을 통해 포인터의 값에 직접 접근해서 바꿔줘야함
	IntList* list = new IntList;
	//list[3] = 993;//non-OK!!!
	(*list)[3]=993; //OK!

	return 0;
}

