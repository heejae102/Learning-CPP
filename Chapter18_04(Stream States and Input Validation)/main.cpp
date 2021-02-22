#include<iostream>
#include<cctype>
#include<string>
#include<bitset>
using namespace std; 

/*

<흐름 상태와 입력 유효성 검증>

printCharacterClassification 함수 내 
라이브러리 함수 확인하 것. 

*/

void printCharacterClassification(const int &i)
{
	cout << boolalpha;

	// 아래 함수들은 <cctype> 헤더 내에 들어있음. 
	cout << "isalpha " << bool(std::isalpha(i)) << endl;
	cout << "isalnum " << bool(std::isalnum(i)) << endl;
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;

}

// stream은 콘솔 input/output, filestream 모두 사용 가능
void printState(const std::ios& stream)
{
	cout << boolalpha;

	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;		// end of file : 파일을 다 읽었나 
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

bool isAllDigit(const string &str)
{
	bool ok_flag = true;

	// str 내의 모든 문자를 검사하여 숫자인지 확인

	for (auto e : str)
	{
		if (!std::isdigit(e))
		{
			ok_flag = false;
			break;
		}
	}

	return ok_flag;
}

int main()
{
	while (true)
	{
		//int i;
		char i;
		cin >> i;

		// 입력된 값이 올바른 값인지 확인하는 함수
		printState(cin);

		cout << boolalpha;
		cout << std::bitset<8>(cin.rdstate()) << endl;
		cout << std::bitset<8>(std::istream::goodbit) << endl;
		cout << std::bitset<8>(std::istream::failbit) << endl;
		cout << !bool((cin.rdstate()&std::istream::failbit) != 0) << endl;

		// 내가 원하는 문자인지 확인 
		printCharacterClassification(i);

		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
	}

	cout << boolalpha;

	// string으로 입력받아 숫자인지 확인 

	cout << isAllDigit("1234") << endl;
	cout << isAllDigit("a1234") << endl;

	return 0;
}