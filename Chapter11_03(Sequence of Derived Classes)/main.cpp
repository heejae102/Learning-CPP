#include<iostream>
using namespace std; 

/*

<유도된 클래스들의 생성 순서>

유도 클래스는 부모 클래스의 멤버를 모두 사용할 수 있다.

따라서 유도 클래스 생성 시, 부모 클래스를 생성하여 
부모 클래스 내 멤버를 모두 초기화시킨 후에(부모 클래스 생성자 호출),
유도 클래스의 생성자를 호출하여 초기화시킨다. 

따라서 유도 클래스의 이니셜라이저 리스트 작성 시, 
아직 부모 클래스가 초기화되기 이전 상태이므로 부모의 멤버 값을
가져다가 사용할 수 없다. (생성자의 바디에서는 가능) 

대신 이니셜라이저 리스트에서 부모의 생성자를 호출하여 
멤버 값을 초기화하는 것은 가능한데, 원래 유도 클래스의 이니셜라이저 리스트는 
부모의 생성자를 호출하지 않아도 부모의 디폴트 생성자를 호출하는 구조로 이루어져 있다. 
(디폴트 생성자처럼 보이지 않는 채로 작동) 


//===============================================================================//


여러 단계의 상속이 이루어진 구조의 생성에서는 
가장 기본 단계의 클래스부터 순차적으로 생성자가 호출된다.

A -> B -> C 단계로 상속된 구조에서 (A가 가장 상위 클래스)

A constructor called.
B constructor called.
C constructor called.

순서로 생성자가 호출된다. 

*/

class Mother
{
public:
	int _i;

	Mother(const int &i_in = 0)
		: _i(i_in)
	{
		cout << "Mother Constructor Called" << endl;
	}

};

// Mother로부터 유도된 Child 클래스 
class Child : public Mother
{
public:
	double _d;

public:
	Child()
		//: Mother() => 부모의 생성자를 따로 호출하지 않을 경우, 
		//				부모 클래스의 디폴트 생성자가 기본 호출되는 구조 
		//				이니셜라이저 리스트의 열거 순서에 상관없이 부모의 생성자가 가장 먼저 호출
		: Mother(1024), _d(1.0)
	{
		cout << "Child Constructor Called" << endl; 
	}
};

class A
{
public:
	A()
	{
		cout << "A Constructor Called" << endl; 
	}
};

class B : public A 
{
public:
	B()
	{
		cout << "B Constructor Called" << endl;
	}
};

class C : public B 
{
public:
	C()
	{
		cout << "C Constructor Called" << endl;
	}
};

int main()
{
	Child child;

	C c;

	return 0; 
}