#include<iostream>
#include<sstream>
using namespace std; 

int main()
{
	// << : insertion operator 
	// >> : extraction operator 

	stringstream os;

	// stringstream에 개간문자도 포함 가능 

	// 1. 버퍼에 "" 내 문자를 덧붙이는 형태
	//os << "Hello, World!";			// insertion operator 사용하여 출력
	//os << "Hello, World!" << endl;
	
	// 2. 버퍼를 "" 문자로 교체하는 형태 (이전에 담겨있던 문자열은 사라짐.)
	//os.str("Hello, World!\n");

	string str; 
	
	// 공백문자가 있으면 공백문자 이후는 잘려서 들어감. 
	//os >> str; 

	// 공백문자 상관없이 문자를 통째로 가져옴. 
	str = os.str();

	// 1. string에 버퍼에 담긴 문자열을 저장하여 출력
	cout << str << endl; 

	// 2. 버퍼 자체에서 string을 가져와 출력 
	cout << os.str() << endl;


	//=======================================================================//


	int i = 12345;
	double d = 67.89;

	os << i << " " << d;

	os.str("12345 67.89");	// 숫자를 문자로 저장

	string str1;
	string str2;

	// 버퍼에 공백문자가 있을 경우 이를 기준으로 문자를 나눠서 extract
	//os >> str1 >> str2;
	//cout << str1 << " | " << str2 << endl;


	// 버퍼에 넣은 숫자(문자열, 정수 및 실수형 모두 가능)를 다시 숫자로 받기 

	int i2;
	double d2;

	os >> i2 >> d2;
	cout << i2 << " | " << d2 << endl;


	//=======================================================================//


	// stringstream 비우기 

	os.str("");			// 공백문자로 초기화하여 비움. 
	os.str(string());
	//os.clear();		// state를 지우는 함수. (stringstraem을 다 비우지는 X)

	cout << os.str() << endl;

	return 0;
}