#include<iostream>
using namespace std; 

/*

<������-�� ���� >

*/

// L/R value�� �Ű������� �޴� ��� �����ε� ���� 
void doSomething(int &lref)
{
	cout << "L-value ref" << endl; 
}

void doSomething(int &&ref)
{
	cout << "R-value ref" << endl; 
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value References 

	int &lr1 = x;		// Modifiable L-values
	//int &lr2 = cx;	// Non-modifiable L-values (const�� �����ʹ� ���۷����� ���� �� x)
 	//int &lr3 = 5;		// R-values (����� ���۷����� ���� �� x)

	const int &lr4 = x;
	const int &lr5 = cx;
	const int &lr6 = 5;

	// R-value References 

	// R-value ���۷����� R ��� ���� ���� �� �ִ�. 

	//int &&rr1 = x;		// Modifiable L-values
	//int &&rr2 = cx;		// Non-modifiable L-values
	int &&rr3 = 5;			// R-values

	//const int &&rr4 = x;	// Modifiable L-values
	//const int &&rr5 = cx;	// Non-modifiable L-values
	const int &&rr6 = 5;	// R-values

	//=======================================================================//

	// L/R-value Reference Parameters

	doSomething(x);
	//doSomething(cx);
	doSomething(5);
	doSomething(getResult());

	return 0;
}