#include<iostream>
using namespace std; 

//void printArray(int *array)
//매개변수로 넘겨받은 데이터의 값을 실제로 변경하기 위해 포인터를 사용 (C)
//C++에서는 대개 래퍼런스를 통해 데이터 값을 변경 

void printArray(int array[])
{
	cout << sizeof(array) << endl; //4

	*array = 100;
	//*array[0] = 100;
}

struct MyStruct
{
	int arr[5] = { 1,3,5,7,9 };
};

void doSomething(MyStruct ms)
{
	cout << sizeof(ms.arr) << endl; 
}

void doSomething(MyStruct *ms)
{
	cout << sizeof((*ms).arr) << endl; 
}

int main()
{
	////배열의 변수명은 배열의 첫번째 원소의 주소값을 저장하는 포인터 변수와 같다. 

	//int array[5] = { 9,7,5,3,1 };

	//cout << array[0] << " " << array[1] << endl; 
	//cout << array << endl; 
	//cout << &(array[0]) << endl; 

	////array의 첫번째 원소의 주소값을 담은 변수를 de-referencing 
	//cout << *array << endl; 

	//int *ptr = array;
	//cout << ptr << endl; 
	//cout << *ptr << endl; 

	////but, 배열포인터와 일반포인터에는 차이가 有

	////배열의 전체 사이즈 : 20
	//cout << sizeof(array) << endl;		
	////배열의 주소를 담은 포인터의 사이즈 : 4
	//cout << sizeof(ptr) << endl; 

	////배열을 통째로 넘겼으나, 사이즈를 측정하면 4가 출력됨. 
	////배열을 넘기든 뭘 넘기든간에 함수 내에서는 포인터 변수로 받아 
	////해당 배열의 첫번째 주소 값만 저장하기 때문에 사이즈를 출력하면 
	////결국 포인터 변수의 사이즈인 4가 출력 됨. 
	//printArray(array);

	//cout << "*array " << *array << endl; 
	//cout << "array[0] " << array[0] << endl; 

	//★구조체 내에 배열이 있는 경우 사이즈 구하기★ 
	//배열이 구조체나 클래스 내에 들어있는 경우, 포인터로 강제변환되지 않고
	//배열이 그 자체로 들어가기 때문에 배열의 사이즈를 제대로 출력 

	MyStruct ms; 

	cout << ms.arr[0] << endl; 
	cout << sizeof(ms.arr) << endl;

	doSomething(ms);
	doSomething(&ms);

	//char name[] = "jack";
	//cout << *name << endl; 
	//cout << name[0] << endl; 

	return 0; 
}