#include<iostream>
#include<iomanip>
#include<typeinfo>
using namespace std; 

int main()
{
	/*
	
	�Ͻ��� ����ȯ(Implicit type conversion) = coersion
	
	���α׷��Ӱ� ���� ��û���� �ʾ����� �����Ϸ��� �ڵ����� ��ȯ�ϴ� ��� 
	
	ex1) int a = 123.0;
	123.0�� ������������ a�� �ڷ����� int�̹Ƿ� 
	123.0�� int������ ��ȯ�Ͽ� ���� ���� 

	ex2) numeric promotion : ���� ũ���� �ڷ������� �� ū �ڷ������� ��ȯ 
	float a = 1.0f;
	double b = a; 

	ex) numeric conversion : ū ũ���� �ڷ������� �� ���� �ڷ������� ��ȯ
	
	�� ū �޸� ������ ���� �����͸� ���� �޸� ������ ����������ν� 
	���� �ش� �������� �޸� ũ�Ⱑ ����ְ��� �ϴ� �޸� �������� ū ��� 
	�����Ͱ� ����ǰų� ������ �� ���� ���� ����Ǵ� �� ���� �߻� 

	short s = 2(int); 

	����ȯ���� �켱��ȯ�� �ִ�. 
	4byte���� ���� �ڷ���(char, short)�� ������ int�� ��ȯ
	
	�� ������ �Ʒ��� ������ ����. 
	int, unsigned int, long, unsigned long 
	long long, unsigned long long, float, double, long double 

	������ ���� signed�� ���������� unsigned�� ������ �켱������ ���ٴ� ��. 


	����� ����ȯ(Explicit type conversion) = casting 
	
	���α׷��Ӱ� ��������� ��ȯ�ϵ��� ����ϴ� ��. 

	*/

	//��ȣ �ȿ� ������ �ڷ��� ������ Ÿ���� ����ϴ� �Լ� 
	//cout << typeid(4.0).name() << endl; 

	//int a = 123;

	//cout << typeid(a).name() << endl; 

	//numeric promotion
	int j = 2; 
	char d = j;

	//numeric conversion 
	int i = 30000;
	char c = i;

	double g = 0.123456789;
	float f = g; 

	//�Ǽ��� ���� ������ ������ ��������� �Ҽ��� �Ʒ� ���� �����ϰ� ����

	cout << static_cast<int>(c) << endl; 
	cout << static_cast<int>(d) << endl; 
	cout << setprecision(12) << f << endl; 

	//explicit type conversion(casting)
	//C��Ÿ�� ĳ���� 
	int num1 = (int)4.0;

	//C++��Ÿ�� ĳ����
	int num2 = int(4.0);

	//��ȯ�� �� �ִ� Ÿ������ Ȯ���Ͽ� ĳ���� 
	int num3 = static_cast<int>(4.0);

}