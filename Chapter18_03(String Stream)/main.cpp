#include<iostream>
#include<sstream>
using namespace std; 

int main()
{
	// << : insertion operator 
	// >> : extraction operator 

	stringstream os;

	// stringstream�� �������ڵ� ���� ���� 

	// 1. ���ۿ� "" �� ���ڸ� �����̴� ����
	//os << "Hello, World!";			// insertion operator ����Ͽ� ���
	//os << "Hello, World!" << endl;
	
	// 2. ���۸� "" ���ڷ� ��ü�ϴ� ���� (������ ����ִ� ���ڿ��� �����.)
	//os.str("Hello, World!\n");

	string str; 
	
	// ���鹮�ڰ� ������ ���鹮�� ���Ĵ� �߷��� ��. 
	//os >> str; 

	// ���鹮�� ������� ���ڸ� ��°�� ������. 
	str = os.str();

	// 1. string�� ���ۿ� ��� ���ڿ��� �����Ͽ� ���
	cout << str << endl; 

	// 2. ���� ��ü���� string�� ������ ��� 
	cout << os.str() << endl;


	//=======================================================================//


	int i = 12345;
	double d = 67.89;

	os << i << " " << d;

	os.str("12345 67.89");	// ���ڸ� ���ڷ� ����

	string str1;
	string str2;

	// ���ۿ� ���鹮�ڰ� ���� ��� �̸� �������� ���ڸ� ������ extract
	//os >> str1 >> str2;
	//cout << str1 << " | " << str2 << endl;


	// ���ۿ� ���� ����(���ڿ�, ���� �� �Ǽ��� ��� ����)�� �ٽ� ���ڷ� �ޱ� 

	int i2;
	double d2;

	os >> i2 >> d2;
	cout << i2 << " | " << d2 << endl;


	//=======================================================================//


	// stringstream ���� 

	os.str("");			// ���鹮�ڷ� �ʱ�ȭ�Ͽ� ���. 
	os.str(string());
	//os.clear();		// state�� ����� �Լ�. (stringstraem�� �� ������� X)

	cout << os.str() << endl;

	return 0;
}