#include<iostream>
#include<array>
#include"Storage8.h"
using namespace std; 

/*

<클래스 템플릿 특수화>

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

// 템플릿화된 클래스를 char 형으로 인스턴스화하는 경우 
// 아래와 같이 작동하도록 설정하는 것으로, 새로운 클래스를 정의하는 것과 비슷함. 
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

	// 생성자를 구현하여 아래와 같이 사용하는 것도 가능 
	A<int> a_int(10);
	A<double> a_double(3.14);
	A<char> a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	// 상속과 헷갈리지 말아야 할 것은, 기존의 클래스 내에 정의된 것들이 
	// 템플릿 특수화 클래스에 개별적으로 정의되지 않는다면 사용할 수 없음. 
	// 상속처럼 이전의 것을 이어받고 새로 재정의해서 쓸 수 있는 것이 아니라,
	// 똑같이 템플릿 인스턴스가 가능한 새로운 클래스를 만드는 것과 같은 방식. 
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