#include<iostream>
using namespace std; 

int main()
{
	//정적 메모리는 stack에 저장됨.
	//int array[1000000];	

	//동적 메모리는 heap에 저장됨. 
	//int사이즈에 맞춰서 os에서 메모리를 받아온 다음 해당 주소를 
	//넘겨주므로 포인터로 받아주어야 함. 
	//메모리를 할당하면서 바로 값을 초기화하는 것도 가능
	//동적 메모리 사용 시 중요한 것은 할당 후 메모리를 해제하는 것.
	//크고 복잡한 프로그램을 사용할수록 메모리를 해제하는 것이 중요함★
	
	
	//메모리 할당 
	//int *ptr = new int; 
	int *ptr = new int(7);

	cout << ptr << endl;
	cout << *ptr << endl; 

	//메모리 해제 
	delete ptr; 

	//메모리를 해제한 후에 해당 주소를 사용하려고 하면 오류 발생
	//cout << "After Delete" << endl; 
	//cout << ptr << endl;
	//cout << *ptr << endl;

	//1.메모리 해제 후 잘못 참조하는 오류 방지하는 방법
	//2.스마트 포인터 사용 
	//ptr = nullptr;

	//cout << "After Delete" << endl; 
	//if (ptr != nullptr)
	//{
	//	cout << ptr << endl; 
	//	cout << *ptr << endl; 
	//}

	//아래와 같이 변수에 값을 할당하는 것과 같음.
	//int var;
	//var = 7;

	//※ 프로그램이 메모리를 할당받으려고 하지만 남은 
	//메모리 공간이 없어서 더 이상 할당받지 못하는 경우 해결 방법

	//1. 프로그램이 종료되도록 프로그래밍 

	//2. 프로그램이 종료되지 않고 있다가 할당했던 메모리를 반납받아 
	//공간이 생길 경우 해당 메모리를 할당받아 사용하도록 프로그래밍 
	//그럴 경우 메모리를 할당해도 오류가 발생하지 않도록 방지해야 함. 

	//nothrow 키워드를 사용하면, 메모리를 할당할 공간이 없어 
	//메모리 할당에 실패할 경우 nullptr을 반환 
	int *p = new(nothrow) int{ 7 };

	if (p != nullptr)
	{
		cout << p << endl;
		cout << *p << endl;
	}
	else
	{
		cout << "couldn't allocate memory" << endl; 
	}

	//동적 메모리 할당 시 자주 실수하는 것
	int *pt = new(nothrow) int(10);
	int *pt2 = pt;

	delete pt; 
	pt = nullptr;
	//ptr2도 ptr을 참조하고 있었으므로 함께 초기화해주어야 함.
	pt2 = nullptr;


	/*
	
	메모리 누수 (Memory Leak)
	
	메모리를 사용하지 않는 채로 할당하는 것. 
	
	메모리 누수를 확인하는 법
	1. 프로그램이 큰 경우 컴퓨터의 작업관리자 - 성능 에서 메모리의 증가여부 확인
	2. 비쥬얼 프로그램 내에서 (디버그 - 진단도구) 창을 열고, 디버거 모드로 컴파일 

	new-delete은 상대적으로 속도가 느리기 때문에 
	가급적 남용하지 않는 것이 좋다. 

	*/

	while (true)
	{
		int *pointer = new int;
		cout << pointer << endl; 
	}

	return 0; 
}