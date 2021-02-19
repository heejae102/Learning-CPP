#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std; 

/*

<STL �ݺ���>



*/

int main()
{
	// vector�� �ݺ��� ��� 

	vector<int> container;	

	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	// �ݺ��� ��ü�� ����ȭ (iterator/const_iterator �� �� ����)
	//vector<int>::iterator itr;
	vector<int>::const_iterator itr;
	
	// �ݺ��� �ʱ�ȭ 
	itr = container.begin();

	// container.end() �� ������ ���Ұ� �ƴ� �迭�� ��
	while (itr != container.end())
	{
		cout << *itr << " ";

		itr++;
	}
	cout << endl; 

	// auto ���·� �ʱ�ȭ 
	for (auto itr = container.begin(); itr != container.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl; 

	//==========================================================================//

	// list�� �ݺ��� ��� 

	// list�� vector�� ���������� �ݺ��ڸ� ���� ���� ���� 

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

	// set�� �ݺ��� ��� 
	
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

	// map�� �ݺ��� ��� 

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