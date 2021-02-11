#include<iostream>
using namespace std;

/*

<유도 클래스에서 출력 연산자 사용하기>

friend 출력 연산자는 오버로라이딩이 불가능.
따라서 출력 연산을 하는 멤버 함수는 따로 두고 
해당 함수를 통해 오버라이딩 구현 

*/

class Base
{
public:
	Base() {}

	// friend 함수는 멤버 함수가 아니기 때문에 직접 오버라이딩하는 것이 불가능
	// 따라서 출력 연산을 하는 멤버 함수는 따로 두고 해당 함수를 오버라이딩
	friend std::ostream &operator << (std::ostream &out, const Base &b)
	{
		return b.print(out);
	}

	virtual std::ostream &print(std::ostream &out) const
	{
		out << "Base";
		return out; 
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream &print(std::ostream &out) const override
	{
		out << "Derived";
		return out; 
	}
};

int main()
{
	Base base;
	std::cout << base << "\n";

	Derived derived;
	std::cout << derived << "\n";

	Base &bref = derived;
	std::cout << bref << "\n";

	return 0;
}