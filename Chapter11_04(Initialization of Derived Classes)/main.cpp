#include<iostream>
using namespace std; 

/*

<유도된 클래스들의 생성과 초기화>

 유도 클래스에서 메모리 할당 시 부모 클래스의 메모리를
 모두 수용할 수 있는 크기로 메모리를 할당 
 (패딩 때문에 전체 메모리 크기가 딱 떨어지지 않을 수 있다.)


 - 상속 클래스 생성 

 상위 클래스 -> 하위 클래스 순서로 생성자가 호출

 - 상속 클래스 소멸 

 하위 클래스 -> 상위 클래스 순서로 소멸자가 호출 

*/

class Mother
{
private:
	int _i;

public:
	Mother(const int &i_in = 0)
		: _i(i_in)
	{
		cout << "Mother Constructor Called" << endl; 
	}
};

class Child : public Mother
{
private:
	float _d;

public:
	Child()
		: _d(1.0f), Mother(1024)
	{
		cout << "Child Contructor Called" << endl; 
	}
};

class A
{
public:
	A(const int &a)
	{
		cout << "A : " << a << endl; 
	}

	~A()
	{
		cout << "Destructor A" << endl; 
	}
};

class B : public A
{
public:
	B(const int &a, const double &b)
		: A(a)
	{
		cout << "B : " << b << endl; 
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b)
	{
		cout << "C : " << c << endl; 
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main()
{
	//Child child;

	//cout << sizeof(Mother) << endl; 
	//cout << sizeof(Child) << endl; 

	//==============================================================//

	C c(1024, 3.14, 'a');

	return 0;
}