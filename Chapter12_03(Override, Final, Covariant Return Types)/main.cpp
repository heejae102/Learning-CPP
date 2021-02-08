#include<iostream>
using namespace std; 

/*

<��Ӱ� �������� ������ �پ��� Ű����>

�� override 

���� Ŭ������ �����Լ��� ���� Ŭ�������� �������̵� �ϴ� ������ 
���α׷��� ����ٰ� ���� ��, �Ǽ��� �Ķ���͸� �ٸ� Ÿ������ �����Ѵٰų�,
�Լ����� �߸� �����Ѵٰų� �ϴ� ��쵵 ���� �� ������,
���������δ� Ʋ�� ���� �����Ƿ� ������ �ܰ迡�� �߰��ϱ�� ��ƴ�. 

�̷��� ��� �����Լ��� ��ӹ޴� �Լ��� �ڿ� override �� �ۼ��Ͽ� 
�ش� �Լ��� �������̵� �ϴ� �Լ���� ���� ��������� �����ϸ�
�����Ϸ��� �̿� ���� ���� �˻縦 �����ϹǷ� ������ �Ǽ��� ������ �� �ִ�.  


�� final 

final Ű���带 ����Ͽ� ���� �� ��ü �� ����� 
�ش� ��ü�� ����ϴ� ���� Ŭ�������� �������̵��ϴ� ���� �Ұ����ϴ�. 
override�� ���������� �Լ���(�Ķ����) �ڿ� Ű���� �ۼ� 


�� covariant return types (���� ��ȯ��)

�ڱ� �ڽ��� ����Ű�� ���� ���� �����ϴ� �Լ��� �����Լ��� ����ϴ� ��������
(�Ϲ������� ���� Ÿ���� �ٸ� ��� �������̵��� �Ұ���������,
�θ�-�ڽ� �����̱� ������ �ش� ��쿡�� �����ϴ�.) 

�θ� Ŭ���� �����ͷ� �ڽ� Ŭ������ ����Ű�� ���,
���� �Լ��� ������������ �ұ��ϰ� �θ� Ŭ������ �����Ͱ� ���� 

*/

class A
{
public:
	//virtual void print(int x) { cout << "A" << endl; }

	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	} 
};

class B : public A
{
public:
	//void print(int x) final { cout << "B" << endl; }
	//void print(int x) override { cout << "B" << endl; }

	//void print(short x) { cout << "B" << endl; }	// �Ķ���� �߸� ���� 
	//void print1(int x) { cout << "B" << endl; }	// �Լ��� �߸� ���� 
	
	void print() { cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl; 
		return this; 
	}
};

int main()
{
	A a;
	B b;
	//C c;
	
	A &ref = b;
	
	b.getThis()->print();
	
	// �и��� B ��ü�� getThis()�� ȣ���Ͽ� B�� ���� ���� �޾������� �ұ��ϰ� 
	// ���۷��� Ÿ���� A�̱� ������ �̸� A Ÿ������ ĳ�����Ͽ� A ��ü�� print�� ȣ��
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl; 
	cout << typeid(ref.getThis()).name() << endl; 

	return 0;
}