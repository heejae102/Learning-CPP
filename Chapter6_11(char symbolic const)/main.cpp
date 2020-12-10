#include<iostream>
using namespace std; 

//함수의 리턴 타입으로도 사용 가능 
const char* getName()
{
	return "Jane Doe";
}

int main()
{
	//char name[] = "Jane Doe";
	
	//오른쪽은 리터럴(상수)이고, 왼쪽은 포인터 
	//"Jane Doe"가 담긴 메모리 주소가 없기 때문에 포인터에 집어넣을 수 x
	//포인터는 변수의 주소를 가리킬 수만 있음. 
	
	//※ 단, 변수 앞에 const를 붙여서 해당 리터럴을 기호적인 상수처럼 사용할 수 있음
	//char *name = "Jane Doe";
	const char *name = "Jane Doe";
	const char *name2 = "Jane Doe";

	//리터럴의 경우 같은 원소를 가진 경우 메모리 주소를 공유
	cout << (uintptr_t)name << endl; 
	cout << (uintptr_t)name2 << endl; 

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";

	//int 배열의 변수명은 주소, 문자열의 포인터 혹은 변수명은 문자열을 출력 
	//즉, 문자의 포인터는 cout으로 출력 시 특별한 방식으로 작동
	cout << int_arr << endl; 
	cout << char_arr << endl; 
	cout << name << endl; 

	//문자의 주소를 출력하려고 하면 문자열을 출력하는 줄 알고 
	//NULL을 만날때까지 출력하려고 하지만, c는 단일문자라 
	//NULL을 포함하고 있지 않기 때문에 오류 발생 
	char c = 'Q';
	cout << &c << endl; 
	cout << *(&c) << endl; 

	return 0;
}