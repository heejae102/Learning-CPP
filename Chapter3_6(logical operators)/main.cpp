#include<iostream>
using namespace std; 

int main()
{
	/*
	
	logical not : ! 
	뒤에 오는 값의 반대 값을 반환(true일 경우 false) 
	
	logical and : A && B
	A와 B의 값이 모두 true일 때만 true를 리턴 

	logical or : A || B 
	A와 B의 값 중 하나라도 true라면 true를 리턴 

	*/

	//bool x = true; 
	//bool y = false; 

	//cout << !x << endl; 
	//cout << (x && y) << endl; 

	//! 연산자 사용 시 연산자 우선순위 주의 
	//(!x == y)   : (!x) == y 의 의미 
	//(!(x == y)) : !(x == y) 의 의미 

	/*
	
	단축 평가(Short Circuit Evaluation)
	
	&& 혹은 || 연산에 있어서 결과가 확실하게 예측이 되었을 때,
	뒤의 나머지 연산을 실행하지 않고 답을 리턴하는 경우 
	(비교 연산자는 왼쪽 항을 먼저 계산하고 오른쪽 항을 계산하는 순서)

	&& : 왼쪽 항의 연산에서 false가 먼저 나와버리면 뒤에 나오는 연산 생략 
	|| : 왼쪽 항의 연산에서 true가 먼저 나와버리면 뒤에 나오는 연산 생략 
	
	*/

	int x = 1;
	int y = 2; 

	if (x == 1 && y++ == 2)
	{
		//do something
	}

	cout << y << endl; 

	//왼쪽 항의 결과가 true일 때  : y의 결과값이 3
	//왼쪽 항의 결과가 false일 때 : y의 결과값이 2

	//왼쪽 항을 계산할 때 false 값이 나오면 오른쪽 항을 계산하지 않고 값을 리턴 

	/*
	
	※ 비교 연산자 &&와 ||를 혼용해서 사용할 때의 주의점 
	
	&&가 ||보다 연산자 우선순위가 높기 때문에
	개별적으로 ()를 사용해서 우선순위를 조정해주지 않으면 &&부터 연산 
	
	*/

	bool v1 = true; 
	bool v2 = false; 
	bool v3 = false; 

	bool r1 = v1 || v2 && v3;
	bool r2 = v1 || (v2 && v3);
	bool r3 = (v1 || v2) && v3;

	cout << r1 << endl; 
	cout << r2 << endl; 
	cout << r3 << endl; 

	cout << std::boolalpha;
	cout << 1 << endl; 
	cout << static_cast<bool>(1) << endl;
	cout << static_cast<bool>(0) << endl << endl;

	cout << ((true && true) || false) << endl;
	cout << ((false && true) || true) << endl; 
	cout << ((false && true) || false || true) << endl; 
	cout << ((14 > 13 || 2 > 1) && (9 > 1)) << endl; 
	cout << !(2314123 > 2 || 123123 > 2387) << endl; 




	cout << std::noboolalpha;



	return 0;
}