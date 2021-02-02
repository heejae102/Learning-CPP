#include<iostream>
#include<cassert>
using namespace std; 

/*

<변환 생성자 >

파라미터 값을 알아서 변환해서 객체 생성 
explicit 키워드를 사용할 경우 변환 생성자가 작동하지 않는다. 

explicit : 해당 키워드를 생성자 앞에 사용할 경우, 
		   변환 생성자가 작동하지 않는다.

delete : 이전 버전에서는 허용했지만 새 버전에서는 
		 허용하지 않는 경우에 보통 사용 

*/

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	// 매개변수에 char형 변수를 입력받는 것을 허용하지 않는다는 의미 
	// 버전업을 하면서, 사람들이 이전과 같은 방식으로 사용할 것을 염려하거나,
	// 자동 변환, 자동 캐스팅이 염려되어서 사용하기도 한다. 
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1)
		: _numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

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

void doSomething(Fraction frac)
{
	cout << frac << endl; 
}

int main()
{
	Fraction frac(7);

	doSomething(frac);			// 복사 생성자 호출. 
	doSomething(Fraction(7));	// 임시 객체를 사용해서 복사 생성자가 생략됨. 


	// doSomething의 매개변수 Fraction에 7을 파라미터로 
	// 넣어서 초기화한 것처럼 작동 
	// explicit 키워드를 사용할 경우 변환 생성자가 작동하지 X

	//doSomething(7);			// 변환 생성자가 작동하는 경우 

	// delete 키워드로 char형 매개변수를 받지 않도록 선언했으므로, 오류 발생 
	//Fraction f('c');

	return 0;
}