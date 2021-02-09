#include<iostream>
using namespace std;

/*

<가상 소멸자>

*/

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *_array;

public:
	Derived(int length)
	{
		_array = new int[length];
	}

	~Derived() override
	{
		cout << "~Derived()" << endl;
		delete[] _array;
	}
};

int main()
{
	//Derived derived(5);

	/*

	<다향성을 이용하여 자식 클래스의 메모리 해제>

	자식 클래스를 무엇으로 만들었는지 모르는 경우가 대부분이기 때문에
	기초 클래스 포인터를 통해 자식 클래스의 메모리를 해제하는 경우가 많다.

	하지만 이렇게 자식 클래스를 가리키는 부모 포인터를 통해 메모리를 해제 할 경우
	자식 클래스의 소멸자는 호출되지 않고, 부모 클래스의 소멸자만 호출되는 문제 발생.
	결국 자식 클래스에서 할당된 메모리가 해제되지 않아서 메모리 누수가 발생하게 된다.

	이러한 경우 virtual 키워드를 사용하면 자식 클래스의 소멸자와
	부모 클래스의 소멸자가 모두 호출되므로 문제가 해결된다.
	(자식 클래스 소멸자 호출 -> 부모 클래스 소멸자 호출)

	※ 부모 - 자식 클래스 간에 소멸자도 override 키워드를 사용하여
	오버라이딩할 수 있는데, 상위 클래스에 virtual 키워드를 붙였을 때만 가능

	*/

	Derived *derived = new Derived(5);
	Base *base = derived;
	delete base;

	return 0;
}