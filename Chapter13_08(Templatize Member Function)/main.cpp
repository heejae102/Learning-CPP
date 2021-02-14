#include<iostream>
using namespace std; 

/*

<멤버 함수를 한 번 더 템플릿화하기>

*/

template<class T>
class A
{
private:
	T _value;

public:
	A(const T &input)
		: _value(input) {}

	// 클래스 A 가 이미 파라미터 T로 템플릿화되어 있지만, 
	// doSomething을 다시 파라미터 TT로 템플릿화 한 것. 
	// TT는 doSomething 내에서만 파라미터로 작용. 
	//template<typename TT>
	//void doSomething()
	//{
	//	cout << typeid(T).name() << " " << typeid(TT).name() << endl; 
	//}
	
	// TT 타입을 파라미터로 받는 경우 해당 함수를 아래와 같이 인스턴스화하지 않고
	// 파라미터만 입력해서(자동으로 파라미터 타입으로 인스턴스화) 사용 가능 
	// a_int.doSomething<float>();
	// a_int.doSomething(1.23f);
	template<typename TT>
	void doSomething(const TT &input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)_value << endl; 
	}

	void print()
	{
		cout << _value << endl; 
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();

	// doSomething 함수를 float형으로 인스턴스화 
	//a_int.doSomething<float>();
	
	// 파라미터를 통해 doSomething 함수를 char형으로 인스턴스화 
	//a_int.doSomething('A');
	
	// 아래와 같이 자료형을 입력하여 해당 자료형으로 인스턴스화 가능  
	a_int.doSomething(char());

	return 0;
}