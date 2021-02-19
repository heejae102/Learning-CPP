#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std; 

/*

<STL 반복자>



*/

int main()
{
	// vector의 반복자 사용 

	vector<int> container;	

	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	// 반복자 자체를 변수화 (iterator/const_iterator 둘 다 가능)
	//vector<int>::iterator itr;
	vector<int>::const_iterator itr;
	
	// 반복자 초기화 
	itr = container.begin();

	// container.end() 는 마지막 원소가 아닌 배열의 끝
	while (itr != container.end())
	{
		cout << *itr << " ";

		itr++;
	}
	cout << endl; 

	// auto 형태로 초기화 
	for (auto itr = container.begin(); itr != container.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl; 

	//==========================================================================//

	// list의 반복자 사용 

	// list도 vector와 마찬가지로 반복자를 통해 접근 가능 

	list<int> arrayList;

	for (int i = 0; i < 10; i++)
	{
		arrayList.push_back(i + 1);
	}

	for (auto itr = arrayList.begin(); itr != arrayList.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl; 

	//==========================================================================//

	// set의 반복자 사용 
	
	set<int> setList;

	for (int i = 0; i < 10; i++)
	{
		setList.insert(i + 1);
	}

	for (auto itr = setList.begin(); itr != setList.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;

	//==========================================================================//

	// map의 반복자 사용 

	map<int, char> mapContainer;

	for (int i = 0; i < 10; i++)
	{
		mapContainer.insert(make_pair(i, char(i + 65)));
	}

	for (auto itr = mapContainer.begin(); itr != mapContainer.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
	cout << endl; 

	return 0;
}