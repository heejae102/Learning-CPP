#include<iostream>
#include<cmath>
using namespace std; 

int main()
{
	//관계 연산자 

	//int x, y;
	//cin >> x >> y;
	//cout << "Your input values are : " << x << " " << y << endl; 

	//if (x == y) cout << "equal" << endl; 
	//if (x != y) cout << "not equal" << endl; 
	//if (x > y) cout << "x is greater than y" << endl; 
	//if (x < y) cout << "x is less than y" << endl; 
	//if (x >= y) cout << "x is greater than or equal to y" << endl; 
	//if (x <= y) cout << "x is less than or equal to y" << endl; 

	/*
	
	부동소수점을 비교할 때 오류가 자주 발생 
	
	*/

	double d1(100 - 99.99);	//0.01
	double d2(10 - 9.99);	//0.01

	//출력할 때는 같은 값으로 뜨지만 미세한 오차값으로 인해 
	//연산자를 통해 비교할 때는 같은 값으로 인식되지 않음. 
	cout << d1 << endl; 
	cout << d2 << endl; 

	if (d1 == d2) cout << "equal" << endl; 
	else
	{
		cout << "not equal" << endl; 

		if (d1 > d2) cout << "d1 > d2" << endl;
		else cout << "d2 > d1" << endl; 
	}

	//특정한 오차 범위에서는 같은 값으로 인식하도록 하고 싶다면 
	//오차범위를 정해놓고 두 숫자를 뺀 절대값이 오차범위 내라면 같게 인식하도록 조건을 줄 것. 
	const double epsilon = 1e-10;

	if (std::abs(d1 - d2) < epsilon) cout << "Approximately equal" << endl; 
	else cout << "Not equal" << endl; 

	return 0;
}