#include<iostream>
#include<memory>
#include<string>
using namespace std;

/*

<순환 의존성 문제(Circular Dependency Issues)와 std::weak_ptr>

shared_ptr 포인터를 사용 시 발생할 수 있는 순환 의존성 문제
해당 문제를 해결하기 위해서 weak_ptr 사용 

*/

class Person
{
	std::string _name;
	//std::shared_ptr<Person> _partner;
	std::weak_ptr<Person> _partner;

public:
	Person(const std::string &name) : _name(name)
	{
		std::cout << _name << " created\n";
	}

	~Person()
	{
		std::cout << _name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->_partner = p2;
		p2->_partner = p1;

		std::cout << p1->_name << " is partnered with " << p2->_name << "\n";

		return true; 
	}

	const std::shared_ptr<Person> getPartner() const
	{
		return _partner.lock();
	}

	const std::string &getName() const
	{
		return _name;
	}
};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	// PartnerUp 함수를 실행하고 나면 메모리 해제가 이루어지지 않음. 
	// 두 객체가 서로가 서로를 참조하게 되어 카운트가 1이 되지 않기 때문에 
	// 메모리가 해제되지 않게 됨. => 상호 의존성 문제 

	// 이러한 경우에는 shared_ptr 대신 weak_ptr 을 사용하면 문제 해결 가능
	// 단, weak_ptr 의 경우 내용물을 사용해야 할 때 직접 사용할 수 없고 
	// ptr.lock()을 통해 shared_ptr 형태로 바꾸어 사용해야 함. 
	partnerUp(lucy, ricky);

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}