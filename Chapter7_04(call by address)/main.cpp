#include<iostream>
using namespace std; 

/*

<Call by address>

�Ű������� �ּ� ���� �Ѱ� �޾Ƽ� �ش� �ּҸ� ���� ���� �����ϴ� ��.
call by value�� �޸� ���� �������ϱ� ������ ���� ���� ���� ����. 

������ ������ ���� ���������� call by value�� ���� �۵��Ͽ� 
���ڷ� �޴� ������ ������ �Լ� �� �Ű������� ������ ������ ������ �����̴�. 
(��, �� ������ �ּ� ���� �Ű������� �ּ� ���� �ٸ���.)

*/

//������ ������ �ּҸ� ���޹޾� �ش� ������ ����� ���, 
//�ּҷ� �������� �����ϱ� ������ �� �������� ������ �� �ִ�.

//������, �̰͵� ������ ���� ��ü�� call by value��, ������ ������ �����ϸ鼭 
//���ڷ� �Ѱܹ��� �ּ� ���� ������ ���̴�. 
//��, �������� ������ ������ �ּҰ��� �Լ� �� �Ű������� �ּҰ��� �ٸ���. 

//�������� �������� ������ �� �ֱ� ������ �Լ��� ��°�ó�� �̿��ϱ⵵ �Ѵ�. 

void test(int *ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl; 
}

//�������� �տ� const�� ������ �������Ͽ� ���� �������� �ʰڴٴ� �ǹ� 
//������ �տ� const�� ������ �ش� ������ ������ �ٸ� �ּ� ���� �������� �ʰڴٴ� �ǹ� 

//C��Ÿ�� �ڵ� 

void print(const int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl; 
	}
}

void print(int *const array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl;
	}

	//������ �տ� const�� �پ����Ƿ� array�� �ٸ� �ּҰ��� ������ �� X 
	//int x = 5;
	//array = &x;
}

int main()
{
	int value = 5;

	cout << value << " " << &value << endl; 

	int *ptr = &value;

	cout << "main &ptr : " << &ptr << endl; 

	test(ptr);
	test(&value);
	
	//���ͷ��� �޸� �ּҰ� �����Ƿ� �ȵ�. �Ű������� const�� �����ص� �ȵ�. 
	//test(5);


	//--------------------------------------------------------------------//

	int arr[5]{ 1,2,3,4,5 };

	print(arr, 5);

	return 0;
}