#include<iostream>
#include<string>
using namespace std; 

/*

<std::string �Լ�>

����, ��ȯ, �����̱�, ����

*/

int main()
{

	string str1("one");

	string str2;

	// string ����(assignment)
	str2 = str1;
	str2 = "two";
	str2.assign("two");	// assign �Լ��� �ڱ��ڽ��� ���۷����� ����
	str2.assign("two").append(" ").append("three");	// Chaining Function�� ���� 

	cout << str2 << endl; 

	//===========================================================================//

	// string ��ȯ(swap) 

	cout << "str1 : " << str1 << " " << "str2 : " << str2 << endl;
	
	swap(str1, str2);

	cout << "str1 : " << str1 << " " << "str2 : " << str2 << endl;

	str1.swap(str2);

	cout << "str1 : " << str1 << " " << "str2 : " << str2 << endl;

	//===========================================================================//

	// string �����̱�(append)

	str2.append("four");
	str2 += "four";

	str2 = str1 + "four";
	
	// ����ó�� ���Ҹ� �ִ� ���� �����ϳ�, ���ڿ��� �ƴ� ���Ϲ��ڸ� ���� ' '
	str2.push_back('A');

	cout << str2 << endl;

	//===========================================================================//

	// string ����(insert)

	string str("aaaaa");

	str.insert(2, "bbb");

	cout << str << endl; 

	return 0;
}