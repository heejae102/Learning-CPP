#include<iostream>
#include<exception>
#include<string>
using namespace std;

/*

std::exception

스탠다드 라이브러리에 포함되어 있는 exception 클래스 
이미 예외 처리에 필요한 기능들이 구현되어 있으므로 편리하게 사용 가능

헤더파일 <exception> 을 include 하여 사용 

*/

// 표준 라이브러리 exception을 상속받는 함수 
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

		// exception 중 하나를 가져다 사용 가능 
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