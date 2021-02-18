#include<iostream>
#include<memory>
#include"Resource.h"
using namespace std;

/*

std::unique_ptr

포인터가 가리키고 있는 데이터의 소유권이 한 곳에만 속할 때 사용

객체가 사라질 때 소멸자를 자동으로 호출 


*/

auto doSomething()
{
	return std::unique_ptr<Resource>(new Resource(5));

	//auto res1 = std::make_unique<Resource>(5);
	//return res1;

	//return std::make_unique<Resource>(5);
}

// 유니크 포인터 래퍼런스를 매개변수로 받는 함수 
// 유니크 포인터는 소유권이 하나이므로 여기서도 래퍼런스를 빼고 
// 일반 포인터 타입으로 받을 경우, 복사가 일어나므로 문제가 발생 
//void doSomething2(std::unique_ptr<Resource> &res)
//{
//	res->setAll(10);
//}

// 아래와 같이 매개변수를 받는 경우, 
// doSomething2(std::unique_ptr<Resource>(new Resource(10)));
// 위와 같은 방식으로 파라미터를 넘길 경우, 
// 완벽하게 객체가 생성되지 않은 상태로 넘어갈 수 있어서 위험함. 
// 생성과 동시에 매개변수로 넘겨야 하는 경우 아래와 같이 사용해야 함.
// doSomething2(std::make_unique<Resource>(10));

// 굳이 유니크 포인터를 일반 매개변수로 넘겨받는다면, 값을 넘겨줄 때 
// move 함수를 사용해서 소유권을 이전하는 형태로 해야 함. 
// 그런데 넘겨받은 포인터를 다시 사용해야한다면 리턴형으로 넘겨줄 수 있음. 
//auto doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(10);
//	
//	return res;
//}

// 유니크 포인터가 아닌, 객체의 포인터형으로 받기 
void doSomething2(Resource *res)
{
	res->setAll(100);
}

int main()
{
	{
		//Resource *res = new Resource(10000000);

		// early return or throw

		//delete res;

		// 일반 포인터로 생성 시 delete 키워드를 통해 메모리를 해제해야 하지만,
		// 스마트 포인터로 생성 시, 자동으로 메모리 해제 
		//std::unique_ptr<Resource> res(new Resource(10000000));
	}

	//{
	//	// 1. 기본 자료형에도 스마트 포인터 사용 가능 
	//	std::unique_ptr<int> upi(new int);

	//	// 2. 객체를 가리키는 용도로 사용 가능 
	//	std::unique_ptr<Resource> res1(new Resource(5));

	//	// 3. 메모리를 동적할당하여 해당 포인터를 가리키는 용도로 사용 가능 
	//	//auto *ptr = new Resource(5);
	//	//std::unique_ptr<Resource> res1(ptr);

	//	// 4. make_unique 자체 함수를 사용하여 할당	// 권장하는 방식
	//	//auto res1 = std::make_unique<Resource>(5);

	//	// 5. 위의 방법을 함수에 넣어놓고 함수를 통해 할당 
	//	//auto res1 = doSomething();


	//	//=======================================================================//
	//
	//
	//	std::unique_ptr<Resource> res2;

	//	res1->setAll(5);
	//	res1->print();

	//	// 포인터를 bool로 캐스팅하여 해당 해당 포인터가 NULL 값인지 확인
	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	// ※ 단, 유니크 포인터를 대입(복사)하는 것은 불가능 
	//	// 유니트 포인터는 데이터의 소유권이 한 군데만 있어야하므로 
	//	// 해당 데이터의 주소를 공유하게 되는 대입 연산이 불가능 
	//	// res2 = res1;
	//	
	//	// 따라서 Copy semantics는 불가능하고, Move semantics만 가능 
	//	// Move semantics는 복사하지 않고 소유권만 이전하는 것이므로 가능 
	//	// 비어있는 Nullptr인 res2에 res1의 주소를 이전 
	//	res2 = std::move(res1);

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) res2->print();	// (*res2).print(); 도 가능
	//}

	{
		auto res1 = std::make_unique<Resource>(5);

		res1->setAll(0);
		res1->print();

		// 1. 유니크 포인터 래퍼런스를 매개변수로 받는 경우 
		//doSomething2(res1);

		// 2. 유니크 포인터를 move 함수로 넘기고, 리턴 값으로 다시 받아 저장하는 경우
		//res1 = doSomething2(std::move(res1));
		//res1->print();

		// 3. 유니크 포인터가 가리키는 데이터의 포인터형을 매개변수로 받는 경우 
		doSomething2(res1.get());
		res1->print();
	}

	{
		// 유니크 포인터를 사용할 때 하지 말아야 할 것.

		// 1. 유니크 포인터는 소유주가 하나뿐인 포인터로, 
		// 유니크 포인터가 가리키고 있는 데이터를 다른 포인터가 가리킬 수 X 
		// 꼭 하나의 데이터를 하나의 유니크 포인터가 가리키야 한다. 

		// 2. 유니크 포인터는 스마트 포인터로, 데이터가 파괴될 때 자동으로 메모리를 해제 
		// 따라서 추가적으로 해당 메모리를 해제할 경우, 이미 해제된 메모리를 
		// 다시 해제하려고 하는 것이므로 오류 발생 

		Resource *res = new Resource;

		// res를 두 개의 유니크 포인터가 가리키고 있음.
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		// 자동으로 해제되는 메모리를 다시 지우는 것이므로 X
		delete res;
	}

	return 0;
}