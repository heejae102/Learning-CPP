#include<iostream>
using namespace std; 

/*

<������ Ŭ�������� ������ �ʱ�ȭ>

 ���� Ŭ�������� �޸� �Ҵ� �� �θ� Ŭ������ �޸𸮸�
 ��� ������ �� �ִ� ũ��� �޸𸮸� �Ҵ� 
 (�е� ������ ��ü �޸� ũ�Ⱑ �� �������� ���� �� �ִ�.)


 - ��� Ŭ���� ���� 

 ���� Ŭ���� -> ���� Ŭ���� ������ �����ڰ� ȣ��

 - ��� Ŭ���� �Ҹ� 

 ���� Ŭ���� -> ���� Ŭ���� ������ �Ҹ��ڰ� ȣ�� 

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