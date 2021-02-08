#include<iostream>
using namespace std; 

/*

<freind 키워드>

함수나 클래스를 friend로 선언할 경우, 
해당 선언을 한 클래스 내의 멤버에 자유롭게 접근 가능 

friend 키워드를 사용할 때는 자유롭게 접근하고자 하는 대상인 
클래스의 필드에 friend 키워드를 사용하여 접근자 함수, 객체를 선언

*/

/*

<전방선언> forward declaration

나중에 등장 할 객체를 미리 선언하여 알려준다거나, 
어떠한 클래스에서 특정한 클래스에 대한 정보가 필요하여 상호작용할 때 사용 
단, 코드를 읽거나 디버깅할 때 불편할 수 있다. 

*/
class A;

class B
{
private:
	int m_value = 2;

	//friend void doSomething(A &a, B &b);

public:
	// 전방선언을 해도 함수 내 A의 멤버 변수에 대한 정보가 없어 오류가 발생하므로, 
	// 해당 멤버 함수의 선언과 정의를 분리하여 정의는 클래스 A의 선언 뒤의 위치로 옮기면 오류 해결 
	void doSomething(A &a);

};

class A
{
private:
	int m_value = 1;

	// 클래스 B의 선언은 아래에 나오므로 B에 대한 정보가 없음. 이럴 경우 전방선언 사용 
	//friend void doSomething(A &a, B &b);

	// B 클래스를 friend로 선언 (B 클래스에서 A 클래스 멤버에 자유롭게 접근 가능) 
	//friend class B;

	// B 클래스에서 모두 접근할 수는 없고 특정 함수를 통해서만 접근 가능하게 설정
	// 근데 이렇게 할 경우, 전방선언을 했어도 doSomething 함수에 대한 정보는 없기 때문에 오류 발생
	friend void B::doSomething(A &a);
};

void B::doSomething(A &a)
{
	cout << a.m_value << endl;
}

// doSomething 함수가 A, B 객체의 멤버에 모두 접근해야 할 경우 두 객체 모두에 friend 키워드로 함수 선언 
//void doSomething(A &a, B &b)
//{
//	cout << a.m_value << " " << b.m_value << endl;
//}

//void doSomething(A &a)
//{
//	cout << a.m_value << endl; 
//}

int main()
{
	A a; 
	B b; 

	//doSomething(a, b);

	b.doSomething(a);

	return 0;
}