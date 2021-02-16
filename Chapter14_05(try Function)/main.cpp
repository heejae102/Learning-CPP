#include<iostream>
using namespace std;

/*

<try 함수>

클래스의 생성자에서 발생하는 예외를 처리하는 것도 중요 
따라서 멤버 이니셜라이저 리스트에서 try 함수를 사용하여 예외처리를 하기도 함.

*/

class A
{
private:
	int _x;

public:
	A(int x) : _x(x) 
	{
		if (x <= 0) throw 1; 
	}
};

class B : public A
{
public:
	//B(int x) : A(x) {}

	// 생성자 내에서 catch 하는 방식 
	// ※ 생성자에서 catch 하는 문법 사용 시 따로 throw 함수를 사용하지 않아도
	// 자동으로 rethrow 되어서 전달됨. 따라서 생성자-main 내 catch 모두 작동.   
	B(int x) try : A(x)
	{
		// do initialization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl; 
		
		//throw;
	}
};

// 함수의 바디 전체에 대해 try-catch 함수를 사용하기도 함. 
// 단, 실제로 잘 쓰이는 문법은 아님. 

// ※ 바디 내에서 catch 할 경우 rethrow 되지 않음. 
// rethrow 되지 않으므로 main 내의 catch 는 실행되지 않음.  
void doSomething()
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl; 
}

int main()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl; 
	}

	return 0;
}