#include<iostream>
using namespace std; 

int main()
{
	//int value = 7;
	//int *ptr = &value; 

	//�ּҴ� �⺻������ 16������ ����Ǿ� ���� 
	//cout << ptr << endl; 

	//�ּҸ� 10������ ��ȯ����. 
	//cout << uintptr_t(ptr) << endl;	

	/*
	
	<������ ����>

	�����Ϳ� +,-�� ������ �� ���, 

	(�������� ������ Ÿ���� �޸�)*���갪 �� ���·� ���� 
	
	ex. int ptr;
		ptr + 1 : ptr + (int���� �޸� * 1)
		ptr + 2 : ptr + (int���� �޸� * 2)

	*/

	//cout << uintptr_t(ptr - 1) << endl;
	//cout << uintptr_t(ptr) << endl;
	//cout << uintptr_t(ptr + 1) << endl;
	//cout << uintptr_t(ptr + 2) << endl;

	//�迭�� �޸𸮰� ������ �þ ���·�, �ּҸ� ����ϸ� 
	//�ش� ������ Ÿ���� ũ�⸸ŭ �����ϰ� �����ϴ� ���·� �ּҰ� �̿��� ���� 
	//�ش� ������ �̿��Ͽ� ������ �ε����� �̿��� �迭�� ���������� ���� ���� 

	//int array[] = { 1,3,5,7,9 };
	//int *ptr = array;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << array[i] << " " << (uintptr_t)&array[i] << endl; 
	//	cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
	//}

	char name[] = "Jack jack";

	//�̷��� �����ϸ� ������ ������ null�� �Բ� ���Ե� ���� ���� 
	const int n_name = sizeof(name) / sizeof(char);

	for (int i = 0; i < n_name - 1; i++)
	{
		//�Ʒ� ����� ����
		cout << *(name + i) << endl;
		//cout << name[i] << endl; 
	}
}
