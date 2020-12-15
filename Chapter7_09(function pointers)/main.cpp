#include<iostream>
#include<array>
#include<functional>
using namespace std; 

/*

<�Լ� ������>

�Լ��� ������ ���������� �ּҸ� ������ �ִ�. 
������ ������ ���� ������ ����Ű�� �Ͱ� ����������
�Լ��� �����͸� ���� �ּҸ� ����ų �� �ִ�. 

*/

int func()
{
	return 5;
}

int goo()
{
	return 10; 
}

bool isEven(const int &number)
{
	if (number % 2 == 0) return true;
	else return false; 
}

bool isOdd(const int &number)
{
	if (number % 2 == 1) return true; 
	else return false; 
}

//�Լ� �����͸� ����ϰ� ����� ��� typedef�̳� using Ű����� �ٿ��� ��밡�� 

//typedef bool(*check_fnc_t)(const int &);
//using check_fnc_t = bool(*)(const int &);
//
//void printNumbers(const array<int, 10> &my_arr, check_fnc_t check_fnc = isEven)
//{
//	for (const auto &element : my_arr)
//	{
//		if (check_fnc(element) == true) cout << element;
//
//		//if (!print_even && element % 2 == 1) cout << element;
//	}
//	cout << endl;
//}

//�Լ� �����͵� ����Ʈ �Ű������� �⺻���� �������� �� �ִ�. 

//void printNumbers(const array<int, 10> &my_arr, bool(*check_fnc)(const int &) = isEven)
//{
//	for (const auto &element : my_arr)
//	{
//		if (check_fnc(element) == true) cout << element;
//
//		//if (!print_even && element % 2 == 1) cout << element;
//	}
//	cout << endl;
//}

void printNumbers(const array<int, 10> &my_arr, 
	function<bool(const int &)> check_fnc = isEven)
{
	for (const auto &element : my_arr)
	{
		if (check_fnc(element) == true) cout << element;

		//if (!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}


int main()
{
	//�Լ��� �ּ� ��� 
	//cout << func << endl; 

	////�Լ��� ȣ���ϸ� �Լ��� �޸� �ּҸ� ã�Ƽ� 
	////�ش� �ּ� ���� �ִ� �ڵ带 ���� 
	//func();

	////�Լ� ������ ���� �� �ʱ�ȭ 
	////�����ϰ��� �ϴ� �Լ��� ���¿� �°� ����. 
	////����Ÿ�� (�Լ������͸�)(�Ű����� Ÿ��)
	//int(*fcnptr)() = func;

	////�Լ������ͷ� �Լ� ȣ�� 
	//cout << fcnptr() << endl;

	////�Լ������ͷ� �ٸ� �Լ� ���� ���� 
	//fcnptr = goo;

	//cout << fcnptr() << endl; 


	//----------------------------------------------------------//

	
	//�Լ� �����͸� �Ķ���ͷ� �ѱ��  

	array<int, 10> my_arr{ 1,2,3,4,5,6,7,8,9,10 };

	printNumbers(my_arr, isOdd);
	printNumbers(my_arr, isEven);
	
	//����Ʈ ������ ������ �Լ��� ���� ���� 
	printNumbers(my_arr);


	//----------------------------------------------------------//


	//C++17���� ���Ե� ��� (functional ��� ���)

	function<bool(const int &)> fcnptr = isEven;

	printNumbers(my_arr, fcnptr);

	fcnptr = isOdd;

	printNumbers(my_arr, fcnptr);

	return 0;
}