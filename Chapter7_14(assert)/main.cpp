#include<iostream>
#include<cassert>
#include<array>
using namespace std; 

/*

<assert>

사용자가 소프트웨어를 사용하는 데 도움을 주는 장치 

릴리즈 모드에서는 작동하지 않고, 디버그 모드에서만 작동 

assert는 런타임에 오류를 체크 
반면 static_assert는 컴파일 타임에 오류를 체크 

*/

void printValue(const array<int, 5> &my_arr, const int &idx)
{
	//만약 아래 assert 조건에 맞지 않는 값이 들어올 경우, 
	//런타임 오류가 발생하고 콘솔창에 해당 assert문 내용을 출력해서 오류 확인 가능 
	//&&를 이용해서 두 문장을 줄일 수 있으나, 정확히 어떤 문제가 발생했는지
	//확인하기 어렵기 때문에 세부적인 단위로 쪼개서 사용하는 것이 더 좋음. 
	assert(idx >= 0);
	assert(idx <= my_arr.size() - 1);

	cout << my_arr[idx] << endl; 
}

int main()
{
	//assert(false);

	array<int, 5> my_arr{ 1,2,3,4,5 };

	//printValue(my_arr, 100);

	//static_assert는 컴파일타임에 오류를 체크하므로 
	//런타임에 바뀔 여지가 있는 값은 체크할 수 X (변수는 const형으로 바꾸어야 함.)
	//int x = 5;
	const int x = 5;
	static_assert(x == 5, "x should be 5");

	return 0;
}