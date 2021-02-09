#include<iostream>
using namespace std; 

/*

<동적 바인딩과 정적 바인딩>

*/

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl; 
	cin >> op;

	// Static Binding (Early Binding)

	// 정적 바인딩 
	// 모든 변수명 및 함수명이 빌드 타임에 정리가 되어 있는 것.
	// 런타임 중에 결정할 것 없이 빌드 타임에 결정이 되므로 동적바인딩보다 속도 면에서 우수. 

	int result;

	switch (op)
	{
		case 0: result = add(x, y); break;
		case 1: result = subtract(x, y); break;
		case 2: result = multiply(x, y); break;
	}

	//============================================================================//

	// Dynamic Binding (Late Binding)

	// 동적 바인딩 
	// 예시는 input되는 op값에 따라 함수 포인터에 들어갈 함수가 정해지는 구조로, 
	// 즉 런타임 중에 입력되는 것에 따라 변수 및 함수가 달라지는 것.
	// 속도적인 측면에서는 성능이 떨어지지만, 프로그램의 자유도와 유연성을 높일 수 있다. 

	int(*func_ptr)(int, int) = nullptr;

	switch (op)
	{
		case 0: func_ptr = add; break;
		case 1: func_ptr = subtract; break; 
		case 2: func_ptr = multiply; break; 
	}

	cout << func_ptr(x, y) << endl; 

	return 0;
}