#include<iostream>
using namespace std; 

/*

<Call by value>

값에 의한 호출 

매개변수로 변수 자체가 아닌 변수의 값을 복사해서 넘기는 것.

doSomething 내 매개변수 y는 함수가 실행될 때 선언되면서,
매개변수로 넘어오는 값을 복사하여 해당 값으로 초기화된다.
즉, 함수 실행 시 매개변수로 넘기는 변수와 y는 별개의 변수이다. 

이러한 방식으로 함수를 실행 시 장점은 함수 내에서 일어나는 연산들이 
함수 바깥에 영향을 미치지 않는다는 것이다. 

*/

void doSomething(int y)
{
	cout << "In func : " << y << " " << &y << endl; 
}

int main()
{
	doSomething(5);

	int x = 6;

	cout << "In main : " << x << " " << &x << endl; 

	//매개변수로 x를 넘길 때 변수 x자체를 넘기는 것이 아니라 
	//변수 x에 담겨있는 값을 넘기는 것이다. 
	doSomething(x);
	doSomething(x + 1);

	return 0;
}