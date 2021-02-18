#include<iostream>
using namespace std; 

//다중 포인터와 동적 다차원 배열 

int main()
{
	//포인터를 참조하는 포인터형(이중 포인터)

	//int *ptr = nullptr;
	//int **ptrptr = nullptr;

	//int value = 5;
	//ptr = &value;
	//ptrptr = &ptr;

	//cout << "ptr  : " << ptr << endl;
	//cout << "*ptr : " << *ptr << endl; 
	//cout << "&ptr : " << &ptr << endl; 

	//cout << "ptrptr   : " << ptrptr << endl;
	//cout << "*ptrptr  : " << *ptrptr << endl;
	//cout << "&ptrptr  : " << &ptrptr << endl;
	//cout << "**ptrptr : " << *ptrptr << endl;

	//3중, 4중 포인터도 만들 수 있지만 그 정도로 사용할 일은 많지 않다..
	//다만 2중 포인터는 2차원 행렬을 구현하는 데 종종 사용한다. 
	//int ***ppptr, ****pppptr;


	//--------------------------------------------------------------//

	const int row = 3;
	const int col = 5;

	const int s2da[][5]=
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	//5개의 원소를 가진 1차원 배열 3개로 표현 가능

	//int *r1 = new int[col] { 1, 2, 3, 4, 5 };
	//int *r2 = new int[col] { 6, 7, 8, 9, 10 };
	//int *r3 = new int[col] { 11, 12, 13, 14, 15 };

	////row의 개수만큼 선언해주어야하므로 이중포인터로 좀 더 편리하게 선언
	//int **rows = new int*[row] {r1, r2, r3};

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//	{
	//		cout << rows[r][c] << " ";
	//	}
	//	cout << endl; 
	//}

	//delete[] r1;
	//delete[] r2;
	//delete[] r3;
	//delete[] rows;

	//-------------------------------------------------------------//

	//int **matrix = new int*[row];

	//for (int r = 0; r < row; r++)
	//{
	//	matrix[r] = new int[col];
	//}

	////print all elements
	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//	{
	//		matrix[r][c] = s2da[r][c];
	//	}
	//}

	////print all elements
	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//	{
	//		cout << matrix[r][c] << " ";
	//	}
	//	cout << endl; 
	//}

	////delete
	//for (int r = 0; r < row; r++)
	//{
	//	delete[] matrix[r];
	//}

	//delete[] matrix;

	//-------------------------------------------------------------//

	//2중 포인터를 사용하지 않고 구현 

	int *matrix = new int[row*col];

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			matrix[(r*col) + c] = s2da[r][c];
		}
	}

	//print all elements
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			cout << matrix[(col*r) + c] << " ";
		}
		cout << endl; 
	}

	delete[] matrix;

	return 0;
}