#include<iostream>
using namespace std; 

int pow(int base, int exponent)
{
	int result = 1; 

	for (int count = 0; count < exponent; count++)
	{
		result *= base; 
	}

	return result;
}

int main()
{
	//반복 횟수가 정해져 있는 경우에 사용하기 좋다. 

	//for (int count = 0; count < 10; count++)
	//{
	//	cout << count << endl; 
	//}

	int count = 0;

	//조건문을 작성하지 않으면 무한루프를 돌게 됨. 
	//for (;;)
	//{
	//	cout << count << endl; 
	//}

	cout << pow(2, 7) << endl;

	//for (int i = 10; count >= 0; count--)
	//{
	//	cout << count << endl; 
	//}

	//for문의 조건문 내에서 조건에 사용할 변수를 여러 개 사용하는 것도 가능 
	//조건식에도 i와 j를 함께 사용할 수 있음. 
	//for (int i = 0, j = 0; i < 10; i++, j--)
	//{
	//	cout << i << " " << j << endl; 
	//}

	//for (int i = 0, j = 0; (i + j) < 10; i++, j += 2)
	//{
	//	cout << i << " " << j << endl; 
	//}

	//잘못된 예제 
	//unsigned(부호가 없는) 변수이므로 0까지만 올바른 값을 담을 수 있다.
	//0에서 i--를 하게 되면 예측할 수 없는 값이 나오므로 조건검사가 제대로
	//진행되지 않아서 무한루프에 빠지게 된다. 
	//for (unsigned int i = 10; i >= 0; i--)
	//{
	//	cout << i << endl; 
	//}

	//반면 조건검사에서 i값이 0이 될때 조건이 false가 되어
	//for문이 종료되므로 i값이 음수로 내려가지 않기 때문에 함수 정상 작동 
	for (unsigned int i = 10; i > 0; i--)
	{
		cout << i << endl;
	}
}