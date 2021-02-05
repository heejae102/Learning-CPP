#include<iostream>
#include<cassert>
using namespace std; 

/*

<복사 생성자>

자기자신(객체)과 똑같은 타입의 인스턴스를 매개변수로 받는 생성자

*/

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	Fraction(int num = 0, int den = 1)
		: _numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

	// copy constructor (복사 생성자)
	// 보안 상 문제 등의 이유로 복사 생성자를 외부에서 사용하는 것을 막아야 하는 경우
	// private 접근지정자로 설정해주면 된다. 
	Fraction(const Fraction &fraction)
		: _numerator(fraction._numerator), _denominator(fraction._denominator)
	{
		cout << "Copy Constructor Called" << endl; 
	}

	friend std::ostream &operator << (std::ostream &out, const Fraction &f)
	{
		out << f._numerator << " / " << f._denominator << endl;
		return out; 
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	
	cout << &temp << endl; 
	return temp;
}

int main()
{
	Fraction fraction(3, 5);


	// 복사 생성자, 복사 초기화 모두 복사 생성자가 호출된다. 

	//Fraction fr_copy1(fraction);		// copy constructor 
	//Fraction fr_copy2 = fraction;		// copy initialization

	// 임시 객체를 사용하는 경우 복사 생성자가 생략된다. 
	// 즉, 복사 생성자가 불필요한 경우 최적화를 위해 컴파일러에서 생략 처리 
	Fraction fr_copy3(Fraction(1, 3));
	
	cout << fr_copy3 << endl; 


	//-----------------------------------------------------------------//


	// 함수에서 생성 후 copy initialization을 거치면서 복사 생성자 호출 (Debug 모드)
	// 하지만, 빌드 모드를 release로 바꾸면 복사 생성자가 호출되지 않는다. 
	// 리턴 밸류가 함수를 벗어나면 유지 될 필요가 없으므로,
	// 리턴 밸류가 result에 바로 옮겨진다. => 반환값 최적화(Return Value Optimization)

	// 따라서 Debug 모드에서는 함수 내 객체의 주소와 리턴으로 넘겨받은 객체의 주소가 다르지만,
	// Release 모드에서는 함수 내 객체의 주소와 리턴으로 넘겨받은 객체의 주소가 일치한다. 

	Fraction result = doSomething();
	
	cout << &result << endl; 
	cout << result << endl; 

	return 0; 
}