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
	//오름차순으로 값을 정렬한다고 할 때, 처음에 있는 
	//원소보다 값이 작은 숫자(들 중에서 가장 작은 숫자)의 밸류와 인덱스 값을 
	//저장하였다가 첫번째 원소와 스와핑 

	//첫번째 원소가 끝났으면 두 번째 원소부터 차례대로 일련의 과정 다시 실행 

	/*
	
	<선택정렬 방식> 

	순서대로 인덱스 
	적힌 값이 밸류 
						value	index
	3	5	2	1	4	  1		  3
	1	5	2	3	4	  2		  2
	1	2	5	3	4	  3		  3
	1	2	3	5	4	  4		  4
	1	2	3	4	5
	
	*/

	//선택정렬 구현 
	//버블정렬도 연습해보기 

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