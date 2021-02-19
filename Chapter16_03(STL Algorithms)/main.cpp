#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

<STL 알고리즘>

*/

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	// begin() ~ end() 사이에서 가장 작은 원소를 찾아 반환
	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl; 

	// begin() ~ end() 사이에서 가장 큰 원소를 찾아 반환 
	itr = max_element(container.begin(), container.end());
	cout << *itr << endl; 

	cout << endl; 

	// 첫번째, 두번째 매개변수 범위 사이에서 3의 값을 가진 원소 찾아서 위치값 반환
	itr = find(container.begin(), container.end(), 3);
	
	// itr 의 위치(원소 3의 위치)에 128 삽입
	container.insert(itr, 128);

	for (auto &e : container) cout << e << " ";
	cout << endl; 

	// 정렬하기 (디폴트는 오름차순)
	sort(container.begin(), container.end());
	for (auto &e : container) cout << e << " ";
	cout << endl;

	// list의 경우 list 클래스 내에 sort 함수가 존재해서 자체 함수를 사용 
	//container.sort();

	sort(container.begin(), container.end(), greater<int>());	// 내림차순 
	for (auto &e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end(), less<int>());		// 오름차순 
	for (auto &e : container) cout << e << " ";
	cout << endl;

	// 원소들의 순서 뒤집기 
	reverse(container.begin(), container.end());
	for (auto &e : container) cout << e << " ";
	cout << endl;

	// list의 경우 list 클래스 내에 sort 함수가 존재해서 자체 함수를 사용 
	//container.reverse();

	return 0;
}