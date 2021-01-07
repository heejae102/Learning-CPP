#include<iostream>
using namespace std; 

/*

<freind Ű����>

�Լ��� Ŭ������ friend�� ������ ���, 
�ش� ������ �� Ŭ���� ���� ����� �����Ӱ� ���� ���� 

friend Ű���带 ����� ���� �����Ӱ� �����ϰ��� �ϴ� ����� 
Ŭ������ �ʵ忡 friend Ű���带 ����Ͽ� ������ �Լ�, ��ü�� ����

*/

/*

<���漱��> forward declaration

���߿� ���� �� ��ü�� �̸� �����Ͽ� �˷��شٰų�, 
��� Ŭ�������� Ư���� Ŭ������ ���� ������ �ʿ��Ͽ� ��ȣ�ۿ��� �� ��� 
��, �ڵ带 �аų� ������� �� ������ �� �ִ�. 

*/
class A;

class B
{
private:
	int m_value = 2;

	//friend void doSomething(A &a, B &b);

public:
	// ���漱���� �ص� �Լ� �� A�� ��� ������ ���� ������ ���� ������ �߻��ϹǷ�, 
	// �ش� ��� �Լ��� ����� ���Ǹ� �и��Ͽ� ���Ǵ� Ŭ���� A�� ���� ���� ��ġ�� �ű�� ���� �ذ� 
	void doSomething(A &a);

};

class A
{
private:
	int m_value = 1;

	// Ŭ���� B�� ������ �Ʒ��� �����Ƿ� B�� ���� ������ ����. �̷� ��� ���漱�� ��� 
	//friend void doSomething(A &a, B &b);

	// B Ŭ������ friend�� ���� (B Ŭ�������� A Ŭ���� ����� �����Ӱ� ���� ����) 
	//friend class B;

	// B Ŭ�������� ��� ������ ���� ���� Ư�� �Լ��� ���ؼ��� ���� �����ϰ� ����
	// �ٵ� �̷��� �� ���, ���漱���� �߾ doSomething �Լ��� ���� ������ ���� ������ ���� �߻�
	friend void B::doSomething(A &a);
};

void B::doSomething(A &a)
{
	cout << a.m_value << endl;
}

// doSomething �Լ��� A, B ��ü�� ����� ��� �����ؾ� �� ��� �� ��ü ��ο� friend Ű����� �Լ� ���� 
//void doSomething(A &a, B &b)
//{
//	cout << a.m_value << " " << b.m_value << endl;
//}

//void doSomething(A &a)
//{
//	cout << a.m_value << endl; 
//}

int main()
{
	A a; 
	B b; 

	//doSomething(a, b);

	b.doSomething(a);

	return 0;
}