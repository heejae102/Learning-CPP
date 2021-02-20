#include<iostream>
#include<string>
using namespace std; 

int main()
{
	string my_str("012345678");

	// string은 클래스 기반으로, 문자열의 마지막에 NULL이 포함되지 X  
	cout << my_str.size() << endl;	// 9 

	cout << std::boolalpha;
	cout << my_str.empty() << endl;	// 문자열이 비어있는지 확인 

	my_str = "";
	cout << my_str.empty() << endl; // "" 빈 문자열일 경우 true 


	//==================================================================//


	string str("01234567");

	cout << std::boolalpha;
	
	// length 와 size 는 같다. 
	cout << str.length() << endl; 
	cout << str.size() << endl;

	// 컴파일러나 OS 상황에 따라 다를 수 있으나, string도 vector와 마찬가지로
	// 재할당하는 상황을 피하기 위해(많은 비용 발생) 여분의 용량을 둔다. 
	// capacity는 여분 용량을 포함은 메모리. 
	cout << str.capacity() << endl; 
	
	// 여분 용량을 직접 할당하는 경우  
	str.reserve(1000);
	cout << str.capacity() << endl; 

	// str 의 최대 용량. 
	cout << str.max_size() << endl; 

	return 0;
}