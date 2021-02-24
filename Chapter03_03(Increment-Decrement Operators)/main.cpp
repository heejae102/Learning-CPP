#include<iostream>
using namespace std; 

int add(const int &a,const int &b)
{
	return a + b;
}

int main()
{
	/*
	
	증감 연산자 
	
	*/

	int x = 6, y = 6;

	//후치 연산자 
	cout << x << " " << y << endl; 
	cout << x++ << " " << y-- << endl; 
	cout << x << " " << y << endl; 

	//전치 연산자 
	cout << x << " " << y << endl; 
	cout << ++x << " " << ++y << endl; 
	cout << x << " " << y << endl; 

	//1. 오류발생의 예시(undefined value 값이 명확하지 않음)
	int z = 1;
	//z = z++; 
	
	//2. 오류발생의 예시(컴파일러에 따라 다른 값이 발생) 
	//넘겨주는 매개변수의 변수가 서로 다른 경우는 ok 
	int num = add(z, ++z);
	cout << num << endl; 

	return 0;
}