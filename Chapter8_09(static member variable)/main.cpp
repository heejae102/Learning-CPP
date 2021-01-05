#include<iostream>
using namespace std;

/*

<정적 멤버 변수>

*/

class Something
{
public:
	// static 멤버 변수는 초기화 불가능 
	//static int _value = 1;
	static int _value;

	// static const 멤버 변수는 초기화가 가능하나 값 변경이 불가능
	static const int c_value = 5;
	
	// static const expression 멤버 변수는 컴파일 타임에 값이 결정되어야 한다. (일반은 런타임에도 가능)
	static constexpr int s_value = 1; 

};

// define in cpp (정의는 한 곳에만 있어야 하므로 cpp 파일에 선언해야 한다. 헤더 파일에 둘 경우 오류 발생)
int Something::_value = 1;

int generateID()
{
	// static으로 선언하여 함수가 끝나도 사라지지 않고 유지
	static int s_id = 0;
	return ++s_id;
}

int main()
{
	cout << generateID() << endl; 
	cout << generateID() << endl;
	cout << generateID() << endl;

	// static은 정적으로 존재하기 때문에 인스턴스화하지 않아도 이미 메모리에 할당되어있어 사용 가능
	cout << &Something::_value << " " << Something::_value << endl; 

	Something st1;
	Something st2; 

	st1._value = 2; 

	cout << &st1._value << " " << st1._value << endl; 
	cout << &st2._value << " " << st2._value << endl; 

	// 인스턴스를 통하지 않고도 값 변경 가능 
	Something::_value = 1024;
	cout << &Something::_value << " " << Something::_value << endl;

	return 0; 
}