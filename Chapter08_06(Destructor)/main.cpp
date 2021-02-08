#include<iostream>
using namespace std; 

/*

<소멸자> Destructor 

~클래스명 형식으로 파라미터와 리턴타입이 없는 특수 멤버함수 

소멸자는 instance가 메모리에서 해제될 때 내부에서 자동으로 호출.
동적할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 메모리가 
해제되지 않기 때문에 delete으로 메모리를 해제할 때 소멸자가 호출된다. 

멤버의 초기화에 사용되는 생성자와 달리 소멸자는 멤버의 해제(delete)에 주로 사용 


*/

class IntArray
{
private:
	int *_arr = nullptr;
	int _length = 0; 

public:
	IntArray(const int &length_in)
	{
		_length = length_in;
		_arr = new int[_length];

		cout << "Constructor" << endl; 
	}

	~IntArray()
	{
		//nullptr을 delete하려고 해도 문제가 생기기때문에 예외처리 
		if(_arr != nullptr) delete[] _arr;
	}

	int size() { return _length; }
};

class Simple
{
private:
	int _id;

public:
	Simple(const int &id_in) : _id(id_in) 
	{
		cout << "Constructor " << _id << endl; 
	}

	~Simple()
	{
		cout << "Destructor " << _id << endl; 
	}
};

int main()
{
	//일반 변수 선언 시, 먼저 선언된 변수의 생성자가 먼저 호출 
	// 나중에 선언된 변수의 소멸자가 먼저 호출(스택으로 쌓아서 LIFO으로 메모리를 해제) 
	//Simple s1(0);

	//Simple *s1 = new Simple(0);
	//Simple s2(1);
	//delete s1; 

	while (true)
	{
		IntArray my_arr(1000);
	}

	return 0;
}