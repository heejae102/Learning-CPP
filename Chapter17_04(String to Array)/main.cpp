#include<iostream>
#include<string>
using namespace std; 

/*

<string 문자 접근하기와 배열로의 변환>

*/

int main()
{
	string my_str("abcdefg");

	// 배열처럼 인덱스로 접근 가능 (단, 해당 문자열 범위 내의 인덱스만 접근 가능)

	// str[n]    : 처리 속도가 빠르며, 예외처리를 거치지 않음. (퍼포먼스↑)
	// str.at(n) : 처리 속도가 비교적 느리며, 예외처리(throw)를 거친다. (안정성↑)  

	cout << my_str[0] << endl; 
	cout << my_str[3] << endl; 
	cout << my_str.at(0) << endl;
	cout << my_str.at(3) << endl;

	my_str[3] = 'Z';

	cout << my_str << endl; 


	//=====================================================================//


	// C-style 문자열로 변환 

	cout << my_str.c_str() << endl; 

	const char *arr = my_str.c_str();
	//const char *arr = my_str.data();	// str.c_str() 와 같은 기능을 하는 함수 

	// char형으로 변환 시, 문자열의 끝에 NULL 문자가 붙는다. 
	cout << (int)arr[6] << endl; 
	cout << (int)arr[7] << endl; 


	// 수동으로 char 데이터에 직접 복사하기 

	char buf[20];

	// 단, 복사는 되지만 NULL 캐릭터가 자동으로 추가되지 않기 때문에
	// 개별적으로 추가해주어야 빈 문자열에 쓰레기 값이 들어가지 않는다. 
	my_str.copy(buf, 7, 0);
	buf[7] = '\0';			// 문자열의 마지막에 NULL 캐릭터 추가 
	
	cout << buf << endl; 

	return 0;
}