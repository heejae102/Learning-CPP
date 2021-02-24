#include<iostream>
#include<tuple>
using namespace std; 

/*

<�Լ����� ���� ���� ���ϰ� ��ȯ�ϱ�> (C++ 17)

C++ 17 ��� �� ���� 
������Ʈ �Ӽ� - C/C++ - ��� - C++ ��� ǥ�� - IOS C++17 ǥ��

�Ϲ������� �Լ������� 1���� ����� ���� ���� 

*/

//int my_func()
//{
//	return 0;
//}

// 1. tuple�� ����Ͽ� ���� ���� ��� ���� 
//tuple<int, int> my_func()
//{
//	return tuple<int, int>(123, 456);
//}

// 2. tuple�� auto�� ���� ���� 
//auto my_func()
//{
//	return tuple<int, int>(123, 456);
//}

// 3. C++17 ���� return�ϱ�
auto my_func()
{
	return tuple(123, 456, 789);
}

int main()
{
	cout << "Hello, World!" << endl;

	// 1. tuple�� ��� �� �ޱ� 
	//tuple<int, int> result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << endl;

	// 2. auto(tuple)�� ��� �� �ޱ� 
	//auto result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << endl;

	// 3. C++17 ���� auto(tuple)�� ��� �� �ޱ� 
	//auto result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	// ������ ��Ƽ� �����ϴ� �͵� ���� 
	auto[a, b, c] = my_func();
	cout << a << " " << b << " " << c << " " << endl;

	return 0;
}