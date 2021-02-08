#include<iostream>
using namespace std;

/*

<익명 객체> Anonymous Object

객체를 인스턴스화하지 않은 채로 사용할 수 있는 객체 
L value가 아닌 R value 처럼 작동. 
여러 번 사용하지 않고 한 번만 사용하는 객체로 사용하고 사라져버림. 
따라서 사용할 때마다 생성자, 호출자가 반복해서 호출. 

*/

class A
{
public:
	int m_value; 

	A(const int &input) : m_value(input)
	{
		cout << "Constructor" << endl; 
	}

	~A()
	{
		cout << "Destructor" << endl; 
	}

	void print()
	{
		cout << m_value << endl; 
	}

};

class Cents
{
private:
	int m_cents; 

public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};

Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	// 생성자, 소멸자 한 번씩만 호출 
	A a(32); 
	a.print();
	a.print();

	// 객체 내의 함수만 사용하거나 하는 상황(굳이 인스턴스화시킬 필요까지는 없는 상황)에서 사용
	// L value가 아닌 R value처럼 작용
	// 한 번 사용하고 나면 사라져버리므로 해당 메모리 재사용은 불가능 
	// 따라서 익명의 객체를 사용할 때마다 생성자, 소멸자가 반복해서 호출 

	A(64).print();
	A(128).print();

	cout << add(Cents(6), Cents(8)).getCents() << endl; 
	cout << int(6) + int(8) << endl; 

	return 0; 
}