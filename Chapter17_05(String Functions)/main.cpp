#include<iostream>
#include<string>
using namespace std; 

/*

<std::string 함수>

대입, 교환, 덧붙이기, 삽입

*/

int main()
{

	string str1("one");

	string str2;

	// string 대입(assignment)
	str2 = str1;
	str2 = "two";
	str2.assign("two");	// assign 함수는 자기자신의 래퍼런스를 리턴
	str2.assign("two").append(" ").append("three");	// Chaining Function이 가능 

	cout << str2 << endl; 

	//===========================================================================//

	// string 교환(swap) 

	cout << "str1 : " << str1 << " " << "str2 : " << str2 << endl;
	
	swap(str1, str2);

	cout << "str1 : " << str1 << " " << "str2 : " << str2 << endl;

	str1.swap(str2);

	cout << "str1 : " << str1 << " " << "str2 : " << str2 << endl;

	//===========================================================================//

	// string 덧붙이기(append)

	str2.append("four");
	str2 += "four";

	str2 = str1 + "four";
	
	// 벡터처럼 원소를 넣는 것이 가능하나, 문자열이 아닌 단일문자만 가능 ' '
	str2.push_back('A');

	cout << str2 << endl;

	//===========================================================================//

	// string 삽입(insert)

	string str("aaaaa");

	str.insert(2, "bbb");

	cout << str << endl; 

	return 0;
}