#include<iostream>
#include<cassert>
#include<array>
using namespace std; 

/*

<assert>

����ڰ� ����Ʈ��� ����ϴ� �� ������ �ִ� ��ġ 

������ ��忡���� �۵����� �ʰ�, ����� ��忡���� �۵� 

assert�� ��Ÿ�ӿ� ������ üũ 
�ݸ� static_assert�� ������ Ÿ�ӿ� ������ üũ 

*/

void printValue(const array<int, 5> &my_arr, const int &idx)
{
	//���� �Ʒ� assert ���ǿ� ���� �ʴ� ���� ���� ���, 
	//��Ÿ�� ������ �߻��ϰ� �ܼ�â�� �ش� assert�� ������ ����ؼ� ���� Ȯ�� ���� 
	//&&�� �̿��ؼ� �� ������ ���� �� ������, ��Ȯ�� � ������ �߻��ߴ���
	//Ȯ���ϱ� ��Ʊ� ������ �������� ������ �ɰ��� ����ϴ� ���� �� ����. 
	assert(idx >= 0);
	assert(idx <= my_arr.size() - 1);

	cout << my_arr[idx] << endl; 
}

int main()
{
	//assert(false);

	array<int, 5> my_arr{ 1,2,3,4,5 };

	//printValue(my_arr, 100);

	//static_assert�� ������Ÿ�ӿ� ������ üũ�ϹǷ� 
	//��Ÿ�ӿ� �ٲ� ������ �ִ� ���� üũ�� �� X (������ const������ �ٲپ�� ��.)
	//int x = 5;
	const int x = 5;
	static_assert(x == 5, "x should be 5");

	return 0;
}