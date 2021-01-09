#include<iostream>
using namespace std; 

/*

<������ �����ε�> Operator Overloading

�����ڸ� ����ڰ� ���� �����ؼ� ���

���ϱ�, ����, ���ϱ�, ������ ���� �⺻���� ��� ������ ��� ��� �����ϳ�, 
���� ������(? :), ������ ������(::), sizeof, .(��� ������) .*(��� ������ ������) ��� �Ұ��� 

�� �����ڸ� ����ڰ� ���� ������ ���� ������, �������� �켱������ �״��. 
���� ����ڰ� ������ ���ϱ�, ���� �����ڴ� ����ڰ� ������ ���ϱ�, ������ �����ں��� �켱������ ����. 
������ �켱������ ���� ���� ����� ���� �׻� ��ȣ�� �μ� ����� ��. 

������ �ǹ�, ���� ������ �� �ִ� ������� ������ �����ε��� �����ϴ� ���� ����. 

*/

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// ������ �����ε��� ��� �Լ��� ���� (��� �Լ��� ���� �� �Ķ���ʹ� 1���� �����ؾ� ��.)
	// =, [], (), -> �����ڸ� ���� �����ε��� ��� �Լ��θ� ������ �� �ִ�. 
	Cents operator + (const Cents &c)
	{
		return Cents(this->m_cents + c.m_cents);
	}

	// ������ �����ε��� friend �Լ��� ���� 
	//friend Cents operator + (const Cents &c1, const Cents &c2)
	//{
	//	return Cents(c1.m_cents + c2.m_cents);
	//}
};

Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

// ������ �����ε� 
//Cents operator + (const Cents &c1, const Cents &c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}


int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents sum = add(cents1, cents2);
	cout << sum.getCents() << endl; 

	// cents1�� cents2�� ���� ��������, �� ���� Cents(6)�� �������� ������
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl; 

	return 0; 
}