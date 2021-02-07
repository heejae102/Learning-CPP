#include<iostream>
using namespace std; 

/*

<상속받은 함수 감추기>

부모 클래스로부터 상속받은 클래스를 
자식 클래스에서 감추거나 사용하지 못하도록 막기 

1. using 키워드를 사용하여 해당 멤버나 함수의 접근지정자를 private으로 재정의 
2. delete 키워드를 사용하여 해당 멤버나 함수를 사용하지 못하도록 막기 

*/

class Base
{
protected:
	int _i;

public:
	Base(int value)
		: _i(value) {}

	void print()
	{
		cout << "I'm base" << endl; 
	}
};

class Derived : public Base
{
private:
	int _d;

public:
	Derived(int value)
		: Base(value) {}

	// 상위 클래스의 멤버 접근자를 public으로 재정의 
	// using ~ 이하를 선언하는 자식 클래스의 접근지정자로 재정의 됨. 
	using Base::_i;

private:
	// 1. 상위 클래스의 함수 접근자를 private으로 재정의 
	// 함수 뒤에 ()는 생략해주어야 한다. 
	using Base::print; 

	// 2. delete 키워드를 사용하여 해당 함수를 사용하지 못하도록 막기 
	void print() = delete; 
};

int main()
{
	Derived derived(5);
	
	derived._i = 10;
	//derived.print();

	return 0;
}