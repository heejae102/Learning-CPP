#include<iostream>
using namespace std; 

//int x, int y : parameters
int test(int x, int y);

int test(int x, int y)
{
	//함수의 파라미터는 지역변수처럼 작용하여 함수가 실행되면서 
	//생성되어 넘겨받은 argument 값을 복사하여 초기화되고, 
	//함수가 끝나면서 다시 사라지는 구조 

	return x + y;
	// x and y are  destroyed here 
}

int main()
{
	int x = 1, y = 2;

	test(6, 7);		//6, 7 : argements (actual parameters)
	test(x, y + 1);

	return 0;
}