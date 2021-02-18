#include<iostream>
using namespace std; 

// void pointer (=generic pointer)

enum Type
{
	INT,
	FLOAT,
	CHAR
};

int main()
{
	//�����Ͱ� � ũ���� �����͸� �����ϵ��� ������ ���� ��ü�� ũ��� �����ϹǷ�
	//void �����͵� �������� ũ��� ������� � �����͵� ������ �� �ִ�.
	//��, ���������� void�̹Ƿ� �ּҰ��� �Ѱܹ��� ������ � ������������ 
	//������ �� �ִ� �ܼ��� ����. 

	//���� ������, ���� �� �������� ���� ������ ũ�⸦ �𸣱� ������
	//������ ���굵 �Ұ����ϴ�. 

	int i = 5;
	float f = 3.5f;
	char c = 'a';

	void *ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	//+1�� �� �� + ������ ���� �� �޸� ������ �𸣱� ������ ���� �߻� 
	//cout << ptr + 1 << endl; 

	//����, �ش� �޸𸮸� ��� ������������ ǥ���ؾ� ���� �𸣱� ������
	//�����ͷ� de-referencing(������)�� �Ұ��� 
	//��� �ּҰ��� ������ �� �ִ�. 
	//cout << *ptr << endl; 
	cout << ptr << endl; 

	//void �����ͷ� ������ ��, �ٲٰ��� �ϴ� �������� ������������ ĳ���� �ʿ� 
	//�̷��� ����� �ſ� ���������� �������� �����ϱ� ����
	//�ε����ϰ� ����ؾ� �ϴ� ��찡 ���� �� �ִ�. 
	Type type = FLOAT;

	switch (type)
	{
	case INT:
		cout << *static_cast<int*>(ptr) << endl;
		break;
	case FLOAT:
		cout << *static_cast<float*>(ptr) << endl;
		break;
	case CHAR:
		cout << *static_cast<char*>(ptr) << endl;
		break;
	default:
		break;
	}

	return 0;
}