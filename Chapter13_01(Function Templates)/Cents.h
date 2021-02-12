#pragma once
#include<iostream>

/*

템플릿 내에서 사용할 수 있도록 
출력 연산자, 부등호 연산자 오버로딩이 이루어져야 함. 

*/

class Cents
{
private:
	int _cents;

public:
	Cents(int cents)
		: _cents(cents) {}

	friend bool operator > (const Cents &c1, const Cents &c2)
	{
		return (c1._cents > c2._cents);
	}

	friend std::ostream &operator << (std::ostream &out, const Cents &cents)
	{
		out << cents._cents << " cents ";
		return out;
	}
};

