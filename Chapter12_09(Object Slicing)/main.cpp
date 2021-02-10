#include<iostream>
#include<vector>
#include<functional>
using namespace std;

/*

<��ü �߸��� reference_wrapper>

�� ��ü �߸�

�Ϲ������� �θ� Ŭ�������ٴ� �ڽ� Ŭ�������� �� ���� �����͸� �����µ�, 
���� ���� ���� �Ը��� �θ� ��ü�� ���� ū �Ը��� �ڽ� ��ü�� ������ ���� �� ���
�θ� ��ü�� ���� �� �ִ� �޸� ũ�Ⱑ �� �����Ƿ� 
�ڽ� Ŭ�������� �ִ� �������� �߷������� �ȴ�. 

*/

class Base
{
public:
	int _i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl; 
	}
};

class Derived : public Base
{
public:
	int _j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl; 
	}
};

//void doSomething(Base &base)
//{
//	base.print();
//}

/*

�Լ��� �Ķ���͸� �޴� ��쿡��, ��ü�� �ּҸ� �޾� �����ϴ� ���� �ƴ϶�
���� �޾� �����ϴ� ��� ��ü �߸� ���� �߻� 

*/

void doSomething(Base base)
{
	base.print();
}

int main()
{
	Derived derived;
	//Base &base = derived;

	/*
	
	�ּҷ� �����ϴ� ���� �ƴ϶� �������� ���� �޾� �����ϰ� �� ���,
	base�� �޸� ũ�Ⱑ derived���� �۱� ������ �޸� �߸� ���� �߻�.

	�ڽ� Ŭ������ �ִ� ������ �Լ��� ������ �� ���� �ͻ� �ƴ϶�, �������� �������.
	�޸𸮰� �߷������鼭 �ڽ� Ŭ������ �Լ��� �����ϱ� ���� �߰����� �����鵵 ������鼭
	������ base�� �ִ� �Լ��鸸 ������ �� �����Ƿ� �������� ������� �ȴ�. 
	
	*/

	//Base base = derived;
	//base.print();

	//========================================================================//

	// <���� ��� �� ��ü �߸� ����>
	
	// ��ü�� �ּҰ� �ƴ� ���� ���ҷ� ������ ������ ���, 
	// ���� Ÿ���� �θ� ��ü�� �ϰ� �ڽ� ��ü�� ���ҷ� ���� ��� ��ü�߸����� �߻� 
	// ���� �ƴ� ��ü�� �ּҸ� ���� Ÿ������ �� ��� ���� �ذ� 
	// (�� ���۷����� ����ص� ������ �ذ�� �� �ְ�����, ������ ���ҷ� ���۷��� ��� �Ұ���)

	Base b; 
	Derived d; 

	//std::vector<Base> my_vec;
	//my_vec.push_back(b);
	//my_vec.push_back(d);

	std::vector<Base*> my_vec;
	my_vec.push_back(&b);
	my_vec.push_back(&d);

	for (auto &element : my_vec)
	{
		//element.print();
		element->print();
	}

	//========================================================================//

	// ���۷����� ���� ���Ҹ� ������ ���� ����� 

	// ������� <functional> �߰� 
	// Base�� ���۷����� ���ҷ� �����ϴ� ���� 
	// std::vector<Base&> v; �̿� ���� �۵� (�����δ� ���۷����� ���ҷ� ��� �Ұ���)
	std::vector<std::reference_wrapper<Base>> v;
	v.push_back(b);
	v.push_back(d);

	for (auto &element : v)
		element.get().print();

	return 0;
}