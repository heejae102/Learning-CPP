#include<iostream>
using namespace std; 

/*

<상속받은 함수의 오버라이딩>

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

	friend std::ostream &operator << (std::ostream &out, const Base &base)
	{
		out << "This is base output" << endl;
		return out; 
	}
};

class Derived : public Base 
{
private:
	double _d;

public:
	Derived(int value)
		: Base(value) {}

	void print()
	{
		// Base 의 print 함수를 호출하고, + 자식객체만의 특수한 기능 추가 
		// Base:: 를 빼먹으면 자기자신을 호출하는 재귀함수가 되어버림. 
		Base::print();
		cout << "I'm derived" << endl; 
	}

	friend std::ostream &operator << (std::ostream &out, const Derived &derived)
	{
		// base에 정의된 입출력 연산자 오버로딩도 출력하기
		// 파생 클래스를 부모 클래스로 캐스팅하여 출력 
		out << static_cast<Base>(derived);
		out << "This is derived output" << endl;
		return out;
	}
};

int main()
{
	Base base(5);
	//base.print();
	cout << base << endl; 

	Derived derived(10);
	cout << derived << endl; 

	return 0;
}