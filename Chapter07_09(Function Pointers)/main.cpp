#include<iostream>
#include<array>
#include<functional>
using namespace std; 

/*

<함수 포인터>

함수도 변수와 마찬가지로 주소를 가지고 있다. 
포인터 변수를 통해 변수를 가리키던 것과 마찬가지로
함수도 포인터를 통해 주소를 가리킬 수 있다. 

*/

int func()
{
	return 5;
}

int goo()
{
	return 10; 
}

bool isEven(const int &number)
{
	if (number % 2 == 0) return true;
	else return false; 
}

bool isOdd(const int &number)
{
	if (number % 2 == 1) return true; 
	else return false; 
}

//함수 포인터를 빈번하게 사용할 경우 typedef이나 using 키워드로 줄여서 사용가능 

//typedef bool(*check_fnc_t)(const int &);
//using check_fnc_t = bool(*)(const int &);
//
//void printNumbers(const array<int, 10> &my_arr, check_fnc_t check_fnc = isEven)
//{
//	for (const auto &element : my_arr)
//	{
//		if (check_fnc(element) == true) cout << element;
//
//		//if (!print_even && element % 2 == 1) cout << element;
//	}
//	cout << endl;
//}

//함수 포인터도 디폴트 매개변수로 기본값을 지정해줄 수 있다. 

//void printNumbers(const array<int, 10> &my_arr, bool(*check_fnc)(const int &) = isEven)
//{
//	for (const auto &element : my_arr)
//	{
//		if (check_fnc(element) == true) cout << element;
//
//		//if (!print_even && element % 2 == 1) cout << element;
//	}
//	cout << endl;
//}

void printNumbers(const array<int, 10> &my_arr, 
	function<bool(const int &)> check_fnc = isEven)
{
	for (const auto &element : my_arr)
	{
		if (check_fnc(element) == true) cout << element;

		//if (!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}


int main()
{
	//함수의 주소 출력 
	//cout << func << endl; 

	////함수를 호출하면 함수의 메모리 주소를 찾아서 
	////해당 주소 내에 있는 코드를 실행 
	//func();

	////함수 포인터 선언 및 초기화 
	////대입하고자 하는 함수의 형태에 맞게 선언. 
	////리턴타입 (함수포인터명)(매개변수 타입)
	//int(*fcnptr)() = func;

	////함수포인터로 함수 호출 
	//cout << fcnptr() << endl;

	////함수포인터로 다른 함수 참조 가능 
	//fcnptr = goo;

	//cout << fcnptr() << endl; 


	//----------------------------------------------------------//

	
	//함수 포인터를 파라미터로 넘기기  

	array<int, 10> my_arr{ 1,2,3,4,5,6,7,8,9,10 };

	printNumbers(my_arr, isOdd);
	printNumbers(my_arr, isEven);
	
	//디폴트 값으로 지정된 함수가 사용될 예정 
	printNumbers(my_arr);


	//----------------------------------------------------------//


	//C++17부터 도입된 기능 (functional 헤더 사용)

	function<bool(const int &)> fcnptr = isEven;

	printNumbers(my_arr, fcnptr);

	fcnptr = isOdd;

	printNumbers(my_arr, fcnptr);

	return 0;
}