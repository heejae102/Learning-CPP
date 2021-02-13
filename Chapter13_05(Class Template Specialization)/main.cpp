#include<iostream>
#include<array>
#include"Storage8.h"
using namespace std; 

/*

<Ŭ���� ���ø� Ư��ȭ>

*/

template<typename T>
class A
{
public:
	A(const T& input) {}

	void doSomething()
	{
		cout << typeid(T).name() << endl; 
	}

	void test() {}
};

// ���ø�ȭ�� Ŭ������ char ������ �ν��Ͻ�ȭ�ϴ� ��� 
// �Ʒ��� ���� �۵��ϵ��� �����ϴ� ������, ���ο� Ŭ������ �����ϴ� �Ͱ� �����. 
template<>
class A<char>
{
public:
	A(const char& input) {}

	void doSomething()
	{
		cout << "Char type specialization" << endl; 
	}
};

int main()
{
	//A<int> a_int;
	//A<double> a_double;
	//A<char> a_char; 

	// �����ڸ� �����Ͽ� �Ʒ��� ���� ����ϴ� �͵� ���� 
	A<int> a_int(10);
	A<double> a_double(3.14);
	A<char> a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	// ��Ӱ� �򰥸��� ���ƾ� �� ����, ������ Ŭ���� ���� ���ǵ� �͵��� 
	// ���ø� Ư��ȭ Ŭ������ ���������� ���ǵ��� �ʴ´ٸ� ����� �� ����. 
	// ���ó�� ������ ���� �̾�ް� ���� �������ؼ� �� �� �ִ� ���� �ƴ϶�,
	// �Ȱ��� ���ø� �ν��Ͻ��� ������ ���ο� Ŭ������ ����� �Ͱ� ���� ���. 
	a_int.test();
	a_double.test();
	//a_char.test();

	//=======================================================================//

	// Define a Storage for Integers

	Storage8<int> intStorage;

	for (int count = 0; count < 8; count++)
	{
		intStorage.set(count, count);
	}

	for (int count = 0; count < 8; count++)
	{
		std::cout << intStorage.get(count) << '\n';
	}

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl; 

	Storage8<bool> boolStorage;

	for (int count = 0; count < 8; count++)
	{
		boolStorage.set(count, count & 3);
	}

	for (int count = 0; count < 8; count++)
	{
		std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';
	}

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
}