#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

/*

<std::string 의 여러가지 생성자들과 형변환>

*/

template <typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;
	osstream << x; 

	// 입력되는 값이 무엇이든 전부 string 형으로 변환하여 리턴
	return osstream.str();
}

template <typename T>
bool FromString(const std::string &str, T &x)
{
	// 인풋 스트링 스트림을 str 을 넣어서 초기화 
	std::istringstream isstream(str);

	// str을 템플릿 x의 데이터형으로 변경 
	return (isstream >> x) ? true : false;
}

int main()
{
	// 자주 사용하는 std::string 의 생성자 

	// 괄호 안에 들어오는 문자열로 값을 초기화 
	//const char* my_string = "my string";
	std::string my_string("my string");

	// 매개변수로 들어오는 문자열로 값을 초기화  
	//std::string second_string(my_string);

	// 첫 번째 매개변수로 들어온 문자열을 
	// 두 번째 매개변수(3)의 위치에서부터 복사하여 값을 초기화 
	//std::string second_string(my_string, 3);

	// 첫 번째 매개변수로 들어온 문자열을 두 번째 매개변수(3)의 위치에서부터 
	// 세 번째 매개변수(3)의 크기만큼 복사하여 값을 초기화 
	std::string second_string(my_string, 3, 3);
	std::cout << second_string << std::endl;

	// 두 번째 매개변수(A)를 첫 번째 매개변수 사이즈만큼 초기화 
	std::string thrid_string(10, 'A');
	std::cout << thrid_string << std::endl;

	// iterator 반복자로 초기화 
	std::vector<char> vec;
	for (auto e : "Today is a good day.")
	{
		vec.push_back(e);
	}

	//string forth_string(vec.begin(), vec.end());
	string forth_string(vec.begin(), find(vec.begin(), vec.end(), ' '));
	cout << forth_string << endl; 


	//====================================================================//


	// std::string 의 형변환 

	// 숫자를 문자열로 변환 (ex. int -> string)

	string str(to_string(1004));

	str += to_string(128);

	cout << str << endl; 

	// 문자열을 숫자로 변환 (ex. string -> int)

	int i = stoi(str);
	cout << i << endl; 

	float f = stof(str);
	cout << f << endl; 

	str = ToString(3.141592);
	cout << str << endl; 

	double d; 

	// string을 char형으로 초기화한 경우, 
	// double 형으로 형변환이 불가능하기 때문에 else 구문의 명령이 실행된다. 
	if (FromString(str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl; 

	return 0;
}