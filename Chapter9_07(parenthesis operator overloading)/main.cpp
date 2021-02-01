#include<iostream>
using namespace std; 

/*

<괄호 연산자 오버로딩>

괄호 연산자는 특징 상 함수를 호출하는 괄호를 사용하므로,
함수객체처럼 사용할 수 있음. 

*/

class Accumulator
{
private:
	int _counter = 0;

public:
	int operator() (int i)
	{
		// counter 에 i 값을 더한 뒤 리턴하는 형식 
		return (_counter += i);
	}
};

int main()
{
	Accumulator acc;

	// 마치 함수를 사용하는 것과 비슷한 형태로, 이를 'functor'라고 부름.

	cout << acc(10) << endl; 
	cout << acc(20) << endl; 

	return 0;
}