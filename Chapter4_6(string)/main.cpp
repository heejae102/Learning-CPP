#include<iostream>
#include<string>
#include<limits>
using namespace std; 

int main()
{
	/*
	
	<string> 
	
	기본 자료형같지만 일종의 사용자 정의 자료형과 같은 것. 
	문자열과 관련하여 필요한 여러 작업들이 기본적으로 제공 됨. 
	
	*/

	//const string my_hellow = "Hello, World";
	//const char my_ch[] = "Hello, World";

	//cout << "Hello, World" << endl; 
	//cout << my_hellow << endl; 
	//cout << my_ch << endl; 

	// 숫자를 문자열로 집어넣을 수는 있지만, 숫자 자체를 집어넣는 것은 불가능
	// 정수를 문자열로 암시적 형변환 해주는 방법이 없기 때문 
	//string my_ID = "123"; 

	//cin 
	//cin 함수는 엔터, 탭, 스페이스를 기준으로 입력값을 구분하고 
	//필요한 입력값보다 큰 입력값을 입력받을 경우 나머지 값을 버리지 않고
	//버퍼에 저장해두었다가 다음 입력을 받을 때 해당 나머지 값을 사용 

	//getline
	//getline 함수는 엔터를 칠 때까지 해당 라인의 입력값을 모두 저장 

	//cin으로 숫자 값을 입력 받으니 해당 값이 버퍼에 저장되어 있다가 
	//다음 string 입력 값에까지 들어가버림. 
	//해당 문제를 해결하려면 입력을 받은 뒤 버퍼에 있는 값을 삭제해야 함. 

	//cout << "Your age ? : ";
	//int age; 
	//cin >> age; 
	////std::getline(std::cin, age);

	////방법1) '\n'(백슬래시n, 즉 엔터 탭 스페이스 입력 값)을 만날때까지 32767만큼의 입력값을 무시
	////32767은 2바이트 int로 표현 가능한 가장 큰 signed 밸류 값. 
	//std::cin.ignore(32767, '\n');

	////방법2) 매직넘버를 사용하는 것이 싫다면 입력 값의 맥스 값을 지정해서 사용.
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

	//string 사이에서 더하기 연산자를 사용하면 문자열을 붙이는 기능 

	string a("Hello, ");
	string b("World!");
	string hw = a + b;	//이렇게 문자열 뒤에 문자열을 더하는 것을 append라고 부름.
	hw += " I'm good.";

	cout << hw << endl; 

	//문자열의 사이즈를 측정하는 함수 
	cout << b.size() << endl; 
	cout << b.length() << endl; 

	return 0; 
}