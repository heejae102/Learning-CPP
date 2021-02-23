#include<iostream>
#include"MyConstants.h"
using namespace std; 

int value = 123;
//int a = 1;

//void doSomething()
//{
//	static int a = 1; 
//	++a; 
//	cout << a << endl; 
//}

//test함수를 main cpp파일에서도 사용하기 위해 전방 선언(extern 생략 가능)
extern void test();
extern int a;

int main()
{
	//:: 콜론 2개만 사용하면 global scope operator 전역 연산자 

	//cout << value << endl; 

	//int value = 1;

	//cout << ::value << endl; 
	//cout << value << endl; 

	/*
	
	global variable 

	static duration variable 
	
	
	global 변수 vs static 변수 

	1) static 변수 
	static 변수는 메모리가 정적으로 선언된다. 
	처음 static 변수를 선언 할 때 반드시 초기화되어야 한다. 

	메모리적 관점에서 어떤 스코프 내에서 반복적으로 할당이 되어 
	사용하는 메모리를 정적으로 선언하여 같은 메모리를 재사용한다. 

	디버깅 할 때 예를 들자면 함수가 몇 번 호출됐는지 
	확인하는 등에 사용하면 유용하다. 


	2) global 변수 
	static 변수와 흡사하게 기능 
	하지만 여기저기서 접근이 가능하므로 추적이 어렵고 디버깅이 어려워짐.
	객체지향 설계 시 반드시 필요한 경우는 제외하고 사용을 지양하는 것이 좋다. 

	*/

	//doSomething();
	//doSomething();
	//doSomething();
	//doSomething();

	/*
	
	linkage

	지역 변수의 경우 해당 스코프를 벗어나면 사라지고, 스코프 내에서만 
	작용하기 때문에 다른 객체들과 링킹할 필요가 없음 

	
	internal linkage 

	개별 cpp 파일 안에서만 전역으로 작동하는 전역 변수 
	(cpp 파일 내에서 전역 변수를 static으로 선언하는 경우)


	external linkage

	다른 cpp 파일 내에서도 접근할 수 있는 전역 변수 
	변수를 extern 키워드(보통 생략됨)를 사용해서 전방 선언
	extern 변수를 여러번 초기화할 수 없음. 

	각각의 cpp파일에서 따로 헤더파일을 두고 사용할 경우 서로 주소가 다른 객체가 생성 
	(서로 다른 객체를 생성하지 않아도 되는 경우 메모리 낭비 발생 )

	extern 키워드를 사용하면 메모리를 한 곳에서만 차지하고 
	같은 주소의 데이터가 반복해서 사용되어 메모리 낭비를 막을 수 있음.

	*/

	/*
	
	<정리>

	int g_x;			// external linkage 
	static int g_x		// internal linkage
	
	
	<forward declaration> 

	extern int g_z;
	extern const int g_z;
	

	int g_y(1);
	static int g_y(1);
	const int g_y(1);


	extern int g_w(1);
	extern const int g_w(1);
	*/

	//test();
	//cout << a << endl; 

	cout << "In main.cpp file" << Constants::pi << " " << &Constants::pi << endl; 
	test();

	return 0;
}