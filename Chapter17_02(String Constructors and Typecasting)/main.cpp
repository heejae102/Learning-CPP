#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

/*

<std::string �� �������� �����ڵ�� ����ȯ>

*/

template <typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;
	osstream << x; 

	// �ԷµǴ� ���� �����̵� ���� string ������ ��ȯ�Ͽ� ����
	return osstream.str();
}

template <typename T>
bool FromString(const std::string &str, T &x)
{
	// ��ǲ ��Ʈ�� ��Ʈ���� str �� �־ �ʱ�ȭ 
	std::istringstream isstream(str);

	// str�� ���ø� x�� ������������ ���� 
	return (isstream >> x) ? true : false;
}

int main()
{
	// ���� ����ϴ� std::string �� ������ 

	// ��ȣ �ȿ� ������ ���ڿ��� ���� �ʱ�ȭ 
	//const char* my_string = "my string";
	std::string my_string("my string");

	// �Ű������� ������ ���ڿ��� ���� �ʱ�ȭ  
	//std::string second_string(my_string);

	// ù ��° �Ű������� ���� ���ڿ��� 
	// �� ��° �Ű�����(3)�� ��ġ�������� �����Ͽ� ���� �ʱ�ȭ 
	//std::string second_string(my_string, 3);

	// ù ��° �Ű������� ���� ���ڿ��� �� ��° �Ű�����(3)�� ��ġ�������� 
	// �� ��° �Ű�����(3)�� ũ�⸸ŭ �����Ͽ� ���� �ʱ�ȭ 
	std::string second_string(my_string, 3, 3);
	std::cout << second_string << std::endl;

	// �� ��° �Ű�����(A)�� ù ��° �Ű����� �����ŭ �ʱ�ȭ 
	std::string thrid_string(10, 'A');
	std::cout << thrid_string << std::endl;

	// iterator �ݺ��ڷ� �ʱ�ȭ 
	std::vector<char> vec;
	for (auto e : "Today is a good day.")
	{
		vec.push_back(e);
	}

	//string forth_string(vec.begin(), vec.end());
	string forth_string(vec.begin(), find(vec.begin(), vec.end(), ' '));
	cout << forth_string << endl; 


	//====================================================================//


	// std::string �� ����ȯ 

	// ���ڸ� ���ڿ��� ��ȯ (ex. int -> string)

	string str(to_string(1004));

	str += to_string(128);

	cout << str << endl; 

	// ���ڿ��� ���ڷ� ��ȯ (ex. string -> int)

	int i = stoi(str);
	cout << i << endl; 

	float f = stof(str);
	cout << f << endl; 

	str = ToString(3.141592);
	cout << str << endl; 

	double d; 

	// string�� char������ �ʱ�ȭ�� ���, 
	// double ������ ����ȯ�� �Ұ����ϱ� ������ else ������ ����� ����ȴ�. 
	if (FromString(str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl; 

	return 0;
}