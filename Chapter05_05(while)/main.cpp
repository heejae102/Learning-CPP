#include<iostream>
using namespace std; 

int main()
{
	cout << "while-loop test" << endl; 

	//int count = 0;
	//while (count < 10)
	//{
	//	cout << count << endl; 

	//	count++; 
	//}

	//unsigned int(부호가 없는 정수) 자료형을 쓸 때 변수 값이 해당 자료형의
	//데이터 범위를 벗어날 경우(음수가 될 경우) 오버플로우 현상이 발생해서 
	//올바른 값이 출력되지 않음. 

	//unsigned int count = 10;
	//while (count >= 0)
	//{
	//	if (count == 0) cout << "zero" << endl; 
	//	else cout << count << endl; 

	//	count--;
	//}


	//int outer_count = 1; 

	//while (outer_count <= 5)
	//{
	//	int inner_count = 1; 

	//	while (inner_count <= outer_count)
	//	{
	//		cout << inner_count++ << " ";
	//	}

	//	cout << endl; 
	//	++outer_count;
	//}

	// do-while문

	//특징1)
	//조건에 사용되는 변수는 반드시 do-while문 바깥에 존재해야 한다 
	//do-while문 내에 있을 경우 while 조건문 검사를 할 때 이미 변수가 
	//사라진 상태이므로 오류 발생 

	//특징2) while(조건); while 조건문 뒤에 세미콜론을 붙여줘야 한다. 

	int selection;	//must be declared outside do/while loop

	do
	{
		cout << "1. add" << endl; 
		cout << "2. sub" << endl; 
		cout << "3. mul" << endl; 
		cout << "4. div" << endl; 
		cin >> selection;

	} while (selection <= 0 || selection >= 5);

	cout << "You selected " << selection << endl; 

	return 0; 
}