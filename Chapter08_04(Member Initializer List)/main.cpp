#include<iostream>
using namespace std; 

/*

<생성자의 멤버 이니셜라이저 리스트> Member Initializer List 

*/

class B
{
private:
	int _b;

public:
	B(const int &b) : _b(b) {}
};

class Something
{
private:
	// 클래스의 필드 내에서도 멤버 변수 값(not-static 멤버)을 초기화할 수 있다. 
	// 필드 내에서 변수를 초기화하고, 멤버 초기화 리스트도 사용할 경우 
	// 멤버 초기화 리스트의 우선순위가 높기때문에 최종 값은 멤버 리스트로 초기화한 값이 설정된다. 
	int _i = 10;
	double _d = 1.11;
	char _c = 'c';
	int _arr[5]{ 10,20,30,40,50 };

	B _b; 

public:
	//유니폼 초기화 형식으로도 멤버 초기화 리스트를 작성 가능하나 자동 형변환X
	//Something() : _i{ 1 }, _d{ 3.14 }, _c{ 'a' }
	//{
	//	_i = 1;
	//	_d = 3.14;
	//	_c = 'a';
	//}

	Something() : _i(1), _d(3.14), _c('a'),
		_arr{ 1, 2, 3, 4, 5 }, _b(_i - 1)
	{
		// 멤버 초기화 리스트에서 값을 초기화하고, 생성자 함수 내에서도 값을 초기화할 경우
		// 멤버 변수의 최종 값은 생성자 함수 내에서 초기화한 값으로 설정된다. 
		// 생성자 함수는 진정한 의미에서의 초기화라기보다는 대입의 개념에 가까우므로 
		// 생성자 리스트가 먼저 실행된 후에 생성자 함수에서 값을 초기화(대입)하는 것. 

		_i *= 3;
		_d *= 3.0;
		_c = 'c';
	}

	void print()
	{
		cout << _i << " " << _d << " " << _c << endl; 

		for (auto &element : _arr)
		{
			cout << element << " ";
		}
		cout << endl; 
	}
};

int main()
{
	Something sth;
	sth.print();

	return 0;
}