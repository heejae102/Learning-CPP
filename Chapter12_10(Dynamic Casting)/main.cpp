#include<iostream>
#include<string>
using namespace std;

/*

<동적 형변환>

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

class Derived1 : public Base
{
public:
	int _j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl; 
	}
};

class Derived2 : public Base
{
public :
	string _name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl; 
	}
};

int main()
{
	Derived1 d1;
	Base *base = &d1;

	// base는 d1과 달리 Derived1에만 있는 멤버에 접근 불가능 
	// ▼ base를 다시 Derived1 포인터 타입으로 형변환하여 접근 가능  

	auto *base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->_j << endl; 

	// 해당 포인터를 통해 오리지널 값도 수정 가능 
	// 하지만 이렇게 형변환으로 왔다갔다하는 것은 디버깅 시에도 알아보기 힘들고
	// 코드 자체를 복잡하게 만들기 때문에 가급적 virtual - override로 해결하는 것이 좋다. 
	
	base_to_d1->_j = 512;
	cout << d1._j << endl; 

	/*
	
	d1은 애초에 Derived1 타입의 객체였으므로, 이를 Derived2로 
	dynamic cast 하려고 할 경우 캐스팅에 실패하여 NULL 포인터가 반환된다. 

	반면 static cast 를 통해 캐스팅 할 경우, 캐스팅 자체는 성공한다.
	하지만 결국 데이터는 Derived1 객체인 채로 캐스팅만 성공한 것이기 때문에,
	Derived2 객체가 가진 데이터에 접근하려고 하면 문제가 발생한다. 

	따라서, 가급적 상속 관계에서 형변환은 피하는 것이 좋지만, 
	필요한 상황이 생길 경우에는 dynamic cast 를 사용하여 문제가 발생하는 것을
	사전에 방지하는 것이 좋다. 
	
	*/
	
	//auto *base_to_d2 = dynamic_cast<Derived2*>(base);
	auto *base_to_d2 = static_cast<Derived2*>(base);

	if (base_to_d2 == nullptr) cout << "Casting Failed" << endl; 
	else cout << base_to_d2->_name << endl;

	return 0;
}