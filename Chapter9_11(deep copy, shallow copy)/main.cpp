#include<iostream>
#include<cassert>
using namespace std; 

/*

<대입 연산자 오버로딩>

깊은 복사 vs 얕은 복사

얕은 복사 : 데이터를 그대로 복사한다. 디폴트 복사 생성자의 작동방식. 
           값 형식의 데이터뿐 아니라 참조 형식의 데이터도 그대로 복사하기 때문에 
		   어떠한 메모리를 가리키는 참조 값을 복사하면 해당 메모리를 똑같이 가리키는 참조 값이 복사된다.

깊은 복사 : 참조 형식의 데이터가 있는 경우, 해당 참조 값이 가리키는 메모리의 공간만큼 메모리를 할당하여 
           새로운 메모리 공간에 해당 메모리를 생성하고, 메모리 내의 데이터를 그대로 복사하는 형식. 
		   즉, 참조 형식이 가리키는 데이터와 동일한 데이터를 새로운 메모리로 할당하는 방식. 

*/

class MyString
{
public:
	char *_data = nullptr;
	int _length = 0;

public:
	MyString(const char *source = "")
	{
		assert(source);

		// 문자열의 NULL 캐릭터가 들어갈 공간을 위해 +1 
		_length = std::strlen(source) + 1;
		
		// 해당 글자 수만큼 동적할당 
		_data = new char[_length];

		// 동적할당한 메모리에 실제적인 char 값 복사 
		for (int i = 0; i < _length; i++)
		{
			_data[i] = source[i];
		}

		_data[_length - 1] = '\0';
	}

	// 만약 복사 생성자를 구현 할 시간이 없는데, 얕은 복사는 
	// 막아야 하는 상황일 경우 복사 생성자가 호출되지 않도록 아예 막아버리는 방법도 있다.
	// 하지만, 모범적으로 복사생성자를 잘 구현해두도록 하자. 
	//MyString(const MyString &source) = delete;

	// 복사생성자 (깊은 복사)
	MyString(const MyString &source)
	{
		cout << "Copy Constructor Called" << endl; 

		_length = source._length;

		// source 내의 데이터가 null 데이터가 아닌 경우 메모리를 할당하여 복사 
		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; i++)
				_data[i] = source._data[i];
		}
		else _data = nullptr;
	}

	MyString& operator = (const MyString &source)
	{
		cout << "Assignment Operator Called" << endl; 

		// 자기자신을 대입하는 경우 방지 
		if (this == &source) // prevent self-assignment
			return *this;

		// 복사 생성자가 호출될 경우 객체를 새로 생성하는 상황이므로 상관없지만,
		// 대입 연산이 일어나는 경우 이미 메모리를 가지고 있을 가능성이 있으므로,
		// 이미 가지고 있는 메모리는 delete 하도록 한다. 
		delete[] _data;

		_length = source._length;

		// source 내의 데이터가 null 데이터가 아닌 경우 메모리를 할당하여 복사 
		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; i++)
				_data[i] = source._data[i];
		}
		else _data = nullptr;

		return *this;
	}

	~MyString()
	{
		delete[] _data;
	}

	char* getString() { return _data; }
	int getLength() { return _length; }
};

int main()
{
	MyString hello("Hello");

	// data의 주소 출력 
	cout << (int*)hello._data << endl;
	cout << hello.getString() << endl;

	{	
		/*
		
		Copy Initialization 동작으로 복사 생성자 호출 
		(초기화 시 같은 타입의 객체를 대입하는 경우로, 일반 대입 시에는 대입 연산)
		
		현재 해당 객체는 복사 생성자가 따로 구현되어 있지 않으므로,
		복사 생성자 호출 시 디폴트 복사 생성자가 호출된다. 
		
		디폴트 복사 생성자는 그저 값을 복사하는 역할만 하기 때문에, 
		객체 내에 참조 값이 있을 경우, 해당 메모리가 통째로 복사되는 것이 아니라,
		해당 메모리를 참조하는 값을 그대로 복사하는 것 뿐이다. 
		(즉, 같은 메모리를 기존의 포인터와 복사된 포인터가 함께 참조하는 꼴이 된다.)

		따라서, 이후 어느 한 쪽의 객체가 삭제되는 등의 이유로 해당 메모리가 사라질 경우, 
		남아있는 포인터는 삭제된 메모리를 계속 참조하게 되므로 쓰레기 값을 가리켜 오류가 발생한다.
		
		*/

		// 복사 생성자를 통해 hello 객체를 복사한 뒤, 스코프를 벗어나 메모리가 삭제되었으므로,
		// 스코프 밖에서 해당 메모리에 접근하려고 하면 이미 삭제된 메모리라 오류가 발생. 
		MyString copy = hello;

		cout << (int*)copy._data << endl; 
		cout << copy.getString() << endl; 
	}

	cout << hello.getString() << endl;


	//----------------------------------------------------------------------------//


	// MyString str1(hello) 와 동작 방식이 같음.
	MyString str1 = hello;	// Copy Constructor 호출 

	MyString str2;
	str2 = hello;			// Assignment Operator 호출 

	return 0;
}