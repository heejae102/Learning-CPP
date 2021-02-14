#include<iostream>
using namespace std; 

/*

<��� �Լ��� �� �� �� ���ø�ȭ�ϱ�>

*/

template<class T>
class A
{
private:
	T _value;

public:
	A(const T &input)
		: _value(input) {}

	// Ŭ���� A �� �̹� �Ķ���� T�� ���ø�ȭ�Ǿ� ������, 
	// doSomething�� �ٽ� �Ķ���� TT�� ���ø�ȭ �� ��. 
	// TT�� doSomething �������� �Ķ���ͷ� �ۿ�. 
	//template<typename TT>
	//void doSomething()
	//{
	//	cout << typeid(T).name() << " " << typeid(TT).name() << endl; 
	//}
	
	// TT Ÿ���� �Ķ���ͷ� �޴� ��� �ش� �Լ��� �Ʒ��� ���� �ν��Ͻ�ȭ���� �ʰ�
	// �Ķ���͸� �Է��ؼ�(�ڵ����� �Ķ���� Ÿ������ �ν��Ͻ�ȭ) ��� ���� 
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

	// doSomething �Լ��� float������ �ν��Ͻ�ȭ 
	//a_int.doSomething<float>();
	
	// �Ķ���͸� ���� doSomething �Լ��� char������ �ν��Ͻ�ȭ 
	//a_int.doSomething('A');
	
	// �Ʒ��� ���� �ڷ����� �Է��Ͽ� �ش� �ڷ������� �ν��Ͻ�ȭ ����  
	a_int.doSomething(char());

	return 0;
}