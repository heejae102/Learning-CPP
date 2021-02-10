#include<iostream>
#include<vector>
#include<functional>
using namespace std;

/*

<객체 잘림과 reference_wrapper>

▶ 객체 잘림

일반적으로 부모 클래스보다는 자식 클래스에서 더 많은 데이터를 가지는데, 
만약 보다 작은 규모의 부모 객체에 보다 큰 규모의 자식 객체를 강제로 대입 할 경우
부모 객체가 담을 수 있는 메모리 크기가 더 적으므로 
자식 클래스에만 있는 정보들은 잘려나가게 된다. 

*/

class Base
{
public:
	int _i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl; 
	}
};

class Derived : public Base
{
public:
	int _j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl; 
	}
};

//void doSomething(Base &base)
//{
//	base.print();
//}

/*

함수의 파라미터를 받는 경우에도, 객체의 주소를 받아 참조하는 것이 아니라
값을 받아 복사하는 경우 객체 잘림 현상 발생 

*/

void doSomething(Base base)
{
	base.print();
}

int main()
{
	Derived derived;
	//Base &base = derived;

	/*
	
	주소로 참조하는 것이 아니라 대입으로 값을 받아 복사하게 될 경우,
	base의 메모리 크기가 derived보다 작기 때문에 메모리 잘림 현상 발생.

	자식 클래스에 있는 변수나 함수에 접근할 수 없는 것뿐 아니라, 다형성도 사라진다.
	메모리가 잘려나가면서 자식 클래스의 함수를 실행하기 위한 추가적인 변수들도 사라지면서
	오로지 base에 있는 함수들만 실행할 수 있으므로 다형성도 사라지게 된다. 
	
	*/

	//Base base = derived;
	//base.print();

	//========================================================================//

	// <벡터 사용 시 객체 잘림 현상>
	
	// 객체의 주소가 아닌 값을 원소로 가지는 벡터의 경우, 
	// 원소 타입을 부모 객체로 하고 자식 객체를 원소로 넣을 경우 객체잘림현상 발생 
	// 값이 아닌 객체의 주소를 원소 타입으로 할 경우 문제 해결 
	// (※ 래퍼런스를 사용해도 문제가 해결될 수 있겠지만, 벡터의 원소로 래퍼런스 사용 불가능)

	Base b; 
	Derived d; 

	//std::vector<Base> my_vec;
	//my_vec.push_back(b);
	//my_vec.push_back(d);

	std::vector<Base*> my_vec;
	my_vec.push_back(&b);
	my_vec.push_back(&d);

	for (auto &element : my_vec)
	{
		//element.print();
		element->print();
	}

	//========================================================================//

	// 래퍼런스와 같은 원소를 가지는 벡터 만들기 

	// 헤더파일 <functional> 추가 
	// Base의 래퍼런스를 원소로 저장하는 벡터 
	// std::vector<Base&> v; 이와 같이 작동 (실제로는 래퍼런스를 원소로 사용 불가능)
	std::vector<std::reference_wrapper<Base>> v;
	v.push_back(b);
	v.push_back(d);

	for (auto &element : v)
		element.get().print();

	return 0;
}