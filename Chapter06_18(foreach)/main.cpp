#include<iostream>
#include<limits>
#include<algorithm>
#include<vector>
using namespace std; 

int main()
{
	//foreach��
	//��, array�� �����Ҵ� �� ��� foreach ��� �Ұ��� 
	//���, �����Ҵ� �迭 ��� vector ��밡�� 

	//int fibonacci[] = { 0,1,2,3,5,8,13,21,34,55,89 };

	vector<int> fibonacci = { 0,1,2,3,5,8,13,21,34,55,89 };

	//change arrray values
	//for (int number : fibonacci)
	//{
	//	//�Լ��� �Ķ���ͷ� ���� �Ͱ� ����ؼ� ����δ� ���� ������ �� X
	//	number = 10;
	//}

	//���� ���ĵ� ���� �������� �ʰ� auto�� ���� ��� 
	//for (auto &number : fibonacci)
	//{
	//	//���� �����ϱ� ���ؼ��� call by reference ������ ����ؾ� ��.
	//	number = 10;
	//}

	//output 
	//���⼭�� ���� �������� �����Ƿ� const������ ���ϴ� ���� ����. 
	for (const auto &number : fibonacci)
	{
		cout << number << " ";
	}

	cout << endl; 


	//--------------------------------------------------------//

	//foreach���� ����Ͽ� �ִ밪 ���ϱ� 

	int max_number = std::numeric_limits<int>::lowest();

	for (const auto &number : fibonacci)
	{
		//max(a,b) a,b �� �� ū ���ڸ� ��ȯ 
		//max_number = max(max_number, number);
		
		max_number = (max_number < number) ? number : max_number;
	}

	cout << max_number << endl; 

	return 0;
}