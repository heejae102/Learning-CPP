#include<iostream>
#include<iomanip>
using namespace std; 

/*

<ostream���� ����ϱ�>

*/

int main()
{
	/*
	
	<���� ������ ���� ��� ���>

	1. cout.setf(std::ios::hex);

	�ش� �ڵ� ��� �� ���� ����ϴ� ���� unsetf �ؾ� ��. 
	
	cout.setf(std::ios::oct) : ���ڸ� 8������ ���
	cout.setf(std::ios::dec) : ���ڸ� 10������ ��� 
	cout.setf(std::ios::hex) : ���ڸ� 16������ ��� 

	cout.unsetf(std::ios::oct) : 8���� ��� ���� 
	cout.unsetf(std::ios::dec) : 10���� ��� ���� 
	cout.unsetf(std::ios::hex) : 16���� ��� ���� 


	2. cout.setf(std::ios::hex, std::ios::basefield);

	�ش� �ڵ� ��� �� unsetf ���� �ʰ� ��� ���� 


	3. cout << std::hex; 

	cout << std::hex;
	cout << std::oct; 
	cout << std::dec;

	16 ��� �� ���ĺ��� �ҹ��ڰ� ����Ʈ 

	cout.setf(std::ios::uppercase); ȣ�� �� �빮�ڷ� ���
	cout << std::hex << std::uppercase; �� ���� 

	*/


	// + ��� ��ȣ ��� 
	cout.setf(std::ios::showpos);
	cout << 108 << endl;
	cout << 110 << endl;

	// + ��� ��ȣ ���� 
	cout.unsetf(std::ios::showpos);
	cout << 108 << endl;


	//===================================================================//


	// bool �� �����͸� 1/0�� �ƴ� ���� true/false�� ���  

	cout << std::boolalpha;
	cout << true << " " << false << endl; 


	//===================================================================//


	// ������ �ڸ��� ��� 

	//cout << std::defaultfloat;	// �Ҽ� ��� ����Ʈ�� 

	// std::setprecision(n) : n�ڸ� ��ŭ ��� 
	// std::scientifix		: ������ ���� ǥ�� (�ҹ��ڰ� e ���) 
	// std::fixed;			: �Ҽ��� �ڸ��� �������� ǥ�� 
	// std::showpoint		: �Ҽ��� ��� 

	// fixed, setprecision �Բ� ��� �� �Ҽ��� �ڸ� ���� n�ڸ� ������ ��� 
	// cout << std::scientific << std::uppercase; ȣ�� �� �빮�� E ��� 

	cout << fixed;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;


	//===================================================================//


	// ���� ���� 

	cout.fill('*');	// ������ �ش� ��ȣ�� ä���. 
	cout << -12345 << endl;
	cout << std::setw(10) << -12345 << endl; 
	cout << std::setw(10) << std::left << -12345 << endl; 
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;	// ��ȣ�� ���� ���� ��ĭ

	return 0;
}