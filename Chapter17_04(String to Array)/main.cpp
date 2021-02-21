#include<iostream>
#include<string>
using namespace std; 

/*

<string ���� �����ϱ�� �迭���� ��ȯ>

*/

int main()
{
	string my_str("abcdefg");

	// �迭ó�� �ε����� ���� ���� (��, �ش� ���ڿ� ���� ���� �ε����� ���� ����)

	// str[n]    : ó�� �ӵ��� ������, ����ó���� ��ġ�� ����. (�����ս���)
	// str.at(n) : ó�� �ӵ��� ���� ������, ����ó��(throw)�� ��ģ��. (��������)  

	cout << my_str[0] << endl; 
	cout << my_str[3] << endl; 
	cout << my_str.at(0) << endl;
	cout << my_str.at(3) << endl;

	my_str[3] = 'Z';

	cout << my_str << endl; 


	//=====================================================================//


	// C-style ���ڿ��� ��ȯ 

	cout << my_str.c_str() << endl; 

	const char *arr = my_str.c_str();
	//const char *arr = my_str.data();	// str.c_str() �� ���� ����� �ϴ� �Լ� 

	// char������ ��ȯ ��, ���ڿ��� ���� NULL ���ڰ� �ٴ´�. 
	cout << (int)arr[6] << endl; 
	cout << (int)arr[7] << endl; 


	// �������� char �����Ϳ� ���� �����ϱ� 

	char buf[20];

	// ��, ����� ������ NULL ĳ���Ͱ� �ڵ����� �߰����� �ʱ� ������
	// ���������� �߰����־�� �� ���ڿ��� ������ ���� ���� �ʴ´�. 
	my_str.copy(buf, 7, 0);
	buf[7] = '\0';			// ���ڿ��� �������� NULL ĳ���� �߰� 
	
	cout << buf << endl; 

	return 0;
}