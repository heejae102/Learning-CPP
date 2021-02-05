#include<iostream>
using namespace std; 

class Mother
{
// private 접근 지정자는 자식 클래스에서도 접근이 불가능
// protectd로 선언 시 자식 클래스에서는 접근 가능 
protected:
	int _i;

public:
	Mother(const int &i_in)
		: _i(i_in) 
	{
		std::cout << "Mother Constructor Called" << std::endl;
	}

	void setValue(const int &i_in)
	{
		_i = i_in;
	}

	int getValue()
	{
		return _i;
	}
};

/*

1. 클래스간의 공통적인 부분들을 묶어서 부모 클래스로 만들어 상속하도록 함으로써 코드의 양 ↓
2. 자식클래스는 부모클래스로부터 받은 것들을 전부 사용할 수 있다.
3. 하나의 부모 클래스로 여러 개의 유도 클래스를 만들 수 있다. 

*/

class Child : public Mother
{
private:
	double _d;

public:

	/*
	
	생성자의 존재 이유는 메모리가 할당될 때 
	값을 바로 초기화하기 위함이다. 
	자식 클래스를 생성할 때 부모 클래스가 존재하지 않으므로
	이니셜라이저 리스트에서 부모의 멤버에 접근 불가능 

	자식 클래스가 생성될 때는 부모 클래스의 생성자를 함께 호출 
		
	*/

	// 자식클래스 생성자1.
	//Child(const int &i_in, const double &d_in)
	//	//: _i(i_in), _d(d_in)	// 호출되지 않음.
	//{
	//	Mother::setValue(i_in);
	//	_d = d_in;
	//}

	// 자식클래스 생성자2. 
	// 부모 클래스의 생성자를 호출하여 부모의 멤버를 바로 초기화 가능 
	// 이니셜라이저 리스트를 사용한 더 깔끔한 구조 
	Child(const int &i_in, const double &d_in)
		: Mother(i_in), _d(d_in) {}

	void setValue(const int &i_in, const double &d_in)
	{
		// _i = i_in;
		// 부모 클래스명:: 을 통해 부모 클래스의 멤버에 접근 가능 

		Mother::setValue(i_in);
		_d = d_in;
	}

	void setValue(const double &d_in)
	{
		_d = d_in;
	}

	double getValue()
	{
		return _d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mother(1024);
	cout << mother.getValue() << endl; 

	Child child(128, 256);
	//child.setValue(128);
	//child.Mother::setValue(256);

	cout << child.Mother::getValue() << endl; 
	cout << child.getValue() << endl; 

	return 0; 
}