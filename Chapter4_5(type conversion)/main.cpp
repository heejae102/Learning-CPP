#include<iostream>
#include<iomanip>
#include<typeinfo>
using namespace std; 

int main()
{
	/*
	
	암시적 형변환(Implicit type conversion) = coersion
	
	프로그래머가 따로 요청하지 않았지만 컴파일러가 자동으로 변환하는 경우 
	
	ex1) int a = 123.0;
	123.0은 더블형이지만 a의 자료형은 int이므로 
	123.0을 int형으로 변환하여 값을 저장 

	ex2) numeric promotion : 작은 크기의 자료형에서 더 큰 자료형으로 변환 
	float a = 1.0f;
	double b = a; 

	ex) numeric conversion : 큰 크기의 자료형에서 더 작은 자료형으로 변환
	
	더 큰 메모리 공간을 가진 데이터를 작은 메모리 공간에 집어넣음으로써 
	만약 해당 데이터의 메모리 크기가 집어넣고자 하는 메모리 공간보다 큰 경우 
	데이터가 절삭되거나 예측할 수 없는 값이 저장되는 등 오류 발생 

	short s = 2(int); 

	형변환에도 우선순환이 있다. 
	4byte보다 작은 자료형(char, short)은 무조건 int로 변환
	
	그 다음은 아래의 순서와 같다. 
	int, unsigned int, long, unsigned long 
	long long, unsigned long long, float, double, long double 

	주의할 점은 signed형 변수형보다 unsigned형 변수가 우선순위가 높다는 점. 


	명시적 형변환(Explicit type conversion) = casting 
	
	프로그래머가 명시적으로 변환하도록 명령하는 것. 

	*/

	//괄호 안에 들어오는 자료의 데이터 타입을 출력하는 함수 
	//cout << typeid(4.0).name() << endl; 

	//int a = 123;

	//cout << typeid(a).name() << endl; 

	//numeric promotion
	int j = 2; 
	char d = j;

	//numeric conversion 
	int i = 30000;
	char c = i;

	double g = 0.123456789;
	float f = g; 

	//실수형 값을 정수형 변수에 집어넣으면 소수점 아래 값을 절삭하고 저장

	cout << static_cast<int>(c) << endl; 
	cout << static_cast<int>(d) << endl; 
	cout << setprecision(12) << f << endl; 

	//explicit type conversion(casting)
	//C스타일 캐스팅 
	int num1 = (int)4.0;

	//C++스타일 캐스팅
	int num2 = int(4.0);

	//변환할 수 있는 타입인지 확인하여 캐스팅 
	int num3 = static_cast<int>(4.0);

}