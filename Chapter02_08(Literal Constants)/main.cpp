#include<iostream>
using namespace std;

int main()
{
	unsigned int n = 5u;
	long n2 = 5l;
	double d = 6.0e-10;

	//decimal : 0 1 2 3 4 5 6 7 8 9 10
	//octal	  : 0 1 2 3 4 5 6 7 10 11 12
	//hexa    : 0 1 2 3 4 5 6 7 8 9 A B C D E F 10 

	int a = 012;
	cout << a << endl;

	int b = 0xD;
	cout << b << endl;

	//2����  : 0b-
	//8����  : 0-
	//16���� : 0x-

	//���ڸ� �����ϱ� ���ؼ� ���� ���̻��� '��ȣ ����ص� �����Ϸ��� ����(10�������� ��밡��)
	int x = 0b1010'0001;
	cout << x << endl;

	return 0;
}