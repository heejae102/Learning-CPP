#pragma once
#include<iostream>
#include<string>

/*

protected 나 public 접근 지정자를 사용하면 
자식 클래스에서 더 쉽게 부모클래스의 멤버에 접근하도록 
할 수 있지만, 그렇게 할 경우 해당 멤버를 수정할 일이 생겼을 때,
부모 클래스뿐만 아니라 자식 클래스까지도 일일이 수정해야 한다. 

따라서 가급적 수정 범위를 줄이기 위해서는 private 접근 지정자를
사용하고 부모의 멤버는 부모만 관리하는 것이 좋다. 

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

	// 자식 클래스에서 const로 getName을 접근하기 위해서는 
	// 해당 함수를 const 형식으로 선언해주어야 함. 
	std::string getName() const 
	{
		return _name; 
	}

	void doNothing() const
	{
		std::cout << _name << " is doing nothing" << std::endl;
	}
};

