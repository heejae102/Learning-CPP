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
	// 아래의 예외처리 방식들은 일반적인 방식들로, 특히 네트워크 서버, 게임 서버 등
	// 예측하기 어려운 동작들이 많이 발생하는 상황에서 예외처리를 많이 사용

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

	// <try, catch, throw 예외처리>
	
	// 전통적인 예외처리 방법과 혼용하여 사용 
	// 전통적인 방법보다 퍼포먼스가 떨어지는 측면이 있어서 
	// 프로그램에 따라 알맞은 예외처리 방법을 선택해서 사용할 것. 

	double x;
	cin >> x; 

	// 입력되는 값 x의 SquareRoot(제곱근)을 구하는 함수 
	// ※ 입력되는 값이 0보다 작을 경우 제곱근을 구할 수 없다. 

	// 1. try : 문제가 생길 여지가 있는 부분을 try 영역 내에 집어넣기. 
	try
	{
		// 2. throw : x 가 0보다 작을 경우 에러 메시지("Negative Input"), 예외 던지기 
		// 자동 캐스팅이 안되기 때문에 해당 형식 그대로 입력해야 함. 
		// throw "Nagativie Input"; -> 이렇게 입력할 시 string이 아닌 문자열이므로 오류 발생 
		if (x < 0.0) throw std::string("Negative Input");

		cout << std::sqrt(x) << endl; 
	}

	// 3. catch : 해당 에러 메시지를 받아서 대응하는 동작 수행  
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

	// try에서 throw되는 타입에 따라 해당 자료형에 맞는 catch 영역 실행 
	// catch 괄호 영역 내 타입과 throw되는 자료형이 맞지 않을 경우 
	// 자동으로 타입 캐스팅이 이뤄지는 것이 아니라 오류가 발생하므로 유의할 것. 

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