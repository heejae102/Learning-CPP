#include<iostream>
#include<typeinfo>
using namespace std; 

//포인터 : 메모리의 주소를 저장하는 변수 

int* doSomethiing(int* ptr)
{
	//함수의 파라미터, 리턴타입을 포인터형으로 사용하는 것도 가능
	
	return ptr;
}

struct something
{
	int a, b, c, d, e;
};

int main()
{
	int x = 5; 

	cout << x << endl; 
	cout << &x << endl; 

	//de-reference operator(*)
	//해당 주소에 실제로 들어있는 값을 가져올 수 있는 연산자 
	//cout << *(&x) << endl; 

	//포인터도 변수이므로 사용자 정의형 변수로 지정 가능 
	//but, 실수를 유발할 수 있으므로 지양하는 것이 좋으나 
	//때때로 이중포인터나 삼중포인터를 사용하여 헷갈릴 수 있을 때 사용하기도 함.
	
	//포인터를 선언할 때 데이터 타입이 필요한 이유는 de-referencing할 때 
	//해당 타입을 참고하여 데이터를 읽어와야하기 때문 
	//포인터를 선언할 때의 타입과 담고자하는 데이터의 타입이 다를 경우 오류 발생
	//사용자 정의 자료형도 포인터로 가리킬 수 있음. 

	typedef int* pint;
	//pint ptr_x = &x, ptr_y = &x;
	int *ptr_x = &x; 
	double *ptr_y;

	cout << ptr_x << endl; 
	cout << *(ptr_x) << endl; 
	cout << typeid(ptr_x).name() << endl; 
	cout << typeid(ptr_y).name() << endl; 
	cout << sizeof(ptr_x) << endl; 
	cout << sizeof(ptr_y) << endl; 

	//★주의할점★
	//포인터 변수는 참고하는 자료형의 크기가 무엇이든지 상관없이 
	//오로지 해당 자료의 주소값만 저장하는 변수이므로, 참고하는 데이터에
	//상관없이 포인터 변수의 크기는 일정한 값을 가진다. (모두 16진수 주소이므로)
	//예를 들자면 집의 크기에 상관없이 번지수가 일정한 것과 같음. 

	something ss;
	something *ptr_sth;
	cout << sizeof(something) << endl; 
	cout << sizeof(ptr_sth) << endl; 

	//포인터를 사용함에 있어 가장 잦은 오류는 포인터 변수를 초기화하지 않고
	//쓰레기 값이 들어있는 포인터를 사용하는 것. 
	int *ptr_temp;
	cout << ptr_temp << endl; 

	return 0; 
}