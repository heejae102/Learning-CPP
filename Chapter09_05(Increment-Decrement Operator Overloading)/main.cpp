#include<iostream>
using namespace std; 

/*

<증감 연산자 오버로딩>

증감 연산자는 전위형이냐, 후위형이냐에 따라
동작 방식이 다르므로 그에 맞게 오버로딩하기 

*/

class Digit
{
private:
	int _digit;

public:
	Digit(int digit = 0) : _digit(digit) {}

	// 전위형 (prefix)
	Digit& operator ++ ()
	{
		++_digit;

		// 자기 자신을 리턴 (자기 자신의 참조 값을 리턴하므로 래퍼런스형으로 리턴)
		return *this; 
	}

	// 후위형 (postfix) : 후위형의 경우 파라미터로 더미 데이터를 넣어줌. 
	Digit operator++ (int)
	{
		// 후위형의 경우 일단 리턴을 해준 다음 값을 바꾸는 구조

		Digit temp(_digit);
		//_digit++;

		// 이미 전위형 연산자 오버로딩을 만들었으므로, 해당 방식으로도 가능
		++(*this);

		return temp;
	}

	// 입출력 연산자 오버로딩 
	friend ostream& operator << (ostream &out, const Digit &d)
	{
		out << d._digit;
		return out;
	}
};

int main()
{
	Digit d(5);

	cout << ++d << endl; 
	cout << d << endl; 

	cout << d++ << endl; 
	cout << d << endl; 

	return 0;
}