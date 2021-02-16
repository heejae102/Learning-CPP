#include<iostream>
#include"Resource.h"
#include"AutoPtr.h"
using namespace std; 

/*

<'이동'의 의미와 스마트 포인터 소개>

Move semantics
포인터 간의 대입으로 하나의 메모리를 여러 개의 포인터가 가리키는 문제를 방지하기 위해
포인터 대입(or 복사) 시 대입되는 파라미터의 주소를 넘겨주고, 파라미터는 nullptr로 
만들어서 메모리 소유권을 이전하는 방식.

클래스로 간단하게 구현 한 AutoPtr 은 C++에서 사용이 중지된 문법으로, 
스마트 포인터의 작동원리를 익히게 위해 간단하게 구현한 것으로 참고만 할 것. 

*/

// RAII : resource acquisition is initialization

void doSomething()
{
	// 아래의 경우 예외를 throw 하는 경우 메모리 해제를 하지못해 메모리 누수 발생 
	try
	{
		//Resource *res = new Resource;	// dull pointer

		AutoPtr<Resource> res = new Resource;	// smart pointer

		// work with res
		if (true)
		{
			throw - 1;	// exception
		}
		
		//delete res;
	}
	catch (...)
	{

	}

	//Resource *res = new Resource;

	//// work with res
	//if (true)
	//{
	//	delete res;		// 메모리 해제를 하지 않은채로 return 하는 것 방지 
	//	return;			// early return 
	//}

	//delete res; 

	return; 
}

int main()
{
	//doSomething();

	// AutoPtr 의 한계 

	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1._ptr << endl; 
		cout << res2._ptr << endl; 
		
		// 비어있는 nullptr인 res2 에 res1 의 주소 대입 
		// -> res1, res2가 모두 같은 메모리 주소를 가리키게 된다. 
		// -> 추후 메모리 해제 시 하나의 메모리를 두 번 해제하게 되어 오류 발생 

		// 가장 쉽게 문제를 해결하는 방법은 소유권을 이전하여
		// 메모리의 소유주를 하나의 객체로 유지하는 것. 
		// 이러한 방법을 'Move semantics' 라고 부른다. 
		// 즉, 아래의 대입 연산자는 Copy semantics 를 구현한 것이 아니라 
		// Move semantics 를 구현한 것이라고 할 수 있다. 
		res2 = res1;

		cout << res1._ptr << endl; 
		cout << res2._ptr << endl; 
	}

	return 0;
}