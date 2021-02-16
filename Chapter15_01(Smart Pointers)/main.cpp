#include<iostream>
#include"Resource.h"
#include"AutoPtr.h"
using namespace std; 

/*

<'�̵�'�� �ǹ̿� ����Ʈ ������ �Ұ�>

Move semantics
������ ���� �������� �ϳ��� �޸𸮸� ���� ���� �����Ͱ� ����Ű�� ������ �����ϱ� ����
������ ����(or ����) �� ���ԵǴ� �Ķ������ �ּҸ� �Ѱ��ְ�, �Ķ���ʹ� nullptr�� 
���� �޸� �������� �����ϴ� ���.

Ŭ������ �����ϰ� ���� �� AutoPtr �� C++���� ����� ������ ��������, 
����Ʈ �������� �۵������� ������ ���� �����ϰ� ������ ������ ���� �� ��. 

*/

// RAII : resource acquisition is initialization

void doSomething()
{
	// �Ʒ��� ��� ���ܸ� throw �ϴ� ��� �޸� ������ �������� �޸� ���� �߻� 
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
	//	delete res;		// �޸� ������ ���� ����ä�� return �ϴ� �� ���� 
	//	return;			// early return 
	//}

	//delete res; 

	return; 
}

int main()
{
	//doSomething();

	// AutoPtr �� �Ѱ� 

	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1._ptr << endl; 
		cout << res2._ptr << endl; 
		
		// ����ִ� nullptr�� res2 �� res1 �� �ּ� ���� 
		// -> res1, res2�� ��� ���� �޸� �ּҸ� ����Ű�� �ȴ�. 
		// -> ���� �޸� ���� �� �ϳ��� �޸𸮸� �� �� �����ϰ� �Ǿ� ���� �߻� 

		// ���� ���� ������ �ذ��ϴ� ����� �������� �����Ͽ�
		// �޸��� �����ָ� �ϳ��� ��ü�� �����ϴ� ��. 
		// �̷��� ����� 'Move semantics' ��� �θ���. 
		// ��, �Ʒ��� ���� �����ڴ� Copy semantics �� ������ ���� �ƴ϶� 
		// Move semantics �� ������ ���̶�� �� �� �ִ�. 
		res2 = res1;

		cout << res1._ptr << endl; 
		cout << res2._ptr << endl; 
	}

	return 0;
}