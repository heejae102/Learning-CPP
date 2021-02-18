#include<iostream>
#include<memory>
#include"Resource.h"
using namespace std;

/*

std::unique_ptr

�����Ͱ� ����Ű�� �ִ� �������� �������� �� ������ ���� �� ���

��ü�� ����� �� �Ҹ��ڸ� �ڵ����� ȣ�� 


*/

auto doSomething()
{
	return std::unique_ptr<Resource>(new Resource(5));

	//auto res1 = std::make_unique<Resource>(5);
	//return res1;

	//return std::make_unique<Resource>(5);
}

// ����ũ ������ ���۷����� �Ű������� �޴� �Լ� 
// ����ũ �����ʹ� �������� �ϳ��̹Ƿ� ���⼭�� ���۷����� ���� 
// �Ϲ� ������ Ÿ������ ���� ���, ���簡 �Ͼ�Ƿ� ������ �߻� 
//void doSomething2(std::unique_ptr<Resource> &res)
//{
//	res->setAll(10);
//}

// �Ʒ��� ���� �Ű������� �޴� ���, 
// doSomething2(std::unique_ptr<Resource>(new Resource(10)));
// ���� ���� ������� �Ķ���͸� �ѱ� ���, 
// �Ϻ��ϰ� ��ü�� �������� ���� ���·� �Ѿ �� �־ ������. 
// ������ ���ÿ� �Ű������� �Ѱܾ� �ϴ� ��� �Ʒ��� ���� ����ؾ� ��.
// doSomething2(std::make_unique<Resource>(10));

// ���� ����ũ �����͸� �Ϲ� �Ű������� �Ѱܹ޴´ٸ�, ���� �Ѱ��� �� 
// move �Լ��� ����ؼ� �������� �����ϴ� ���·� �ؾ� ��. 
// �׷��� �Ѱܹ��� �����͸� �ٽ� ����ؾ��Ѵٸ� ���������� �Ѱ��� �� ����. 
//auto doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(10);
//	
//	return res;
//}

// ����ũ �����Ͱ� �ƴ�, ��ü�� ������������ �ޱ� 
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

		// �Ϲ� �����ͷ� ���� �� delete Ű���带 ���� �޸𸮸� �����ؾ� ������,
		// ����Ʈ �����ͷ� ���� ��, �ڵ����� �޸� ���� 
		//std::unique_ptr<Resource> res(new Resource(10000000));
	}

	//{
	//	// 1. �⺻ �ڷ������� ����Ʈ ������ ��� ���� 
	//	std::unique_ptr<int> upi(new int);

	//	// 2. ��ü�� ����Ű�� �뵵�� ��� ���� 
	//	std::unique_ptr<Resource> res1(new Resource(5));

	//	// 3. �޸𸮸� �����Ҵ��Ͽ� �ش� �����͸� ����Ű�� �뵵�� ��� ���� 
	//	//auto *ptr = new Resource(5);
	//	//std::unique_ptr<Resource> res1(ptr);

	//	// 4. make_unique ��ü �Լ��� ����Ͽ� �Ҵ�	// �����ϴ� ���
	//	//auto res1 = std::make_unique<Resource>(5);

	//	// 5. ���� ����� �Լ��� �־���� �Լ��� ���� �Ҵ� 
	//	//auto res1 = doSomething();


	//	//=======================================================================//
	//
	//
	//	std::unique_ptr<Resource> res2;

	//	res1->setAll(5);
	//	res1->print();

	//	// �����͸� bool�� ĳ�����Ͽ� �ش� �ش� �����Ͱ� NULL ������ Ȯ��
	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	// �� ��, ����ũ �����͸� ����(����)�ϴ� ���� �Ұ��� 
	//	// ����Ʈ �����ʹ� �������� �������� �� ������ �־���ϹǷ� 
	//	// �ش� �������� �ּҸ� �����ϰ� �Ǵ� ���� ������ �Ұ��� 
	//	// res2 = res1;
	//	
	//	// ���� Copy semantics�� �Ұ����ϰ�, Move semantics�� ���� 
	//	// Move semantics�� �������� �ʰ� �����Ǹ� �����ϴ� ���̹Ƿ� ���� 
	//	// ����ִ� Nullptr�� res2�� res1�� �ּҸ� ���� 
	//	res2 = std::move(res1);

	//	std::cout << std::boolalpha;
	//	std::cout << static_cast<bool>(res1) << std::endl;
	//	std::cout << static_cast<bool>(res2) << std::endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) res2->print();	// (*res2).print(); �� ����
	//}

	{
		auto res1 = std::make_unique<Resource>(5);

		res1->setAll(0);
		res1->print();

		// 1. ����ũ ������ ���۷����� �Ű������� �޴� ��� 
		//doSomething2(res1);

		// 2. ����ũ �����͸� move �Լ��� �ѱ��, ���� ������ �ٽ� �޾� �����ϴ� ���
		//res1 = doSomething2(std::move(res1));
		//res1->print();

		// 3. ����ũ �����Ͱ� ����Ű�� �������� ���������� �Ű������� �޴� ��� 
		doSomething2(res1.get());
		res1->print();
	}

	{
		// ����ũ �����͸� ����� �� ���� ���ƾ� �� ��.

		// 1. ����ũ �����ʹ� �����ְ� �ϳ����� �����ͷ�, 
		// ����ũ �����Ͱ� ����Ű�� �ִ� �����͸� �ٸ� �����Ͱ� ����ų �� X 
		// �� �ϳ��� �����͸� �ϳ��� ����ũ �����Ͱ� ����Ű�� �Ѵ�. 

		// 2. ����ũ �����ʹ� ����Ʈ �����ͷ�, �����Ͱ� �ı��� �� �ڵ����� �޸𸮸� ���� 
		// ���� �߰������� �ش� �޸𸮸� ������ ���, �̹� ������ �޸𸮸� 
		// �ٽ� �����Ϸ��� �ϴ� ���̹Ƿ� ���� �߻� 

		Resource *res = new Resource;

		// res�� �� ���� ����ũ �����Ͱ� ����Ű�� ����.
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		// �ڵ����� �����Ǵ� �޸𸮸� �ٽ� ����� ���̹Ƿ� X
		delete res;
	}

	return 0;
}