#include<iostream>
#include<string>
using namespace std; 

/*

class를 const형으로 선언 한 경우

1. 해당 클래스 내 멤버변수 변경 불가
2. const형으로 선언된  멤버 함수만 호출 가능
3. 함수 내부에서 멤버 값을 변경하지 않더라도 함수가 const형으로 선언되지 않았을 경우 호출 불가
4. const형으로 선언된 함수라고 할지라도 내부 코드에 멤버 변수값을 변경하는
내용이 있을 경우 해당 함수는 호출 불가능 (애초에 컴파일 단계에서 오류)
5. 멤버함수를 const형으로 선언할 수 있는 경우, const형으로 선언하는 것이 오류 방지에 유리 

*/

class Something
{
public:
	int _value = 0;
	 
	/*
	
	<Copy Constructor>
	
	- 같은 클래스의 객체를 매개변수로 받아 객체를 초기화하는 것.  
	- 디폴트 생성자가 존재하듯 디폴트 복사 생성자도 존재 
	- 생성자가 존재하더라도 복사생성자가 정의되어있지 않을 경우, 
	디폴트 복사 생성자가 자동으로 호출되어 멤버 대 멤버 복사 진행 
	
	*/
	//원래 디폴트 생성자가 존재하듯이, 
	//디폴트 복사 생성자가 숨겨져 있음. 
	Something(const Something &input)
	{
		_value = input.getValue();

		cout << "Copy Constructor" << endl; 
	}

	Something()
	{
		cout << "Constructor" << endl; 
	}

	void setValue(int value) { _value = value; }
	int getValue() const { return _value; } 
};

// 매개변수로 객체를 받으면서 복사 생성자 호출 
// 새로 만들어서 매개변수로 넘어온 객체를 복사한 것이므로 
// 원 객체의 주소와 함수 내 객체의 주소는 서로 다름. 
//void print(Something sth)
//{
//	cout << &sth << endl; 
//	cout << sth._value << endl; 
//}

// 복사 생성자를 통해 새 객체를 만드는 것은 성능이 떨어지므로 
// 래퍼런스를 통해 매개변수로 넘어오는 객체 자체를 참조하는 것이 성능적으로 우수 (주소 일치)
void print(const Something &sth)
{
	cout << &sth << endl;
	cout << sth._value << endl;
}

class Test
{
public:
	string _value = "default";

	// 함수의 const형 유무에 따라 함수 오버로딩 가능 
	// 보통 함수를 const형으로 선언할 경우 리턴형도 const로 선언하는 것이 일반적  
	const string &getValue() const 
	{
		cout << "Const Version" << endl; 

		return _value; 
	}

	string& getValue() 
	{
		cout << "Non-const Version" << endl; 

		return _value; 
	}
};

int main()
{
	const Something sth;

	//sth.setValue(3);

	// getValue 함수를 const형으로 선언하지 않았을 때는 오류 발생 
	//cout << sth.getValue() << endl; 
	//cout << &sth << endl; 
	//print(sth);

	// 멤버 함수를 const 유무에 따라 오버로딩한 경우 
	// const형으로 선언된 클래스에서는 const형 함수 호출 
	// 그렇지 않은 경우 non-const형 함수 호출 

	Test test1; 
	cout << test1.getValue() << endl; 

	const Test test2;
	test2.getValue();

	return 0;
}