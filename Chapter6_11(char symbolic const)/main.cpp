#include<iostream>
using namespace std; 

//�Լ��� ���� Ÿ�����ε� ��� ���� 
const char* getName()
{
	return "Jane Doe";
}

int main()
{
	//char name[] = "Jane Doe";
	
	//�������� ���ͷ�(���)�̰�, ������ ������ 
	//"Jane Doe"�� ��� �޸� �ּҰ� ���� ������ �����Ϳ� ������� �� x
	//�����ʹ� ������ �ּҸ� ����ų ���� ����. 
	
	//�� ��, ���� �տ� const�� �ٿ��� �ش� ���ͷ��� ��ȣ���� ���ó�� ����� �� ����
	//char *name = "Jane Doe";
	const char *name = "Jane Doe";
	const char *name2 = "Jane Doe";

	//���ͷ��� ��� ���� ���Ҹ� ���� ��� �޸� �ּҸ� ����
	cout << (uintptr_t)name << endl; 
	cout << (uintptr_t)name2 << endl; 

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";

	//int �迭�� �������� �ּ�, ���ڿ��� ������ Ȥ�� �������� ���ڿ��� ��� 
	//��, ������ �����ʹ� cout���� ��� �� Ư���� ������� �۵�
	cout << int_arr << endl; 
	cout << char_arr << endl; 
	cout << name << endl; 

	//������ �ּҸ� ����Ϸ��� �ϸ� ���ڿ��� ����ϴ� �� �˰� 
	//NULL�� ���������� ����Ϸ��� ������, c�� ���Ϲ��ڶ� 
	//NULL�� �����ϰ� ���� �ʱ� ������ ���� �߻� 
	char c = 'Q';
	cout << &c << endl; 
	cout << *(&c) << endl; 

	return 0;
}