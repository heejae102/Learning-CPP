#include<iostream>
using namespace std; 

/*

<���� ���ε��� ���� ���ε�>

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

	// ���� ���ε� 
	// ��� ������ �� �Լ����� ���� Ÿ�ӿ� ������ �Ǿ� �ִ� ��.
	// ��Ÿ�� �߿� ������ �� ���� ���� Ÿ�ӿ� ������ �ǹǷ� �������ε����� �ӵ� �鿡�� ���. 

	int result;

	switch (op)
	{
		case 0: result = add(x, y); break;
		case 1: result = subtract(x, y); break;
		case 2: result = multiply(x, y); break;
	}

	//============================================================================//

	// Dynamic Binding (Late Binding)

	// ���� ���ε� 
	// ���ô� input�Ǵ� op���� ���� �Լ� �����Ϳ� �� �Լ��� �������� ������, 
	// �� ��Ÿ�� �߿� �ԷµǴ� �Ϳ� ���� ���� �� �Լ��� �޶����� ��.
	// �ӵ����� ���鿡���� ������ ����������, ���α׷��� �������� �������� ���� �� �ִ�. 

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