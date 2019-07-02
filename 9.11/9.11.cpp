#include <iostream>
#include<cassert>
using namespace std;

class Mystring
{
private:

public:
	char* _data = nullptr;
	int _length = 0;

	Mystring(const char* source = "")
	{
		assert(source); //문자열이 비어있지 않은지 확인

		_length = strlen(source) + 1;
		_data = new char[_length];

		for (unsigned int i = 0; i < _length; ++i)
		{
			_data[i] = source[i];
		}
		_data[_length - 1] = '\0';
	}

	//깊은복사: 포인터 값만 복사하는것이 아니라 포인터가 가르키는 위치의 데이터도 복사하는것
	Mystring(const Mystring& source)
	{
		cout << "Copy constructor" << endl;

		_length = source._length;

		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; ++i)
			{
				_data[i] = source._data[i];
			}
		}
		else
			_data = nullptr;
	}

	Mystring& operator = (const Mystring& source)
	{

		//얕은복사
		this->_data = source._data;
		this->_length = source._length;


		//깊은복사
		cout << "Assignment operator" << endl;

		if (this == &source) //prevent self-assignment (불필요하게 자기 자신을 대입하는 경우 프로그램을 끝냄)
			return *this;

		delete[] _data;
		_data = source._data;

		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; ++i)
			{
				_data[i] = source._data[i];
			}
		}
		else
			_data = nullptr;

		return *this;

	}

	~Mystring()
	{
		delete[] _data;
	}

	char* getString() { return _data; }
	int getLength() { return _length; }
};



int main()
{
	Mystring hello("Hello");

	//cout << (int*)hello._data << endl;
	//cout << hello.getString() << endl;

	//{
	//	Mystring copy = hello;
	//	cout << (int*)copy._data << endl;
	//	cout << copy.getString()<< endl;
	//}

	//cout << hello.getString() << endl; //위 {}에서 복사된 포인터의 값이 소멸자로 인해 삭제되어 값을 찾을 수 없는 오류를 발생시킴

	Mystring str1 = hello; //복사 생성자가 호출이 됨
	Mystring str2 ; 
	str2 = hello; // 대입생성자가 호출이 됨
	return 0;
}

