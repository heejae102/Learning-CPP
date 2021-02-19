#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

<STL �˰���>

*/

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	// begin() ~ end() ���̿��� ���� ���� ���Ҹ� ã�� ��ȯ
	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl; 

	// begin() ~ end() ���̿��� ���� ū ���Ҹ� ã�� ��ȯ 
	itr = max_element(container.begin(), container.end());
	cout << *itr << endl; 

	cout << endl; 

	// ù��°, �ι�° �Ű����� ���� ���̿��� 3�� ���� ���� ���� ã�Ƽ� ��ġ�� ��ȯ
	itr = find(container.begin(), container.end(), 3);
	
	// itr �� ��ġ(���� 3�� ��ġ)�� 128 ����
	container.insert(itr, 128);

	for (auto &e : container) cout << e << " ";
	cout << endl; 

	// �����ϱ� (����Ʈ�� ��������)
	sort(container.begin(), container.end());
	for (auto &e : container) cout << e << " ";
	cout << endl;

	// list�� ��� list Ŭ���� ���� sort �Լ��� �����ؼ� ��ü �Լ��� ��� 
	//container.sort();

	sort(container.begin(), container.end(), greater<int>());	// �������� 
	for (auto &e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end(), less<int>());		// �������� 
	for (auto &e : container) cout << e << " ";
	cout << endl;

	// ���ҵ��� ���� ������ 
	reverse(container.begin(), container.end());
	for (auto &e : container) cout << e << " ";
	cout << endl;

	// list�� ��� list Ŭ���� ���� sort �Լ��� �����ؼ� ��ü �Լ��� ��� 
	//container.reverse();

	return 0;
}