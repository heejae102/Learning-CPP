#include<iostream>
using namespace std;

/*

<포인터에 대한 템플릿 특수화>

템플릿에서 파라미터가 포인터인 경우  
해당 자료형이 인스턴스화 되는 경우에 대한 특수화 

*/

template<class T>
class A
{
private:
	T _value; 

public:
	A(const T &input)
		: _value(input) {}

	void print()
	{
		cout << _value << endl;
	}
};

template<class T>
// T가 포인터인 경우의 특수화 
class A<T*>
{
private:
	T* _value;

public:
	A(T* input)
		: _value(input) {}

	void print()
	{
		cout << *_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();

	int temp = 456;

	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();

	double temp_d = 3.141592;

	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();

	return 0;
}