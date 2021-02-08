#include<iostream>
using namespace std;

/*

<�͸� ��ü> Anonymous Object

��ü�� �ν��Ͻ�ȭ���� ���� ä�� ����� �� �ִ� ��ü 
L value�� �ƴ� R value ó�� �۵�. 
���� �� ������� �ʰ� �� ���� ����ϴ� ��ü�� ����ϰ� ���������. 
���� ����� ������ ������, ȣ���ڰ� �ݺ��ؼ� ȣ��. 

*/

class A
{
public:
	int m_value; 

	A(const int &input) : m_value(input)
	{
		cout << "Constructor" << endl; 
	}

	~A()
	{
		cout << "Destructor" << endl; 
	}

	void print()
	{
		cout << m_value << endl; 
	}

};

class Cents
{
private:
	int m_cents; 

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};

Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	// ������, �Ҹ��� �� ������ ȣ�� 
	A a(32); 
	a.print();
	a.print();

	// ��ü ���� �Լ��� ����ϰų� �ϴ� ��Ȳ(���� �ν��Ͻ�ȭ��ų �ʿ������ ���� ��Ȳ)���� ���
	// L value�� �ƴ� R valueó�� �ۿ�
	// �� �� ����ϰ� ���� ����������Ƿ� �ش� �޸� ������ �Ұ��� 
	// ���� �͸��� ��ü�� ����� ������ ������, �Ҹ��ڰ� �ݺ��ؼ� ȣ�� 

	A(64).print();
	A(128).print();

	cout << add(Cents(6), Cents(8)).getCents() << endl; 
	cout << int(6) + int(8) << endl; 

	return 0; 
}