#include<iostream>
using namespace std; 

struct Person
{
	int age;
	double weight; 
};

int main()
{
	// �����Ϳ� ������ ��� ���� ������ 

	Person person;
	person.age = 5;
	person.weight = 30;

	// ����ü�� ���۷��������� �����Ͽ� ���� ���� 
	Person &ref = person;
	ref.age = 15;

	// ��, �����ͷ� ����ü�� �����ϴ� ��� ->�� ���� �����ҿ� ����
	//�������Ͽ� . �� ���� �����ϴ� ���� ���� 
	Person *ptr = &person;
	ptr->age = 30;

	//.�����ڰ� *�����ں��� �켱������ �����Ƿ� ��ȣ�� ����ؾ� ��.
	(*ptr).age = 20;

	//���۷����� ���� �����Ͱ� �����ϴ� ����� �����ϴ� �͵� ����
	Person &ref2 = *ptr;
	ref2.age = 50;

	cout << &person << endl; 
	cout << ptr << endl; 
	cout << &ref2 << endl; 

	return 0;
}