#include <iostream>
#include "MY_CONSTANTS.h"
using namespace std;

void printNumber(const int &num)
{
	int n = num;

	cout << num << endl;
}

int main()
{
	/*

	<Symbolic Constants>

	일반적인 경우에는 const의 위치가 상관없지만, 보통 "const type 변수명" 으로 사용
	상수는 한번 값이 정해지면 바꿀 수 없기 때문에 반드시 선언과 동시에 초기화해주어야 함.
	const형은 보통 함수의 파라미터(매개변수)에 자주 사용됨.
	함수 내에서 파라미터 값을 바꾸는 경우가 드물고, 다른 사용자가 함수 내에서
	파라미터의 값을 바꾸는 것을 방지하기 위해서 파라미터를 const형으로 선언하여 값을 고정.

	*/

	//double const gravity(9.8);
	const double gravity{ 9.8 };

	printNumber(123);

	//컴파일 타임 상수 : 컴파일 할 때 값이 결정 
	//런타임 상수 : 런타임 중 값이 결정 
	//C++11에서 컴파일 타임 상수를 정의할 수 있는 키워드가 생김(constexpr)

	//컴파일 타임 상수 
	const int const_number(123);
	//constexpr int const_number(123);

	//런타임 상수 
	int number;
	cin >> number;

	const int special_number(number);

	/*

	매직넘버 : 코드에서 상수(숫자)를 직접 사용하는 것으로 프로그래밍에서 지양해야 하는 것.

	코드의 가독성이 떨어지고 유지관리가 힘들다.(값 수정 시 일일이 수정해야 함.)

	매직넘버 사용 방지법
	1. 매크로 사용(전처리기 define)
	- cpp에서는 상수를 대체하기 위해 매크로를 사용하지 않는 편이다.
	- 이유 1) 디버깅이 힘들기 때문.
	- 이유 2) 전처리기는 cpp 파일 전체에 영향을 미치기 때문에 적용 범위가 너무 넓기 때문.

	2. 심볼릭 컨스턴스 사용
	- 심볼릭 컨스턴스를 사용하면 적용범위를 조정하여 사용 가능
	- 컨스턴스형으로 선언해놓고 일반변수로 변경해서 사용하기도 하므로 특별한 명칭을 사용하지 않는 편.
	- 프로그램에 필요한 컨스턴스형 변수들이 많을 때 헤더파일에 따로 모아놓기도 함.

	*/

	//컨스턴스 헤더파일 사용예시 
	double radius;
	cin >> radius;

	double circumference = 2.0 * radius * constants::pi;

	return 0;
}