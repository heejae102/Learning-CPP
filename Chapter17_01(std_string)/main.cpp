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
		// string �� wstring ��� basic_string<> ���ø��� �ν��Ͻ�
		// ��, string�� char, wstring�� wchar_t �� �ν��Ͻ�ȭ 

		string str;
		wstring wstr;

		// ĳ������ �����ʹ� ���� ������ ������ ������ ����, 
		// wchar_t�� short �������� ������ŭ Ŀ�������ϹǷ� 
		// wide-character, unicode(Ư�� ������) ǥ�� �ÿ� ��� 
		wchar_t wc;
	}

	//wstring example
	{
		const std::wstring texts[] =
		{
			L"�ȳ��ϼ���?",
			L"����˪��ϡ�"
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