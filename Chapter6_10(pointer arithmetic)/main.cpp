#include<iostream>
using namespace std; 

int main()
{
	//int value = 7;
	//int *ptr = &value; 

	//주소는 기본적으로 16진수로 저장되어 있음 
	//cout << ptr << endl; 

	//주소를 10진수로 변환해줌. 
	//cout << uintptr_t(ptr) << endl;	

	/*
	
	<포인터 연산>

	포인터에 +,-의 연산을 할 경우, 

	(포인터의 데이터 타입의 메모리)*연산값 의 형태로 연산 
	
	ex. int ptr;
		ptr + 1 : ptr + (int형의 메모리 * 1)
		ptr + 2 : ptr + (int형의 메모리 * 2)

	*/

	//cout << uintptr_t(ptr - 1) << endl;
	//cout << uintptr_t(ptr) << endl;
	//cout << uintptr_t(ptr + 1) << endl;
	//cout << uintptr_t(ptr + 2) << endl;

	//배열은 메모리가 나란히 늘어선 형태로, 주소를 출력하면 
	//해당 데이터 타입의 크기만큼 일정하게 증가하는 형태로 주소가 이웃한 형태 
	//해당 성질을 이용하여 포인터 인덱싱을 이용해 배열에 순차적으로 접근 가능 

	//int array[] = { 1,3,5,7,9 };
	//int *ptr = array;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << array[i] << " " << (uintptr_t)&array[i] << endl; 
	//	cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
	//}

	char name[] = "Jack jack";

	//이렇게 연산하면 마지막 원소인 null도 함께 포함된 값이 나옴 
	const int n_name = sizeof(name) / sizeof(char);

	for (int i = 0; i < n_name - 1; i++)
	{
		//아래 문장과 같음
		cout << *(name + i) << endl;
		//cout << name[i] << endl; 
	}
}
