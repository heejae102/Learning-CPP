#include<iostream>
#include<array>
#include<algorithm>
using namespace std; 

//std::array 

//일반 배열과 달리 std::array는 파라미터로 넘길 때 배열을 통째로 넘기기 때문에
//함수 내에서도 사이즈를 확인할 수 있다. 
//단, 파라미터에 넘기면서 배열의 원소들이 전부 복사가 되므로 
//퍼포먼스를 높이기 위해서 래퍼런스로 받는 것이 좋다. (포인터도 가능)

void printLength(const array<int, 5> &my_arr)
{
	cout << my_arr.size() << endl; 
}

void printElement(const array<int, 5> &my_arr)
{
	for (const auto &element : my_arr)
	{
		cout << element << endl; 
	}
}

int main()
{
	int array[5] = { 1,2,3,4,5 };

	//std::array는 원소 값이 주어져도 사이즈가 지정되어야 함.
	//함수 파라미터로 넘길 때 일반 배열보다 편리 
	std::array<int, 5> my_arr = { 1,21,3,40,5 };

	//재초기화 가능 
	//my_arr = { 0,1,2,3,4 };
	//my_arr = { 0,1,2 };

	//아래 두 코드 모두 기능적인 측면은 같지만, 
	//1번은 실제 배열의 사이즈와 상관없이 무조건 접근하는 반면(오류 발생 가능)
	//2번은 배열의 사이즈보다 큰 값이 넘어올 경우 예외처리(속도는 조금 느릴 수 있음) 

	//cout << my_arr[10] << endl; 
	//cout << my_arr.at(10) << endl; 
	cout << my_arr.size() << endl; 

	for (const auto &number : my_arr)
	{
		cout << number << endl; 
	}
	
	printLength(my_arr);
	cout << endl;

	//----------------------------------------------------------//


	//배열 정렬하기(알고리즘 헤더 사용)
	
	//오름차순 정렬 
	std::sort(my_arr.begin(), my_arr.end());
	printElement(my_arr);

	cout << endl;

	//내림차순 정렬
	std::sort(my_arr.rbegin(), my_arr.rend());
	printElement(my_arr);

	return 0;
}