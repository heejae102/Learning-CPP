#pragma once
#include<iostream>
#include<string>

/*

protected �� public ���� �����ڸ� ����ϸ� 
�ڽ� Ŭ�������� �� ���� �θ�Ŭ������ ����� �����ϵ��� 
�� �� ������, �׷��� �� ��� �ش� ����� ������ ���� ������ ��,
�θ� Ŭ�����Ӹ� �ƴ϶� �ڽ� Ŭ���������� ������ �����ؾ� �Ѵ�. 

���� ������ ���� ������ ���̱� ���ؼ��� private ���� �����ڸ�
����ϰ� �θ��� ����� �θ� �����ϴ� ���� ����. 

*/

class Person
{
private:
	std::string _name;

public:
	Person(const std::string &name_in = "No Name")
		: _name(name_in) {}

	void setName(const std::string &name_in)
	{
		_name = name_in;
	}

	// �ڽ� Ŭ�������� const�� getName�� �����ϱ� ���ؼ��� 
	// �ش� �Լ��� const �������� �������־�� ��. 
	std::string getName() const 
	{
		return _name; 
	}

	void doNothing() const
	{
		std::cout << _name << " is doing nothing" << std::endl;
	}
};

