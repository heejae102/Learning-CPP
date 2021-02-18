#include<iostream>
using namespace std; 

//�Լ��� �Ķ���͸� const ���۷����� �޴� ��� 
//���ڸ� �� �� ���������� �̿� ���� (����, ���, ����+���)
void doSomething(const int &x)
{
	cout << x << endl; 
}

int main()
{
	//const���� �����͸� ���� ���� ���۷����� constȭ ���Ѿ� ��.
	//const ���۷��������� ���� �� �����ϴ� ���� ������ �� X 
	//���۷��� ������ �ٸ� ���۷��� ������ �����ϴ� ���� �����ϴ� �͵� ���� 

	const int x = 5;
	const int &ref_x = x;
	const int &ref_2 = ref_x;

	//�ּҰ� ��� x������ �ּҷ� �����ϴ�. 
	cout << &x << endl; 
	cout << &ref_x << endl; 
	cout << &ref_2 << endl; 

	//���� ���ͷ� ���� ���۷��� ������ ������ �� ������, 
	//const ���۷����� ���� �� ���ͷ� ���� ������ �� �ִ�. 
	const int &ref_y = 3 + 4;

	//const�� ������ ���������, �Լ� �Ķ���ͷ� ����� �� 
	//const ���۷������� ����ϸ� ������ �� 
	const int value = 3 + 4;

	//���ͷ��� �޸� �ּҵ� ��� ���� 
	cout << &ref_y << endl; 
	cout << ref_y << endl; 

	//-------------------------------------------------//

	//�Լ��� �Ķ���͸� const ���۷����� �޴� ��� 
	//���ڸ� �� �� ���������� �̿� ���� (����, ���, ����+���)

	int a = 1;

	doSomething(a);
	doSomething(1);
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}