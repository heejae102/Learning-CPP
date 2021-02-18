#include<iostream>
#include<cstddef>
using namespace std;

void doSomething(const double *ptr)
{
	cout << "address of doSomething ptr : " << &ptr << endl;

	if (ptr != nullptr)
	{
		//do something useful
		cout << *ptr << endl;
	}
	else
	{
		//do nothing with ptr 
		cout << "nullptr, do nothing" << endl;
	}
}

int main()
{
	//NULL pointer 
	//포인터에 주소값이 제대로 들어있는지 확인하는 용도로 자주 사용
	//함수 파라미터로 사용할 때 유용 

	double *ptr = NULL;		//c style
	double *p = nullptr;	//c++ style

	doSomething(ptr);
	doSomething(p);

	double d = 1.234;
	doSomething(&d);

	ptr = &d;
	doSomething(ptr);

	//null 포인터만 집어넣을 수 있는 변수타입 
	//null 포인터만 파라미터로 받아야하는 경우 등에 사용
	nullptr_t nptr;

	//함수의 파라미터로 넘어가는 변수와 
	//함수 내에서 사용하는 해당 파라미터 변수의 주소는 다르다.
	//(함수 내에서 파라미터로 넘어온 변수를 파라미터 변수에 복사해서 사용)
	cout << "address of main ptr : " << &ptr << endl;

	return 0;
}