#include<iostream>
#include<exception>
#include<string>
using namespace std;

/*

std::exception

���Ĵٵ� ���̺귯���� ���ԵǾ� �ִ� exception Ŭ���� 
�̹� ���� ó���� �ʿ��� ��ɵ��� �����Ǿ� �����Ƿ� ���ϰ� ��� ����

������� <exception> �� include �Ͽ� ��� 

*/

// ǥ�� ���̺귯�� exception�� ��ӹ޴� �Լ� 
class CustomException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		//std::string s;
		//s.resize(-1);

		// exception �� �ϳ��� ������ ��� ���� 
		//throw std::runtime_error("Bad thing happended");
		throw CustomException();
	}

	//catch (std::length_error &exception)
	//{
	//	std::cerr << "Length_Error" << std::endl;
	//	std::cerr << exception.what() << std::endl;
	//}
	catch (std::exception &exception)
	{
		//std::cout << typeid(exception).name() << std::endl;
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}