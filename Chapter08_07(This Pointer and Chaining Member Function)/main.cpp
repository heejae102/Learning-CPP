#include<iostream>
using namespace std; 

/*

<this pointer>

this : 객체 자기 자신을 가리키는 참조자 

this 참조자를 통해 자기자신의 멤버 변수와 멤버 함수에 모두 접근 가능 
객체를 여러 개 의 인스턴스로 사용할 경우, 멤버함수를 그 개수만큼 생성하는 것이 아니라
하나의 함수를 같은 객체들끼리 공유하는 형식으로 사용한다. 

예를 들자면 이런 형식으로 하나의 함수에 해당 인스턴스의 주소와 파라미터를 보내는 형식
하지만 명시적으로 이렇게 사용할 수는 없음. 내부적인 작동방식이 이와 같다는 이야기. 
ex. Simple::setID(&2, 4);

*/

class Simple
{
private:
	int _id;

public:
	Simple(int id)
	{
		//현재 this가 가리키는 주소의 객체가 setID 함수를 사용한다는 의미 
		//this->setID(id);
		//this가 생략된 것.  
		setID(id);
		(*this).setID(id);	// 같은 의미 

		cout << this << endl; 
	}

	void setID(int id) { _id = id; }
	int getID() { return _id; }
};

class Calc
{
private:
	int _value;

public:
	Calc(int init_value) : _value(init_value) { }

	Calc& add(int value) { _value += value; return *this; }
	Calc& sub(int value) { _value -= value; return *this; }
	Calc& mult(int value) { _value *= value; return *this; }

	void print()
	{
		cout << _value << endl; 
	}
};

int main()
{
	Simple s1(1), s2(2);
	cout << &s1 << " " << &s2 << endl; 

	Calc cal(10);
	//cal.add(10);
	//cal.sub(2);
	//cal.mult(5);
	//cal.print();

	/*
	
	<Chaining Member Function>
	
	this 포인터를 이용한 Chaining Member Function을 통해 구현
	실용성에 있어서는 조금 번거롭거나 의문스러운 부분이 있다.
	사용자 입장에서 헷갈릴 수 있고, 가독성도 떨어질 수 있기 때문.
	그래도 이러한 방식으로 작동하는 원리와 사례는 알아둘 것.
	
	*/

	cal.add(5).sub(5).mult(7).print();
	
	//임시 객체를 이용해서도 가능 
	Calc(20).add(10).print();

	return 0;
}