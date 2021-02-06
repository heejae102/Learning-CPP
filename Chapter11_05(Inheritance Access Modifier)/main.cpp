#include<iostream>
using namespace std; 

/*

<상속과 접근 지정자>

상위 클래스의 필드 내 접근 지정자 

public    : 자식 클래스 및 외부에서 클래스 멤버에 접근가능
protected : 자식 클래스에서만 클래스 멤버에 접근 가능  
private   : 자식 클래스 및 외부에서 클래스 멤버에 접근 불가능


상속 시의 접근 지정자 

클래스 상속 시 부모 클래스 멤버의 접근 지정자의 경우 
필드 내 접근 지정자와 상속 시의 접근 지정자를 비교하여, 
더 엄격한 제한자를 기준으로 하도록 변경한다. 

쉽게 말해서, 상속 시에 지정해주는 접근 지정자를 토대로
자식 클래스에서 부모 클래스의 접근 지정자를 재설정하여 사용하는 것이라고 보면 된다. 

public    : 필드 내 접근 지정자 그대로 접근가능  
protected : 필드 내 접근 지정자의 범위를 protected 까지로 제한 (public -> protected)
privated  : 필드 내 접근 지정자의 범위를 모두 private 으로 제한 (public, protected -> private)


*/

class Base
{
// 필드 내 접근지정자 
public:
	int _public;

protected:
	int _protected;

private:
	int _private;

};

class Derived : private Base	// 상속 시의 접근 지정자 
{
public:
	Derived()
	{
		/*
		
		private 접근 지정자로 클래스를 상속받을 경우, 
		부모 클래스의 public, protected 멤버를 private 접근 지정자로 변경하여 
		상속받기 때문에 자식 클래스 내에서 접근할 수 없을 것 같지만 그렇지 않다. 
		
		자식 클래스 내에서 해당 멤버를	 private 지정자로 선언한 것과 
		마찬가지이기 때문에, 부모 클래스에서 private 키워드로 선언된 멤버를 
		제외하면 모두 접근이 가능하다. 

		단, 이렇게 부모 클래스를 private 지정자로 상속받은 자식 클래스를
		다른 클래스에서 다시 상속받게 될 경우, 자식 클래스에서는 private 지정자로
		부모 클래스의 멤버를 선언한 것과 마찬가지이기 때문에
		해당 부모 클래스의 멤버에 대한 접근이 불가능하다. 

		*/

		_public = 123;
		_protected = 456;
		//_private = 789;	// 부모 클래스 내에서 private 으로 선언되었기 때문에 접근 불가능 
	}
};

int main()
{
	//Base base;
	//base._public = 123;
	
	Derived derived;

	// protected 접근 지정자로 상속을 받을 경우,
	// 부모 클래스 내 public 변수도 해당 접근지정자로 변경하여 상속받기 때문에  
	// 자식 클래스를 제외한 클래스 외부에서 접근 불가능 

	//derived._public = 123;	 

	return 0;
}