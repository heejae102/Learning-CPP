#include<iostream>
#include<string>
#include<limits>
using namespace std; 

int main()
{
	/*
	
	<string> 
	
	�⺻ �ڷ��������� ������ ����� ���� �ڷ����� ���� ��. 
	���ڿ��� �����Ͽ� �ʿ��� ���� �۾����� �⺻������ ���� ��. 
	
	*/

	//const string my_hellow = "Hello, World";
	//const char my_ch[] = "Hello, World";

	//cout << "Hello, World" << endl; 
	//cout << my_hellow << endl; 
	//cout << my_ch << endl; 

	// ���ڸ� ���ڿ��� ������� ���� ������, ���� ��ü�� ����ִ� ���� �Ұ���
	// ������ ���ڿ��� �Ͻ��� ����ȯ ���ִ� ����� ���� ���� 
	//string my_ID = "123"; 

	//cin 
	//cin �Լ��� ����, ��, �����̽��� �������� �Է°��� �����ϰ� 
	//�ʿ��� �Է°����� ū �Է°��� �Է¹��� ��� ������ ���� ������ �ʰ�
	//���ۿ� �����صξ��ٰ� ���� �Է��� ���� �� �ش� ������ ���� ��� 

	//getline
	//getline �Լ��� ���͸� ĥ ������ �ش� ������ �Է°��� ��� ���� 

	//cin���� ���� ���� �Է� ������ �ش� ���� ���ۿ� ����Ǿ� �ִٰ� 
	//���� string �Է� �������� ������. 
	//�ش� ������ �ذ��Ϸ��� �Է��� ���� �� ���ۿ� �ִ� ���� �����ؾ� ��. 

	//cout << "Your age ? : ";
	//int age; 
	//cin >> age; 
	////std::getline(std::cin, age);

	////���1) '\n'(�齽����n, �� ���� �� �����̽� �Է� ��)�� ���������� 32767��ŭ�� �Է°��� ����
	////32767�� 2����Ʈ int�� ǥ�� ������ ���� ū signed ��� ��. 
	//std::cin.ignore(32767, '\n');

	////���2) �����ѹ��� ����ϴ� ���� �ȴٸ� �Է� ���� �ƽ� ���� �����ؼ� ���.
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//cout << "Your name ? : ";
	//std::string name; 
	////cin >> name; 
	//std::getline(std::cin, name);

	////cout << "Your age ? : ";
	////string age; 
	//////cin >> age; 
	////std::getline(std::cin, age);

	//cout << name << " " << age << endl; 

	//string ���̿��� ���ϱ� �����ڸ� ����ϸ� ���ڿ��� ���̴� ��� 

	string a("Hello, ");
	string b("World!");
	string hw = a + b;	//�̷��� ���ڿ� �ڿ� ���ڿ��� ���ϴ� ���� append��� �θ�.
	hw += " I'm good.";

	cout << hw << endl; 

	//���ڿ��� ����� �����ϴ� �Լ� 
	cout << b.size() << endl; 
	cout << b.length() << endl; 

	return 0; 
}