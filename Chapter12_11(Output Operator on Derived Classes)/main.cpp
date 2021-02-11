#include<iostream>
using namespace std;

/*

<���� Ŭ�������� ��� ������ ����ϱ�>

friend ��� �����ڴ� �����ζ��̵��� �Ұ���.
���� ��� ������ �ϴ� ��� �Լ��� ���� �ΰ� 
�ش� �Լ��� ���� �������̵� ���� 

*/

class Base
{
public:
	Base() {}

	// friend �Լ��� ��� �Լ��� �ƴϱ� ������ ���� �������̵��ϴ� ���� �Ұ���
	// ���� ��� ������ �ϴ� ��� �Լ��� ���� �ΰ� �ش� �Լ��� �������̵�
	friend std::ostream &operator << (std::ostream &out, const Base &b)
	{
		return b.print(out);
	}

	virtual std::ostream &print(std::ostream &out) const
	{
		out << "Base";
		return out; 
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream &print(std::ostream &out) const override
	{
		out << "Derived";
		return out; 
	}
};

int main()
{
	Base base;
	std::cout << base << "\n";

	Derived derived;
	std::cout << derived << "\n";

	Base &bref = derived;
	std::cout << bref << "\n";

	return 0;
}