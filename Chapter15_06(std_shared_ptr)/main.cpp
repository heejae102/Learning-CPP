#include<iostream>
#include"Resource.h"
using namespace std; 

/*

std::shared_ptr 

데이터를 소유하는 포인터가 1개로 한정된 유니크 포인터와 달리, 
하나의 데이터를 여러 개의 포인터가 참조할 수 있는 스마트 포인터. 

자신이 참조하고 있는 데이터를 몇 개의 포인터가 참조하고 있는지 
세어서 해당 카운트 데이터를 가지고 있는 것이 특징. 

여러 개의 포인터가 데이터를 가리키고 있는 경우, 
포인터의 카운트가 1이 된 상태에서 해당 포인터가 파괴될 때 메모리 해제 

유니크 포인터보다 느슨한 형태로, 
메모리를 엄격하게 관리해야 할 경우 유니크 포인터 
유연하게 여러 곳에서 관리해야 할 경우 쉐어드 포인터를 사용하면 좋다. 

*/


int main()
{
	//Resource *res = new Resource(3);
	//res->setAll(1);

	//std::shared_ptr<Resource> ptr1(res);

	//auto ptr1 = std::make_shared<Resource>(3);
	//ptr1->setAll(5);

	{
		{
			/*
			
			※ shared_ptr 사용 시 주의할 점 

			해당 포인터로 포인터를 넘겨받을 때, 이미 ptr1이 res를 넘겨받아서 
			포인터가 생성된 상태에서, ptr2가 ptr1을 통해 포인터를 생성하는 것이 아니라
			원본 객체의 포인터인 res를 통해 포인터를 생성할 경우,
			현재 shared_ptr가 가리키는 데이터를 참조하는 포인터의 개수를 확인 할 수 X 

			따라서, 하단과 같이 다수의 포인터를 생성할 때 
			shared_ptr을 받아어 생성하도록 하거나, std::make_shared<>를 사용할 것. 
			여러가지 면에서 std::make_shared<> 를 사용하여 생성하는 것이 더 안전 
			
			*/

			std::shared_ptr<Resource> ptr2(ptr1);

			//std::shared_ptr<Resource> ptr2(res);
			//auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;

			// 현재 ptr1, ptr2가 메모리를 소유한 상태로, ptr2가 사라지더라도 
			// ptr1이 남아있기 때문에 메모리가 해제되지 않는다. 
		}

		ptr1->print();

		std::cout << "Going out of the outer block" << std::endl; 

		// 메모리를 가리키는 포인터가 ptr1만 남은 상태에서, 
		// ptr1이 파괴되면서 메모리 해제 
	}

	return 0;
}