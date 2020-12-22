#include<iostream>
using namespace std; 

/*

<생성자> constructor

함수명이 클래스명과 같으며, 반환 데이터 타입이 없는 멤버함수 
생성자는 외부에서 명시적으로 호출하면서 사용하는 것이 아님. 
생성자는 객체가 생성되면서 자동적으로 실행되는 함수이다. 
따라서 객체 내의 멤버변수들을 초기화하는데 보통 사용된다. 

생성자를 따로 명시적으로 구현하지 않을 경우,
아무 기능을 하지 않는 디폴트 생성자가 자동으로 호출된다. 
생성자를 1개라도 구현할 경우 디폴트 생성자는 호출되지 않는다. 

생성자는 기본적으로 public으로 선언되어야 사용할 수 있지만, 
private으로 선언해서 사용하는 프로그래밍 기법도 존재한다. 

※ 클래스 내에서 다른 클래스를 멤버 변수로 선언 시, 
클래스를 생성했을 때 해당 멤버 변수의 생성자가 먼저 호출된다. 
해당 변수를 사용하기 위해서는 해당 값이 먼저 초기화되어야하므로 어찌보면 당연함. 

*/

class Fraction
{
private:
	int _numerator;
	int _denominator; 

public:
	// 매개변수에 디폴트 밸류를 설정하는 것도 가능 
	// 디폴트 밸류는 매개변수의 오른쪽에서 왼쪽 순으로 
	// 중간에 빠지는 값 없이 설정해주어야 한다. 

	//디폴트 매개변수 사용 시 주의해야 할 점은, 
	//모든 매개변수 값을 입력하는 경우의 수와 디폴트 매개변수를 제외한 값들만
	//입력하는 경우의 수들이 존재하므로 다른 생성자들이 해당 경우의 수와
	//겹치지 않도록 해주어야 한다는 점이다. 
	//ex) 아래 생성자는 디폴트 매개변수가 2개로 0~2개의 매개변수를 입력하는 경우의 수가 존재한다. 
	//해당 경우의 수와 겹치는 다른 매개변수가 있는 경우 생성자 호출 시 ambiguity 오류가 발생. 
	Fraction(const int &num_input = 1, const int &den_input = 1)
	{
		_numerator = num_input;
		_denominator = den_input;

		cout << "Fraction() constructor" << endl;
	}

	void print()
	{
		cout << _numerator << " / " << _denominator << endl; 
	}
};

class Second
{
public:
	Second()
	{
		cout << "Second constructor called" << endl; 
	}
};

class First
{
private:
	Second second; 

public:
	First()
	{
		cout << "First constructor called" << endl; 
	}
};

int main()
{
	// ※ 생성자 함수에 매개변수가 없는 경우, 함수와 헷갈릴 수 있기 때문에
	// 객체 생성 시 괄호를 사용하지 못하도록 제한되어 있다. 
	// Fraction frac();	사용 불가 X 

	Fraction frac(1);
	frac.print();

	//copy initialization을 통해 초기화하는 것도 가능 
	//복사 생성자와 임시객체 모두 사용한 예시 
	Fraction test = Fraction{ 1,3 };

	/*
	
	{} uniform initialization과 
	() 괄호를 사용한 initialization의 차이 

	{} : 멤버 변수가 public이라면, 유니폼 초기화로 생성자 없이 값 초기화 가능 
	     생성자가 있을 경우 {}를 사용해도 생성자를 호출해준다.
		 단, 유니폼 초기화 사용 시 데이터 타입의 변환을 허용하지 않는다. (자동변환 안됨)
		 즉 괄호를 사용해서 초기화할 때보다 더 엄격한 방식. 

	() : 생성자가 있을 경우 ()를 사용해서 호출. 
	     유니폼 초기화와 달리 데이터 타입의 변환을 허용한다. 
	
	*/

	//Fraction one_thirds{ 1.0,3 };	//데이터 타입 변환 불가능
	Fraction one_thirds(1.0, 3);	//데이터 타입 변환 가능 

	First first; 

	return 0; 
}