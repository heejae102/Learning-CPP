#include<iostream>
#include<iomanip>
using namespace std; 

/*

<ostream으로 출력하기>

*/

int main()
{
	/*
	
	<숫자 진수에 따른 출력 방법>

	1. cout.setf(std::ios::hex);

	해당 코드 사용 시 원래 사용하던 모드는 unsetf 해야 함. 
	
	cout.setf(std::ios::oct) : 숫자를 8진수로 출력
	cout.setf(std::ios::dec) : 숫자를 10진수로 출력 
	cout.setf(std::ios::hex) : 숫자를 16진수로 출력 

	cout.unsetf(std::ios::oct) : 8진수 출력 해제 
	cout.unsetf(std::ios::dec) : 10진수 출력 해제 
	cout.unsetf(std::ios::hex) : 16진수 출력 해제 


	2. cout.setf(std::ios::hex, std::ios::basefield);

	해당 코드 사용 시 unsetf 하지 않고 사용 가능 


	3. cout << std::hex; 

	cout << std::hex;
	cout << std::oct; 
	cout << std::dec;

	16 출력 시 알파벳은 소문자가 디폴트 

	cout.setf(std::ios::uppercase); 호출 시 대문자로 출력
	cout << std::hex << std::uppercase; 도 가능 

	*/


	// + 양수 기호 출력 
	cout.setf(std::ios::showpos);
	cout << 108 << endl;
	cout << 110 << endl;

	// + 양수 기호 삭제 
	cout.unsetf(std::ios::showpos);
	cout << 108 << endl;


	//===================================================================//


	// bool 형 데이터를 1/0이 아닌 문자 true/false로 출력  

	cout << std::boolalpha;
	cout << true << " " << false << endl; 


	//===================================================================//


	// 데이터 자릿수 출력 

	//cout << std::defaultfloat;	// 소수 출력 디폴트형 

	// std::setprecision(n) : n자리 만큼 출력 
	// std::scientifix		: 가수와 지수 표현 (소문자가 e 사용) 
	// std::fixed;			: 소수점 자리를 고정시켜 표현 
	// std::showpoint		: 소수점 출력 

	// fixed, setprecision 함께 사용 시 소수점 자리 이하 n자리 수까지 출력 
	// cout << std::scientific << std::uppercase; 호출 시 대문자 E 사용 

	cout << fixed;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;


	//===================================================================//


	// 여백 관리 

	cout.fill('*');	// 여백을 해당 기호로 채운다. 
	cout << -12345 << endl;
	cout << std::setw(10) << -12345 << endl; 
	cout << std::setw(10) << std::left << -12345 << endl; 
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;	// 부호와 숫자 사이 빈칸

	return 0;
}