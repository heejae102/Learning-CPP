#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); index++)
	{
		if (string[index] == ch)
			return index;
	}

	return -1;	// no match
}

double divide(int x, int y, bool &success)
{
	if (y == 0)
	{
		success = false; 
		return 0.0;
	}

	success = true; 
	return static_cast<double>(x) / y;
}

int main()
{
	// �Ʒ��� ����ó�� ��ĵ��� �Ϲ����� ��ĵ��, Ư�� ��Ʈ��ũ ����, ���� ���� ��
	// �����ϱ� ����� ���۵��� ���� �߻��ϴ� ��Ȳ���� ����ó���� ���� ���

	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cout << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");

	if (!input_file)
		std::cerr << "Cannot open file" << std::endl; 

	//===============================================================================//

	// <try, catch, throw ����ó��>
	
	// �������� ����ó�� ����� ȥ���Ͽ� ��� 
	// �������� ������� �����ս��� �������� ������ �־ 
	// ���α׷��� ���� �˸��� ����ó�� ����� �����ؼ� ����� ��. 

	double x;
	cin >> x; 

	// �ԷµǴ� �� x�� SquareRoot(������)�� ���ϴ� �Լ� 
	// �� �ԷµǴ� ���� 0���� ���� ��� �������� ���� �� ����. 

	// 1. try : ������ ���� ������ �ִ� �κ��� try ���� ���� ����ֱ�. 
	try
	{
		// 2. throw : x �� 0���� ���� ��� ���� �޽���("Negative Input"), ���� ������ 
		// �ڵ� ĳ������ �ȵǱ� ������ �ش� ���� �״�� �Է��ؾ� ��. 
		// throw "Nagativie Input"; -> �̷��� �Է��� �� string�� �ƴ� ���ڿ��̹Ƿ� ���� �߻� 
		if (x < 0.0) throw std::string("Negative Input");

		cout << std::sqrt(x) << endl; 
	}

	// 3. catch : �ش� ���� �޽����� �޾Ƽ� �����ϴ� ���� ����  
	catch (std::string error_message)
	{
		// do something to respond
		cout << error_message << endl; 
	}

	//===============================================================================//

	try
	{
		// something happened;
		throw 123;
	}

	// try���� throw�Ǵ� Ÿ�Կ� ���� �ش� �ڷ����� �´� catch ���� ���� 
	// catch ��ȣ ���� �� Ÿ�԰� throw�Ǵ� �ڷ����� ���� ���� ��� 
	// �ڵ����� Ÿ�� ĳ������ �̷����� ���� �ƴ϶� ������ �߻��ϹǷ� ������ ��. 

	catch (int x)
	{
		cout << "Catch Integer " << x << endl; 
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl; 
	}
	catch (const char* error_message)
	{
		cout << "Catch char* " << error_message << endl; 
	}
	catch (std::string error_message)
	{
		cout << "Catch string " << error_message << endl; 
	}

	return 0;
}