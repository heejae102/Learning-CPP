#include<iostream>
#include<cmath>
using namespace std; 

int main()
{
	double x; 

	/*
	
	goto�� 

	lable ��ġ�� �����س��� ��� ���ǿ� ���� 
	�ش� lable�� ��ġ�� �̵� 

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

	//skip ��ɿ� ���� y������ �������� ���� ä�� 
	//skip lable�� �̵��ϱ� ������ ���� �߻�  
	//goto skip;

	int y = 5;

skip:

	y += 3;

	return 0;
}