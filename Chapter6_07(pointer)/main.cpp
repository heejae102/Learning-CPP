#include<iostream>
#include<typeinfo>
using namespace std; 

//������ : �޸��� �ּҸ� �����ϴ� ���� 

int* doSomethiing(int* ptr)
{
	//�Լ��� �Ķ����, ����Ÿ���� ������������ ����ϴ� �͵� ����
	
	return ptr;
}

struct something
{
	int a, b, c, d, e;
};

int main()
{
	int x = 5; 

	cout << x << endl; 
	cout << &x << endl; 

	//de-reference operator(*)
	//�ش� �ּҿ� ������ ����ִ� ���� ������ �� �ִ� ������ 
	//cout << *(&x) << endl; 

	//�����͵� �����̹Ƿ� ����� ������ ������ ���� ���� 
	//but, �Ǽ��� ������ �� �����Ƿ� �����ϴ� ���� ������ 
	//������ ���������ͳ� ���������͸� ����Ͽ� �򰥸� �� ���� �� ����ϱ⵵ ��.
	
	//�����͸� ������ �� ������ Ÿ���� �ʿ��� ������ de-referencing�� �� 
	//�ش� Ÿ���� �����Ͽ� �����͸� �о�;��ϱ� ���� 
	//�����͸� ������ ���� Ÿ�԰� ������ϴ� �������� Ÿ���� �ٸ� ��� ���� �߻�
	//����� ���� �ڷ����� �����ͷ� ����ų �� ����. 

	typedef int* pint;
	//pint ptr_x = &x, ptr_y = &x;
	int *ptr_x = &x; 
	double *ptr_y;

	cout << ptr_x << endl; 
	cout << *(ptr_x) << endl; 
	cout << typeid(ptr_x).name() << endl; 
	cout << typeid(ptr_y).name() << endl; 
	cout << sizeof(ptr_x) << endl; 
	cout << sizeof(ptr_y) << endl; 

	//������������
	//������ ������ �����ϴ� �ڷ����� ũ�Ⱑ �����̵��� ������� 
	//������ �ش� �ڷ��� �ּҰ��� �����ϴ� �����̹Ƿ�, �����ϴ� �����Ϳ�
	//������� ������ ������ ũ��� ������ ���� ������. (��� 16���� �ּ��̹Ƿ�)
	//���� ���ڸ� ���� ũ�⿡ ������� �������� ������ �Ͱ� ����. 

	something ss;
	something *ptr_sth;
	cout << sizeof(something) << endl; 
	cout << sizeof(ptr_sth) << endl; 

	//�����͸� ����Կ� �־� ���� ���� ������ ������ ������ �ʱ�ȭ���� �ʰ�
	//������ ���� ����ִ� �����͸� ����ϴ� ��. 
	int *ptr_temp;
	cout << ptr_temp << endl; 

	return 0; 
}