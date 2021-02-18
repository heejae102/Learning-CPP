#include<iostream>
#include<limits>
#include<algorithm>
#include<vector>
using namespace std; 

int main()
{
	//foreach문
	//단, array를 동적할당 할 경우 foreach 사용 불가능 
	//대신, 동적할당 배열 대신 vector 사용가능 

	//int fibonacci[] = { 0,1,2,3,5,8,13,21,34,55,89 };

	vector<int> fibonacci = { 0,1,2,3,5,8,13,21,34,55,89 };

	//change arrray values
	//for (int number : fibonacci)
	//{
	//	//함수의 파라미터로 들어가는 것과 비슷해서 밸류로는 값을 변경할 수 X
	//	number = 10;
	//}

	//보통 형식도 직접 지정하지 않고 auto를 많이 사용 
	//for (auto &number : fibonacci)
	//{
	//	//값을 변경하기 위해서는 call by reference 형식을 사용해야 함.
	//	number = 10;
	//}

	//output 
	//여기서는 값을 변경하지 않으므로 const형식을 취하는 것이 좋음. 
	for (const auto &number : fibonacci)
	{
		cout << number << " ";
	}

	cout << endl; 


	//--------------------------------------------------------//

	//foreach문을 사용하여 최대값 구하기 

	int max_number = std::numeric_limits<int>::lowest();

	for (const auto &number : fibonacci)
	{
		//max(a,b) a,b 중 더 큰 숫자를 반환 
		//max_number = max(max_number, number);
		
		max_number = (max_number < number) ? number : max_number;
	}

	cout << max_number << endl; 

	return 0;
}