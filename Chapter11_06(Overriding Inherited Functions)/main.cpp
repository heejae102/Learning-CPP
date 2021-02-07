#include<iostream>
using namespace std; 

/*

<��ӹ��� �Լ��� �������̵�>

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
		// Base �� print �Լ��� ȣ���ϰ�, + �ڽİ�ü���� Ư���� ��� �߰� 
		// Base:: �� �������� �ڱ��ڽ��� ȣ���ϴ� ����Լ��� �Ǿ����. 
		Base::print();
		cout << "I'm derived" << endl; 
	}

	friend std::ostream &operator << (std::ostream &out, const Derived &derived)
	{
		// base�� ���ǵ� ����� ������ �����ε��� ����ϱ�
		// �Ļ� Ŭ������ �θ� Ŭ������ ĳ�����Ͽ� ��� 
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