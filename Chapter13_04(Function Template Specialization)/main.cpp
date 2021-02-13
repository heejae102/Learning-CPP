#include<iostream>
#include"Storage.h"
using namespace std; 

/*

<함수 템플릿 특수화>

템플릿 프로그래밍 시 특수한 자료형에는 다른 기능을 
구현하고 싶을 때 사용하는 것. 

*/

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// getMax라는 templatized 된 함수가 있는데, 
// 특수한 경우 (char형에 대해 instantiation되는 경우) 에는 
// 아래 함수로 빌드하도록 하는 것. 
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing char" << endl; 

	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(1, 2) << endl;

	// 내부적으로는 이러한 방식으로 작동
	// cout << getMax<int>(1, 2) << endl; 
	
	// 매개변수로 들어오는 타입 대신 개별적으로 타입을 지정할 경우 
	// cout << getMax<double>(1, 2) << endl; 

	//=======================================================================//

	Storage<int> nValue(5);
	Storage<double> dValue(3.14);

	nValue.print();
	dValue.print();

	return 0;
}