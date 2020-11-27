#include<iostream>
using namespace std; 

int main()
{
	/*
	
	logical not : ! 
	�ڿ� ���� ���� �ݴ� ���� ��ȯ(true�� ��� false) 
	
	logical and : A && B
	A�� B�� ���� ��� true�� ���� true�� ���� 

	logical or : A || B 
	A�� B�� �� �� �ϳ��� true��� true�� ���� 

	*/

	//bool x = true; 
	//bool y = false; 

	//cout << !x << endl; 
	//cout << (x && y) << endl; 

	//! ������ ��� �� ������ �켱���� ���� 
	//(!x == y)   : (!x) == y �� �ǹ� 
	//(!(x == y)) : !(x == y) �� �ǹ� 

	/*
	
	���� ��(Short Circuit Evaluation)
	
	&& Ȥ�� || ���꿡 �־ ����� Ȯ���ϰ� ������ �Ǿ��� ��,
	���� ������ ������ �������� �ʰ� ���� �����ϴ� ��� 
	(�� �����ڴ� ���� ���� ���� ����ϰ� ������ ���� ����ϴ� ����)

	&& : ���� ���� ���꿡�� false�� ���� ���͹����� �ڿ� ������ ���� ���� 
	|| : ���� ���� ���꿡�� true�� ���� ���͹����� �ڿ� ������ ���� ���� 
	
	*/

	int x = 1;
	int y = 2; 

	if (x == 1 && y++ == 2)
	{
		//do something
	}

	cout << y << endl; 

	//���� ���� ����� true�� ��  : y�� ������� 3
	//���� ���� ����� false�� �� : y�� ������� 2

	//���� ���� ����� �� false ���� ������ ������ ���� ������� �ʰ� ���� ���� 

	/*
	
	�� �� ������ &&�� ||�� ȥ���ؼ� ����� ���� ������ 
	
	&&�� ||���� ������ �켱������ ���� ������
	���������� ()�� ����ؼ� �켱������ ���������� ������ &&���� ���� 
	
	*/

	bool v1 = true; 
	bool v2 = false; 
	bool v3 = false; 

	bool r1 = v1 || v2 && v3;
	bool r2 = v1 || (v2 && v3);
	bool r3 = (v1 || v2) && v3;

	cout << r1 << endl; 
	cout << r2 << endl; 
	cout << r3 << endl; 

	cout << std::boolalpha;
	cout << 1 << endl; 
	cout << static_cast<bool>(1) << endl;
	cout << static_cast<bool>(0) << endl << endl;

	cout << ((true && true) || false) << endl;
	cout << ((false && true) || true) << endl; 
	cout << ((false && true) || false || true) << endl; 
	cout << ((14 > 13 || 2 > 1) && (9 > 1)) << endl; 
	cout << !(2314123 > 2 || 123123 > 2387) << endl; 




	cout << std::noboolalpha;



	return 0;
}