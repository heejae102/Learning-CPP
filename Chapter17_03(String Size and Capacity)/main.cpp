#include<iostream>
#include<string>
using namespace std; 

int main()
{
	string my_str("012345678");

	// string�� Ŭ���� �������, ���ڿ��� �������� NULL�� ���Ե��� X  
	cout << my_str.size() << endl;	// 9 

	cout << std::boolalpha;
	cout << my_str.empty() << endl;	// ���ڿ��� ����ִ��� Ȯ�� 

	my_str = "";
	cout << my_str.empty() << endl; // "" �� ���ڿ��� ��� true 


	//==================================================================//


	string str("01234567");

	cout << std::boolalpha;
	
	// length �� size �� ����. 
	cout << str.length() << endl; 
	cout << str.size() << endl;

	// �����Ϸ��� OS ��Ȳ�� ���� �ٸ� �� ������, string�� vector�� ����������
	// ���Ҵ��ϴ� ��Ȳ�� ���ϱ� ����(���� ��� �߻�) ������ �뷮�� �д�. 
	// capacity�� ���� �뷮�� ������ �޸�. 
	cout << str.capacity() << endl; 
	
	// ���� �뷮�� ���� �Ҵ��ϴ� ���  
	str.reserve(1000);
	cout << str.capacity() << endl; 

	// str �� �ִ� �뷮. 
	cout << str.max_size() << endl; 

	return 0;
}