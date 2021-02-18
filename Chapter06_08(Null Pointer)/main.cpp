#include<iostream>
#include<cstddef>
using namespace std;

void doSomething(const double *ptr)
{
	cout << "address of doSomething ptr : " << &ptr << endl;

	if (ptr != nullptr)
	{
		//do something useful
		cout << *ptr << endl;
	}
	else
	{
		//do nothing with ptr 
		cout << "nullptr, do nothing" << endl;
	}
}

int main()
{
	//NULL pointer 
	//�����Ϳ� �ּҰ��� ����� ����ִ��� Ȯ���ϴ� �뵵�� ���� ���
	//�Լ� �Ķ���ͷ� ����� �� ���� 

	double *ptr = NULL;		//c style
	double *p = nullptr;	//c++ style

	doSomething(ptr);
	doSomething(p);

	double d = 1.234;
	doSomething(&d);

	ptr = &d;
	doSomething(ptr);

	//null �����͸� ������� �� �ִ� ����Ÿ�� 
	//null �����͸� �Ķ���ͷ� �޾ƾ��ϴ� ��� � ���
	nullptr_t nptr;

	//�Լ��� �Ķ���ͷ� �Ѿ�� ������ 
	//�Լ� ������ ����ϴ� �ش� �Ķ���� ������ �ּҴ� �ٸ���.
	//(�Լ� ������ �Ķ���ͷ� �Ѿ�� ������ �Ķ���� ������ �����ؼ� ���)
	cout << "address of main ptr : " << &ptr << endl;

	return 0;
}