#include<iostream>
using namespace std; 

/*

<함수 포인터>

함수도 변수와 마찬가지로 주소를 가지고 있다. 
포인터 변수를 통해 변수를 가리키던 것과 마찬가지로
함수도 포인터를 통해 주소를 가리킬 수 있다. 

*/

int func()
{
	return 5;
}

int main()
{
	//함수의 주소 출력 
	cout << func << endl; 

	//함수를 호출하면 함수의 메모리 주소를 찾아서 
	//해당 주소 내에 있는 코드를 실행 
	func();

	//선언 및 초기화 
	int(*fcnptr)() = func;

	return 0;
}