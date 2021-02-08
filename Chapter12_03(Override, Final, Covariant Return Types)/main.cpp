#include<iostream>
using namespace std; 

/*

<상속과 다형성과 관련한 다양한 키워드>

▶ override 

상위 클래스의 가상함수를 하위 클래스에서 오버라이드 하는 구조의 
프로그램을 만든다고 했을 때, 실수로 파라미터를 다른 타입으로 선언한다거나,
함수명을 잘못 기재한다거나 하는 경우도 있을 수 있지만,
문법상으로는 틀린 것이 없으므로 컴파일 단계에서 발견하기는 어렵다. 

이러한 경우 가상함수를 상속받는 함수명 뒤에 override 를 작성하여 
해당 함수가 오버라이딩 하는 함수라는 것을 명시적으로 선언하면
컴파일러가 이에 따른 오류 검사를 진행하므로 사전에 실수를 방지할 수 있다.  


▶ final 

final 키워드를 사용하여 선언 한 객체 내 멤버는 
해당 객체를 상속하는 하위 클래스에서 오버라이딩하는 것이 불가능하다. 
override와 마찬가지로 함수명(파라미터) 뒤에 키워드 작성 


▶ covariant return types (공변 반환값)

자기 자신을 가리키는 참조 값을 리턴하는 함수를 가상함수로 상속하는 구조에서
(일반적으로 리턴 타입이 다른 경우 오버라이딩이 불가능하지만,
부모-자식 관계이기 때문에 해당 경우에는 가능하다.) 

부모 클래스 포인터로 자식 클래스를 가리키는 경우,
가상 함수를 선언했음에도 불구하고 부모 클래스의 포인터가 리턴 

*/

class A
{
public:
	//virtual void print(int x) { cout << "A" << endl; }

	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	} 
};

class B : public A
{
public:
	//void print(int x) final { cout << "B" << endl; }
	//void print(int x) override { cout << "B" << endl; }

	//void print(short x) { cout << "B" << endl; }	// 파라미터 잘못 기재 
	//void print1(int x) { cout << "B" << endl; }	// 함수명 잘못 기재 
	
	void print() { cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl; 
		return this; 
	}
};

int main()
{
	A a;
	B b;
	//C c;
	
	A &ref = b;
	
	b.getThis()->print();
	
	// 분명히 B 객체의 getThis()를 호출하여 B의 참조 값을 받았음에도 불구하고 
	// 래퍼런스 타입이 A이기 때문에 이를 A 타입으로 캐스팅하여 A 객체의 print를 호출
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl; 
	cout << typeid(ref.getThis()).name() << endl; 

	return 0;
}