#include<iostream>
using namespace std; 

int main()
{
	const int num_rows = 3;
	const int num_columns = 5;

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_columns; col++)
		{
			cout << '[' << row << ']' << '[' << col << ']' << '\t';
		}
		cout << endl; 
	}

	//2차원 배열에서 값을 직접 지정하는 경우 row의 원소 사이즈는 생략 가능하나,
	//column의 원소 사이즈는 생략할 수 없다. 
	int array[/*num_rows*/][num_columns]=
	{
		{1,2,3,4,5},		//row0
		{6,7,8,9,10},		//row1
		{11,12,13,14,15}	//row2
	};

	//2차원 배열 선언 시에 row와 column의 값이 모두 주어져 있다면 한꺼번에
	//값을 초기화하는 것도 가능하다. 
	int arr[num_rows][num_columns] = { 0 };

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_columns; col++)
		{
			cout << array[row][col] << '\t';
		}
		cout << endl;
	}
}