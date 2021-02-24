#include<iostream>
using namespace std; 

int getPrice(int onSale)
{
	if (onSale) return 10;
	else return 100; 
}

int main()
{
	//<sizeof 연산자> 
	//sizeof는 함수가 아닌 연산자 
	//sizeof() 괄호 안에 들어오는 대상의 메모리 크기 값을 반환
	//변수와 데이터 타입 모두 () 안에 들어갈 수 있다.
	//사용자 정의 자료형이나 네트워크 관리에도 사용 
	//변수명이 뒤에 올 때는 괄호 없이도 사용 가능 

	float num;
	sizeof(float);
	sizeof(num);
	sizeof num; 

	/*
	
	콤마 연산자(comma operator)  

	반복문(for문)에서는 콤마 연산자를 많이 사용 
	
	*/

	// 왼쪽 항을 계산하고, 오른쪽 항을 계산하여 오른쪽 항의 계산 값을 변수에 집어넣는다.
	int x = 3; 
	int y = 10;
	//int z = (++x, ++y);

	//풀어쓰면 이런 구조 
	++x;
	++y;
	int z = y;

	//아래 문장에서 콤마는 단순 나열을 구분하는 용도 
	int a = 1, b = 10;
	
	
	//콤마 연산자는 대입 연산자보다 우선순위가 낮기 때문에 대입 연산이 먼저 발생. 
	//(z = a) b; 형태로 연산이 된 것. 
	//결과값으로 10을 얻고 싶은 경우 괄호를 사용할 것. 
	int c;
	c = a, b;			//결과 : 1
	c = (a, b);			//결과 : 10

	c = (a++, a + b);	//결과 : 12
	cout << c << endl; 


	/*
	
	조건부 연산자(=삼항 연산자)
	conditional operator, arithmetic if

	const형 변수를 선언할 때 if문 대신 사용하면 편리하다. 
	단, 조건부가 단순할 때만 사용하는 것이 좋다. 
	구조가 복잡해지는 경우에는 읽거나 디버깅하기 불편할 수 있다. 

	*/

	bool onSale = true; 
	//int price; 

	//if (onSale) price = 10;
	//else price = 100; 

	//그런데 만약 price를 const형으로 선언한다면, if문은 사용할 수 없음.
	//price를 const형으로 쓰고 싶다면 삼항연산자를 사용하면 됨. 
	const int price = (onSale == true) ? 10 : 100;

	//굳이 if문을 사용하면서 const형으로 선언하고 싶다면 함수를 사용할 것. 
	//const int price = getPrice(onSale);

	int n = 5;
	
	//연산자 우선순위때문에 오류 발생 (<< 쉬프트 연산자가 : 조건 연산자보다 우선순위가 높음)
	//이런 경우에는 괄호를 사용해서 직접 우선순위를 조정해줄 것. 
	cout << ((n % 2 == 0) ? "even" : "odd") << endl;

	return 0; 
}
