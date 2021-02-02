#include<iostream>
#include<cassert>
using namespace std; 

/*

<���� ������>

�ڱ��ڽ�(��ü)�� �Ȱ��� Ÿ���� �ν��Ͻ��� �Ű������� �޴� ������

*/

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	Fraction(int num = 0, int den = 1)
		: _numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

	// copy constructor (���� ������)
	// ���� �� ���� ���� ������ ���� �����ڸ� �ܺο��� ����ϴ� ���� ���ƾ� �ϴ� ���
	// private ���������ڷ� �������ָ� �ȴ�. 
	Fraction(const Fraction &fraction)
		: _numerator(fraction._numerator), _denominator(fraction._denominator)
	{
		cout << "Copy Constructor Called" << endl; 
	}

	friend std::ostream &operator << (std::ostream &out, const Fraction &f)
	{
		out << f._numerator << " / " << f._denominator << endl;
		return out; 
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	
	cout << &temp << endl; 
	return temp;
}

int main()
{
	Fraction fraction(3, 5);


	// ���� ������, ���� �ʱ�ȭ ��� ���� �����ڰ� ȣ��ȴ�. 

	//Fraction fr_copy1(fraction);		// copy constructor 
	//Fraction fr_copy2 = fraction;		// copy initialization

	// �ӽ� ��ü�� ����ϴ� ��� ���� �����ڰ� �����ȴ�. 
	// ��, ���� �����ڰ� ���ʿ��� ��� ����ȭ�� ���� �����Ϸ����� ���� ó�� 
	Fraction fr_copy3(Fraction(1, 3));
	
	cout << fr_copy3 << endl; 


	//-----------------------------------------------------------------//


	// �Լ����� ���� �� copy initialization�� ��ġ�鼭 ���� ������ ȣ�� (Debug ���)
	// ������, ���� ��带 release�� �ٲٸ� ���� �����ڰ� ȣ����� �ʴ´�. 
	// ���� ����� �Լ��� ����� ���� �� �ʿ䰡 �����Ƿ�,
	// ���� ����� result�� �ٷ� �Ű�����. => ��ȯ�� ����ȭ(Return Value Optimization)

	// ���� Debug ��忡���� �Լ� �� ��ü�� �ּҿ� �������� �Ѱܹ��� ��ü�� �ּҰ� �ٸ�����,
	// Release ��忡���� �Լ� �� ��ü�� �ּҿ� �������� �Ѱܹ��� ��ü�� �ּҰ� ��ġ�Ѵ�. 

	Fraction result = doSomething();
	
	cout << &result << endl; 
	cout << result << endl; 

	return 0; 
}