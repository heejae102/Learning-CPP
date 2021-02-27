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

	//2진수  : 0b-
	//8진수  : 0-
	//16진수 : 0x-

	//숫자를 구분하기 위해서 숫자 사이사이 '기호 사용해도 컴파일러가 무시(10진수에도 사용가능)
	int x = 0b1010'0001;
	cout << x << endl;

	return 0;
}