#include<iostream>
#include<regex>
using namespace std; 

/*

<정규 표현식 소개>

Regular Expressions

입력받은 데이터가 특정한 형식에 맞게 입력되었는지 
검증하는 데 유용하게 사용할 수 있는 라이브러리 함수 

*/

int main()
{
	// regular expression

	// \\d : 1자리 숫자 하나를 digit(숫자)인지 판별
	regex re("\\d");

	// \\d+ : 1자리 수 이상의 숫자가 digit(숫자)인지 판별
	//regex re("\\d+");

	// [[:digit:]]    : digit이면 true 
	// [[:digit:]]{n} : digit이고 n자리 수까지 true (012, 345, 678)
	// 입력된 수를 n자리 단위로 잘라서 출력 
	//regex re("[[:digit:]]{3}");
	
	// [A-Z]+ : 알파벳 A-Z까지, 1자리 수 이상이면 true
	//regex re("[A-Z]+");

	// [A-Z]{1, 5} : 알파벳 A-Z까지, 최소 1자리, 최대 5자리 수라면 true
	//regex re("[A-Z]{1, 5}");

	// 0-9 숫자 1개 이상 / - 있거나 없어도 됨 / 0-9 숫자 1개 이상 4개 이하 true 
	//regex re("([0-9]{1})([-]?)([0-9]{1,4})");

	string str; 

	while (true)
	{
		// getline으로 문자열 한 줄을 입력 받음. 
		getline(cin, str);

		// 정의된 regex 구문을 검사하여 match 하는지 결과를 리턴 
		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match" << endl;

		// Print Matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
		
			for (auto itr = begin; itr != end; itr++)
			{
				std::smatch match = *itr;
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}