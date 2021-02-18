#include<iostream>
#include<vector>
using namespace std; 

//std::vector

int main()
{
	//std::array와 달리 동적할당되는 메모리이기 때문에 
	//array처럼 초기화 시 사이즈를 기입하지 않아도 된다. 

	//std::array<int, 5> array1;

	//vector<int> array2 = { 1,2,3,4,5 };

	//cout << array2.size() << endl; 

	//vector<int> array3 = { 1,2,3 };

	//cout << array3.size() << endl; 

	////uniform initialization도 가능 
	//vector<int> array4{ 1,2,3 };

	//cout << array4.size() << endl; 

	vector<int> arr{ 1,2,3,4,5 };

	arr.resize(10);

	for (const auto &num : arr)
	{
		cout << num << endl; 
	}

	//index 넘버를 통해 임의접근 가능 
	cout << arr[0] << endl; 
	cout << arr.at(0) << endl; 

	//vector는 다 사용하고 나면 괄호에서 나가거나 return될 때 메모리에서 해제됨.
	//따라서 메모리 누수가 없음 ...진짜인가? 이건 나중에 확인필요 

	//사이즈 함수로 사이즈를 확인할 수 있으므로 함수의 파라미터로 넘겨도
	//사이즈 함수로 원소의 개수를 확인할 수 있다는 장점이 있음.
	//초기화한 이후에 resize 함수를 통해 사이즈를 키우거나 줄이는 것도 가능
	//(resize 시 공간을 확보해서 재할당하기 때문에 퍼포먼스는 떨어짐)


	return 0;
}