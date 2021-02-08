#include<iostream>
using namespace std; 

/*

<정적 멤버 함수>

*/

class Something
{
public:
	// 이너 클래스 : static 멤버 변수를 객체 내에서 초기화 하는 대안. 간접적으로 접근해서 초기화. 
	class _init
	{
	public:
		_init() { s_value = 9876; }
	};

private:
	// static 멤버 변수는 같은 클래스의 모든 인스턴스에서 접근 가능(하나의 주소로 모두가 공유)
	static int s_value; 
	int m_value;

	static _init s_initializer;	// 이너 클래스 정의 

public:
	// static 멤버 변수는 생성자에서 초기화 불가능 
	// 여기서 static 멤버 변수를 초기화하려면 생성자가 static이 되어야 하며, static 생성자는 지원되지 않음.
	Something() :m_value(123)/*, s_value(1024)*/ {}

	static int getValue() 
	{
		// static 멤버 함수 내에서는 this 포인터를 사용할 수 없다. 
		// 즉, 명시적으로 this 포인터를 사용하는 것이 불가능할 뿐 아니라, 
		// this 포인터를 사용해서 접근할 수 있는 모든 멤버에 대한 접근이 불가능하다. 
		
		// 1. this 포인터 직접 사용 불가 
		//return this.s_value;
		
		// 2. this 포인터 간접 사용 불가 
		// m_value도 this.m_value 가 축약된 형태이므로 접근 불가능 
		//return m_value;
		
		return s_value; 
	}
	
	int temp() { return this->s_value; }
};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{
	// 1.해당 static 멤버를 private으로 돌리면 direct로 접근 불가능  
	//cout << Something::s_value << endl; 

	// 1번의 경우 해당 멤버를 호출하는 함수를 static으로 바꾸면 간접적인 방법으로 
	// 특정 인스턴스 없이도 접근 가능 
	cout << Something::getValue() << endl; 

	Something s1;
	//cout << s1.getValue() << endl; 
	//cout << s1._value << endl; 

	// non-static 멤버 함수 포인터 선언 
	int (Something::*fptr1)() = &Something::temp;
	
	/*
	
	Something이라는 클래스 내에 속해있는 멤버함수 temp의 포인터를 가지고 있는데, 
	그 포인터의 위치에 있는 함수를 실행시킬 때 's1'이라는 인스턴스의 포인터를 넘겨주고, 
	's1'이라는 인스턴스의 this 포인터를 가져다가 해당 함수를 작동시키는 형태 

	따라서 's1'을 주지 않으면 작동하지 않음. 
	non-static 멤버함수는 인스턴스에 종속된 형태로 구현되어 있기 때문에, 
	this 포인터를 넘겨주지 않으면 함수가 작동하지 않는다. 
	즉, 모든 멤버 변수와 멤버 함수는 this 포인터가 숨겨져 있는 형태라고 할 수 있다. 

	(멤버함수는 하나의 함수를 인스턴스들끼리 공유하며, this 포인터로 해당 함수의 주소에 
	실행하고자 하는 인스턴스의 주소를 넘겨주면 해당 인스턴스의 멤버 값을 사용하여 함수를 실행)
	
	*/

	// non-static 멤버 함수 포인터 사용 
	cout << (s1.*fptr1)() << endl; 

	// static 멤버 함수 포인터 선언  
	// static 멤버 함수는 특성 인스턴스와 상관없이 호출 가능하므로 '객체명::' 을 빼주어야 함.  
	int(*fptr2)() = &Something::getValue;

	// static 멤버 함수 포인터 사용 
	// 특정 인스턴스를 거치지 않고 바로 사용 가능 
	cout << fptr2() << endl; 

	return 0; 
}