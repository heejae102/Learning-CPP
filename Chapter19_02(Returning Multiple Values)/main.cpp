#include<iostream>
#include<tuple>
using namespace std; 

/*

<함수에서 여러 개의 리턴값 반환하기> (C++ 17)

C++ 17 사용 시 설정 
프로젝트 속성 - C/C++ - 언어 - C++ 언어 표준 - IOS C++17 표준

일반적으로 함수에서는 1개의 밸류만 리턴 가능 

*/

//int my_func()
//{
//	return 0;
//}

// 1. tuple을 사용하여 여러 개의 밸류 리턴 
//tuple<int, int> my_func()
//{
//	return tuple<int, int>(123, 456);
//}

// 2. tuple을 auto로 변경 가능 
//auto my_func()
//{
//	return tuple<int, int>(123, 456);
//}

// 3. C++17 으로 return하기
auto my_func()
{
	return tuple(123, 456, 789);
}

int main()
{
	cout << "Hello, World!" << endl;

	// 1. tuple의 결과 값 받기 
	//tuple<int, int> result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << endl;

	// 2. auto(tuple)의 결과 값 받기 
	//auto result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << endl;

	// 3. C++17 으로 auto(tuple)의 결과 값 받기 
	//auto result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	// 변수에 담아서 리턴하는 것도 가능 
	auto[a, b, c] = my_func();
	cout << a << " " << b << " " << c << " " << endl;

	return 0;
}