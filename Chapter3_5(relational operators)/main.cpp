#include<iostream>
#include<cmath>
using namespace std; 

int main()
{
	//���� ������ 

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
	
	�ε��Ҽ����� ���� �� ������ ���� �߻� 
	
	*/

	double d1(100 - 99.99);	//0.01
	double d2(10 - 9.99);	//0.01

	//����� ���� ���� ������ ������ �̼��� ���������� ���� 
	//�����ڸ� ���� ���� ���� ���� ������ �νĵ��� ����. 
	cout << d1 << endl; 
	cout << d2 << endl; 

	if (d1 == d2) cout << "equal" << endl; 
	else
	{
		cout << "not equal" << endl; 

		if (d1 > d2) cout << "d1 > d2" << endl;
		else cout << "d2 > d1" << endl; 
	}

	//Ư���� ���� ���������� ���� ������ �ν��ϵ��� �ϰ� �ʹٸ� 
	//���������� ���س��� �� ���ڸ� �� ���밪�� �������� ����� ���� �ν��ϵ��� ������ �� ��. 
	const double epsilon = 1e-10;

	if (std::abs(d1 - d2) < epsilon) cout << "Approximately equal" << endl; 
	else cout << "Not equal" << endl; 

	return 0;
}