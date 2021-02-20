#include<string>
#include<cstddef>
#include<locale>
#include<iostream>
using namespace std; 

int main()
{
	// c-style string example 
	{
		char *strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "Hello!");
		std::cout << strHello << std::endl;
	}

	// basic_string<>, string, wstring
	{
		// string 과 wstring 모두 basic_string<> 템플릿의 인스턴스
		// 단, string은 char, wstring은 wchar_t 로 인스턴스화 

		string str;
		wstring wstr;

		// 캐릭터형 데이터는 원래 데이터 범위가 작은데 반해, 
		// wchar_t는 short 데이터형 범위만큼 커버가능하므로 
		// wide-character, unicode(특히 국제어) 표현 시에 사용 
		wchar_t wc;
	}

	//wstring example
	{
		const std::wstring texts[] =
		{
			L"안녕하세요?",
			L"こんにちは。"
		};
	
		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale());

		for (size_t i = 0; i < 11; i++)
		{
			std::wcout << texts[i] << std::endl;
		}
	}

	return 0;
}