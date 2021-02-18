#include<iostream>
#include<array>
#include<algorithm>
using namespace std; 

//std::array 

//�Ϲ� �迭�� �޸� std::array�� �Ķ���ͷ� �ѱ� �� �迭�� ��°�� �ѱ�� ������
//�Լ� �������� ����� Ȯ���� �� �ִ�. 
//��, �Ķ���Ϳ� �ѱ�鼭 �迭�� ���ҵ��� ���� ���簡 �ǹǷ� 
//�����ս��� ���̱� ���ؼ� ���۷����� �޴� ���� ����. (�����͵� ����)

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

	//std::array�� ���� ���� �־����� ����� �����Ǿ�� ��.
	//�Լ� �Ķ���ͷ� �ѱ� �� �Ϲ� �迭���� �� 
	std::array<int, 5> my_arr = { 1,21,3,40,5 };

	//���ʱ�ȭ ���� 
	//my_arr = { 0,1,2,3,4 };
	//my_arr = { 0,1,2 };

	//�Ʒ� �� �ڵ� ��� ������� ������ ������, 
	//1���� ���� �迭�� ������� ������� ������ �����ϴ� �ݸ�(���� �߻� ����)
	//2���� �迭�� ������� ū ���� �Ѿ�� ��� ����ó��(�ӵ��� ���� ���� �� ����) 

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


	//�迭 �����ϱ�(�˰��� ��� ���)
	
	//�������� ���� 
	std::sort(my_arr.begin(), my_arr.end());
	printElement(my_arr);

	cout << endl;

	//�������� ����
	std::sort(my_arr.rbegin(), my_arr.rend());
	printElement(my_arr);

	return 0;
}