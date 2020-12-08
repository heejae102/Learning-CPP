#include<iostream>
#include<limits>
using namespace std; 

void printArray(const int array[], const int length)
{
	for (int index = 0; index < length; index++)
	{
		cout << array[index] << " ";
	}
	cout << endl;
}

int main()
{
	//������������ ���� �����Ѵٰ� �� ��, ó���� �ִ� 
	//���Һ��� ���� ���� ����(�� �߿��� ���� ���� ����)�� ����� �ε��� ���� 
	//�����Ͽ��ٰ� ù��° ���ҿ� ������ 

	//ù��° ���Ұ� �������� �� ��° ���Һ��� ���ʴ�� �Ϸ��� ���� �ٽ� ���� 

	/*
	
	<�������� ���> 

	������� �ε��� 
	���� ���� ��� 
						value	index
	3	5	2	1	4	  1		  3
	1	5	2	3	4	  2		  2
	1	2	5	3	4	  3		  3
	1	2	3	5	4	  4		  4
	1	2	3	4	5
	
	*/

	//�������� ���� 
	//�������ĵ� �����غ��� 

	const int length = 5;
	int array[length] = { 3,5,2,1,4 };

	printArray(array, length);

	//for (int i = 0; i < length - 1; i++)
	//{
	//	int minIdx = i;

	//	for (int j = i + 1; j < length; j++)
	//	{
	//		if (array[minIdx] > array[j])
	//		{
	//			minIdx = j;
	//		}
	//	}

	//	int temp = array[i];
	//	array[i] = array[minIdx];
	//	array[minIdx] = temp;
	//	printArray(array, length);
	//}

	for (int startIdx = 0; startIdx < length - 1; startIdx++)
	{
		int minIdx = startIdx; 

		for (int curIdx = startIdx + 1; curIdx < length; curIdx++)
		{
			minIdx = (array[minIdx] > array[curIdx]) ? curIdx : minIdx;
		}

		int temp = array[minIdx];
		array[minIdx] = array[startIdx];
		array[startIdx] = temp;
		printArray(array, length);
	}

	return 0; 
}