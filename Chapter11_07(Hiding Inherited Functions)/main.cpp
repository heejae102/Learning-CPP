#include<iostream>
using namespace std; 

/*

<��ӹ��� �Լ� ���߱�>

�θ� Ŭ�����κ��� ��ӹ��� Ŭ������ 
�ڽ� Ŭ�������� ���߰ų� ������� ���ϵ��� ���� 

1. using Ű���带 ����Ͽ� �ش� ����� �Լ��� ���������ڸ� private���� ������ 
2. delete Ű���带 ����Ͽ� �ش� ����� �Լ��� ������� ���ϵ��� ���� 

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

	// ���� Ŭ������ ��� �����ڸ� public���� ������ 
	// using ~ ���ϸ� �����ϴ� �ڽ� Ŭ������ ���������ڷ� ������ ��. 
	using Base::_i;

private:
	// 1. ���� Ŭ������ �Լ� �����ڸ� private���� ������ 
	// �Լ� �ڿ� ()�� �������־�� �Ѵ�. 
	using Base::print; 

	// 2. delete Ű���带 ����Ͽ� �ش� �Լ��� ������� ���ϵ��� ���� 
	void print() = delete; 
};

int main()
{
	Derived derived(5);
	
	derived._i = 10;
	//derived.print();

	return 0;
}