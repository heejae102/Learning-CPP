#include<iostream>
#include<memory>
#include<string>
using namespace std;

/*

<��ȯ ������ ����(Circular Dependency Issues)�� std::weak_ptr>

shared_ptr �����͸� ��� �� �߻��� �� �ִ� ��ȯ ������ ����
�ش� ������ �ذ��ϱ� ���ؼ� weak_ptr ��� 

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

	// PartnerUp �Լ��� �����ϰ� ���� �޸� ������ �̷������ ����. 
	// �� ��ü�� ���ΰ� ���θ� �����ϰ� �Ǿ� ī��Ʈ�� 1�� ���� �ʱ� ������ 
	// �޸𸮰� �������� �ʰ� ��. => ��ȣ ������ ���� 

	// �̷��� ��쿡�� shared_ptr ��� weak_ptr �� ����ϸ� ���� �ذ� ����
	// ��, weak_ptr �� ��� ���빰�� ����ؾ� �� �� ���� ����� �� ���� 
	// ptr.lock()�� ���� shared_ptr ���·� �ٲپ� ����ؾ� ��. 
	partnerUp(lucy, ricky);

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}