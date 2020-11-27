#include<iostream>
using namespace std;

int main()
{
	/*

	나머지 연산자 : %

	정수의 나머지 계산
	실수의 나머지 계산

	*/

	int x = 7;
	int y = 4;

	//나누기 연산에서 이항(x,y) 중 하나라도 실수형이면 결과값이 실수형 
	cout << x / y << endl;					//정수 
	cout << (float)x / y << endl;			//실수 
	cout << x / (float)y << endl;			//실수 
	cout << (float)x / (float)y << endl;	//실수 


	//정수와 정수 사이의 나누기 연산에서 이항 중 음의 정수가 있는 경우 
	//C++11부터는 결과값에서 실수 값을 버려 절삭하여 정수형으로 만드는 형식

	cout << -5 / 2 << endl;			//결과값 : -2
	cout << float(-5) / 2 << endl;	//결과값 : -2.5


	//나머지 연산에서 이항 중 음의 정수가 있는 경우 
	//왼쪽에 있는 항의 숫자가 음수인 경우 나머지 값도 음수
	//왼쪽에 있는 항의 숫자가 양수인 경우 나머지 값도 양수 

	cout << -5 % 2 << endl;		//-1
	cout << -5 % -2 << endl;	//-1

	cout << 5 % 2 << endl;		//+1
	cout << 5 % -2 << endl;		//+1
}