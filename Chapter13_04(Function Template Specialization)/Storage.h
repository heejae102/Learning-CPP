#pragma once
#include<iostream>

template <class T>
class Storage
{
private:
	T _value; 

public:
	Storage(T value)
	{
		_value = value;
	}

	~Storage() {}

	void print()
	{
		std::cout << _value << '\n';
	}
};

// templatized �� Ŭ���� ������ print �Լ��� ����� �� 
// double Ÿ������ instantiation �� ��� Ư���ϰ� ó�� 

/*

�� ������ ���� �Ʒ��� �ڵ带 cpp ���Ϸ� �ű�� �Ǹ�, main���� ��� ���ϸ� 
include �Ǳ� ������ �Ʒ��� ���� Ư���� �ν��Ͻ� ��Ȳ�� ���ؼ��� �������� ���ϹǷ�
��� ���Ͽ� �ִ´�θ� �����ϰ� �ȴ�. 

�� �ذ��� 

1. ���ø��� Ư��ȭ�� �ʿ��� ��� ��� ���� ���� ��� �����Ѵ�. 
2. ��� ������ ���� �� �ΰ� �����Ѵ�. 
3. Ư���� �ν��Ͻ�ȭ�� ���� ���ǵ� cpp ������ main �� include �Ѵ�. 

3���� ���� ������ ������ �� �����Ƿ� �������� ����. ���������δ� 1���� ���� ���.
������Ʈ�� ��Ȳ�� ���� ������ ����� ���Ͽ� ����� ��. 

*/

template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << _value << '\n';
}

