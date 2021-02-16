#include<iostream>
using namespace std;

/*

<try �Լ�>

Ŭ������ �����ڿ��� �߻��ϴ� ���ܸ� ó���ϴ� �͵� �߿� 
���� ��� �̴ϼȶ����� ����Ʈ���� try �Լ��� ����Ͽ� ����ó���� �ϱ⵵ ��.

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

	// ������ ������ catch �ϴ� ��� 
	// �� �����ڿ��� catch �ϴ� ���� ��� �� ���� throw �Լ��� ������� �ʾƵ�
	// �ڵ����� rethrow �Ǿ ���޵�. ���� ������-main �� catch ��� �۵�.   
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

// �Լ��� �ٵ� ��ü�� ���� try-catch �Լ��� ����ϱ⵵ ��. 
// ��, ������ �� ���̴� ������ �ƴ�. 

// �� �ٵ� ������ catch �� ��� rethrow ���� ����. 
// rethrow ���� �����Ƿ� main ���� catch �� ������� ����.  
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