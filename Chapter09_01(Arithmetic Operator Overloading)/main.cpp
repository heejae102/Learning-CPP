#include<iostream>
using namespace std; 

/*

<연산자 오버로딩> Operator Overloading

연산자를 사용자가 직접 정의해서 사용

더하기, 빼기, 곱하기, 나누기 등의 기본적인 산수 연산자 모두 사용 가능하나, 
삼항 연산자(? :), 스코프 연산자(::), sizeof, .(멤버 셀렉션) .*(멤버 포인터 셀렉션) 사용 불가능 

※ 연산자를 사용자가 직접 정의할 수는 있지만, 연산자의 우선순위는 그대로. 
따라서 사용자가 정의한 더하기, 빼기 연산자는 사용자가 정의한 곱하기, 나누기 연산자보다 우선순위가 낮다. 
연산자 우선순위가 낮은 것을 사용할 때는 항상 괄호로 싸서 사용할 것. 

가급적 의미, 논리를 납득할 수 있는 방식으로 연산자 오버로딩을 구현하는 것이 좋다. 

*/

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// 연산자 오버로딩을 멤버 함수로 구현 (멤버 함수로 구현 시 파라미터는 1개로 설정해야 함.)
	// =, [], (), -> 연산자를 통한 오버로딩은 멤버 함수로만 구현할 수 있다. 
	Cents operator + (const Cents &c)
	{
		return Cents(this->m_cents + c.m_cents);
	}

	// 연산자 오버로딩을 friend 함수로 선언 
	//friend Cents operator + (const Cents &c1, const Cents &c2)
	//{
	//	return Cents(c1.m_cents + c2.m_cents);
	//}
};

Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

// 연산자 오버로딩 
//Cents operator + (const Cents &c1, const Cents &c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}


int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents sum = add(cents1, cents2);
	cout << sum.getCents() << endl; 

	// cents1과 cents2가 먼저 더해지고, 그 다음 Cents(6)과 더해지는 연쇄방식
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl; 

	return 0; 
}