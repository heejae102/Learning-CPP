#include<iostream>
#include<cstdlib>

int main()
{

	std::cout << "I love you" << std::endl; 

	//함수 종료 제어문 
	//return과 달리 코드의 어디에 있든, 엑싯코드만 넣어주면 함수를 종료할 수 있다. 
	//엑싯코드에 들어오는 데이터 타입과 상관없이 함수를 무조건 종료 
	//프로그램이 무조건 종료되어야 할 경우에 사용 
	//디버깅할 때 프로그램 분석 시에 사용하는 경우가 종종 있음. 
	exit(0);

	//정상적으로 값을 리턴하고 함수를 종료하는 의미 
	//return은 return 타입에 맞게 return을 반환해주어야 문법적으로 문제 없이 컴파일 됨.
	return 0;
}