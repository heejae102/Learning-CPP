#include<iostream>
#include"MyConstants.h"
using namespace std; 

int value = 123;
//int a = 1;

//void doSomething()
//{
//	static int a = 1; 
//	++a; 
//	cout << a << endl; 
//}

//test�Լ��� main cpp���Ͽ����� ����ϱ� ���� ���� ����(extern ���� ����)
extern void test();
extern int a;

int main()
{
	//:: �ݷ� 2���� ����ϸ� global scope operator ���� ������ 

	//cout << value << endl; 

	//int value = 1;

	//cout << ::value << endl; 
	//cout << value << endl; 

	/*
	
	global variable 

	static duration variable 
	
	
	global ���� vs static ���� 

	1) static ���� 
	static ������ �޸𸮰� �������� ����ȴ�. 
	ó�� static ������ ���� �� �� �ݵ�� �ʱ�ȭ�Ǿ�� �Ѵ�. 

	�޸��� �������� � ������ ������ �ݺ������� �Ҵ��� �Ǿ� 
	����ϴ� �޸𸮸� �������� �����Ͽ� ���� �޸𸮸� �����Ѵ�. 

	����� �� �� ���� ���ڸ� �Լ��� �� �� ȣ��ƴ��� 
	Ȯ���ϴ� � ����ϸ� �����ϴ�. 


	2) global ���� 
	static ������ ����ϰ� ��� 
	������ �������⼭ ������ �����ϹǷ� ������ ��ư� ������� �������.
	��ü���� ���� �� �ݵ�� �ʿ��� ���� �����ϰ� ����� �����ϴ� ���� ����. 

	*/

	//doSomething();
	//doSomething();
	//doSomething();
	//doSomething();

	/*
	
	linkage

	���� ������ ��� �ش� �������� ����� �������, ������ �������� 
	�ۿ��ϱ� ������ �ٸ� ��ü��� ��ŷ�� �ʿ䰡 ���� 

	
	internal linkage 

	���� cpp ���� �ȿ����� �������� �۵��ϴ� ���� ���� 
	(cpp ���� ������ ���� ������ static���� �����ϴ� ���)


	external linkage

	�ٸ� cpp ���� �������� ������ �� �ִ� ���� ���� 
	������ extern Ű����(���� ������)�� ����ؼ� ���� ����
	extern ������ ������ �ʱ�ȭ�� �� ����. 

	������ cpp���Ͽ��� ���� ��������� �ΰ� ����� ��� ���� �ּҰ� �ٸ� ��ü�� ���� 
	(���� �ٸ� ��ü�� �������� �ʾƵ� �Ǵ� ��� �޸� ���� �߻� )

	extern Ű���带 ����ϸ� �޸𸮸� �� �������� �����ϰ� 
	���� �ּ��� �����Ͱ� �ݺ��ؼ� ���Ǿ� �޸� ���� ���� �� ����.

	*/

	/*
	
	<����>

	int g_x;			// external linkage 
	static int g_x		// internal linkage
	
	
	<forward declaration> 

	extern int g_z;
	extern const int g_z;
	

	int g_y(1);
	static int g_y(1);
	const int g_y(1);


	extern int g_w(1);
	extern const int g_w(1);
	*/

	//test();
	//cout << a << endl; 

	cout << "In main.cpp file" << Constants::pi << " " << &Constants::pi << endl; 
	test();

	return 0;
}