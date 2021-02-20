#include<iostream>
#include<cmath>
using namespace std; 

int main()
{
	double x; 

	/*
	
	goto문 

	lable 위치를 설정해놓고 어떠한 조건에 따라 
	해당 lable위 위치로 이동 

	*/

tryAgain :	// lable

	cout << "Enter a non-negative number" << endl; 
	cin >> x; 

	if (x < 0.0)
	{
		goto tryAgain;
	}

	cout << sqrt(x) << endl; 

//---------------------------------------------------//

	//skip 명령에 의해 y변수를 선언하지 않은 채로 
	//skip lable로 이동하기 때문에 오류 발생  
	//goto skip;

	int y = 5;

skip:

	y += 3;

	return 0;
}