#include<iostream>
using namespace std; 

//void printArray(int *array)
//�Ű������� �Ѱܹ��� �������� ���� ������ �����ϱ� ���� �����͸� ��� (C)
//C++������ �밳 ���۷����� ���� ������ ���� ���� 

void printArray(int array[])
{
	cout << sizeof(array) << endl; //4

	*array = 100;
	//*array[0] = 100;
}

struct MyStruct
{
	int arr[5] = { 1,3,5,7,9 };
};

void doSomething(MyStruct ms)
{
	cout << sizeof(ms.arr) << endl; 
}

void doSomething(MyStruct *ms)
{
	cout << sizeof((*ms).arr) << endl; 
}

int main()
{
	////�迭�� �������� �迭�� ù��° ������ �ּҰ��� �����ϴ� ������ ������ ����. 

	//int array[5] = { 9,7,5,3,1 };

	//cout << array[0] << " " << array[1] << endl; 
	//cout << array << endl; 
	//cout << &(array[0]) << endl; 

	////array�� ù��° ������ �ּҰ��� ���� ������ de-referencing 
	//cout << *array << endl; 

	//int *ptr = array;
	//cout << ptr << endl; 
	//cout << *ptr << endl; 

	////but, �迭�����Ϳ� �Ϲ������Ϳ��� ���̰� ��

	////�迭�� ��ü ������ : 20
	//cout << sizeof(array) << endl;		
	////�迭�� �ּҸ� ���� �������� ������ : 4
	//cout << sizeof(ptr) << endl; 

	////�迭�� ��°�� �Ѱ�����, ����� �����ϸ� 4�� ��µ�. 
	////�迭�� �ѱ�� �� �ѱ�簣�� �Լ� �������� ������ ������ �޾� 
	////�ش� �迭�� ù��° �ּ� ���� �����ϱ� ������ ����� ����ϸ� 
	////�ᱹ ������ ������ �������� 4�� ��� ��. 
	//printArray(array);

	//cout << "*array " << *array << endl; 
	//cout << "array[0] " << array[0] << endl; 

	//�ڱ���ü ���� �迭�� �ִ� ��� ������ ���ϱ�� 
	//�迭�� ����ü�� Ŭ���� ���� ����ִ� ���, �����ͷ� ������ȯ���� �ʰ�
	//�迭�� �� ��ü�� ���� ������ �迭�� ����� ����� ��� 

	MyStruct ms; 

	cout << ms.arr[0] << endl; 
	cout << sizeof(ms.arr) << endl;

	doSomething(ms);
	doSomething(&ms);

	//char name[] = "jack";
	//cout << *name << endl; 
	//cout << name[0] << endl; 

	return 0; 
}