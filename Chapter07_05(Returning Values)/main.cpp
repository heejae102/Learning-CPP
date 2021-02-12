#include<iostream>
#include<array>
#include<tuple>
using namespace std; 

//int getValue(int x)
//{
//	int value = x * 2;
//	return value;
//}

//값의 복사를 줄이기 위해 리턴 타입을 주소로 설정할 수 있으나, 
//함수 내 지역변수는 함수가 종료되면서 사라지므로 함수 내 지역변수의 
//주소값을 리턴하는 것은 지양하는 것이 좋다. 

//주소값을 리턴 
//int* getValue(int x)
//{
//	int value = x * 2;
//	return &value;
//}

//래퍼런스를 리턴 
int& getValue(int x)
{
	int value = x * 2;
	return value;
}

//래퍼런스 리턴을 편리하게 쓰기 
int& get(array<int, 100> &my_arr, int idx)
{
	return my_arr[idx];
}

//하지만 이렇게 메모리를 할당할 경우, delete은 다른 곳에서 
//별도로 해야하기 때문에 헷갈릴 수 있으므로 권장하지 않음. 
int* allocateMemory(int size)
{
	return new int[size];
}

struct TestS
{
	int a, b, c, d;
};

TestS getStruct()
{
	TestS my_s{ 1,2,3,4 };
	return my_s;
}

//튜플을 이용하여 여러 개의 리턴 타입을 넘기기 
//int와 double형을 리턴한다는 의미(사용자 정의형과 비슷)
tuple<int, double> getTuple()
{
	int a = 10;
	double b = 3.14;

	return make_tuple(a, b);
}

int main()
{
	//리턴으로 넘겨오는 주소값을 이용하여 값을 초기화 

	//1.넘겨받은 주소 값을 역참조  
	//int value = *getValue(3);

	//2. 주소값 자체를 넘겨받기 
	//(함수가 종료된 시점에서 이미 사라지는 변수를 참조하는 것으로 오류 발생)
	//int *ptr = getValue(3);


	//--------------------------------------------------------------------------//

	
	//메모리를 할당하여 할당한 메모리의 주소값을 넘기는 경우도 있다. 

	int *arr = allocateMemory(1024);
	delete[] arr;


	//--------------------------------------------------------------------------//


	//래퍼런스 변수를 리턴
	//리턴타입의 래퍼런스가 가리키는 변수의 값이 복사되어서 value로 대입
	int value = getValue(5);

	//※래퍼런스를 래퍼런스 변수로 받을 경우, 함수의 지역변수를 참조하는 격이기 때문에
	//추후 사라지게 될 값을 참조하게 되면 오류가 발생
	int &var = getValue(5);

	cout << var << endl; 	
	cout << var << endl;	//쓰레기값 출력 


	//--------------------------------------------------------------------------//

	
	//메모리가 휘발성이 아닌 형태로 잡혀 있으면서 해당 메모리를 래퍼런스하여 
	//마치 변수처럼 사용할 수 있는 형태 
	std::array<int, 100> my_arr;
	my_arr[30] = 10;

	//my_arr[30] = 1024 와 같은 형태 
	get(my_arr, 30) = 1024;
	
	cout << my_arr[30] << endl; 


	//--------------------------------------------------------------------------//


	//리턴 타입으로 구조체를 넘기기 

	TestS my_s = getStruct();
	cout << my_s.a << endl;
	cout << my_s.b << endl; 
	cout << my_s.c << endl; 
	cout << my_s.d << endl; 


	//--------------------------------------------------------------------------//


	//튜플로 리턴값 받기 
	tuple<int, double> my_tp = getTuple();
	cout << get<0>(my_tp) << endl; 
	cout << get<1>(my_tp) << endl; 

	//c++17 버전부터 이렇게도 가능 
	//auto[a, b] = getTuple();
	//cout << a << endl; 
	//cout << b << endl; 


	return 0;
}