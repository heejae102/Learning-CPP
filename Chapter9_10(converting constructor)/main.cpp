#include<iostream>
#include<cassert>
using namespace std; 

/*

<��ȯ ������ >

�Ķ���� ���� �˾Ƽ� ��ȯ�ؼ� ��ü ���� 
explicit Ű���带 ����� ��� ��ȯ �����ڰ� �۵����� �ʴ´�. 

explicit : �ش� Ű���带 ������ �տ� ����� ���, 
		   ��ȯ �����ڰ� �۵����� �ʴ´�.

delete : ���� ���������� ��������� �� ���������� 
		 ������� �ʴ� ��쿡 ���� ��� 

*/

class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	// �Ű������� char�� ������ �Է¹޴� ���� ������� �ʴ´ٴ� �ǹ� 
	// �������� �ϸ鼭, ������� ������ ���� ������� ����� ���� �����ϰų�,
	// �ڵ� ��ȯ, �ڵ� ĳ������ �����Ǿ ����ϱ⵵ �Ѵ�. 
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1)
		: _numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

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

void doSomething(Fraction frac)
{
	cout << frac << endl; 
}

int main()
{
	Fraction frac(7);

	doSomething(frac);			// ���� ������ ȣ��. 
	doSomething(Fraction(7));	// �ӽ� ��ü�� ����ؼ� ���� �����ڰ� ������. 


	// doSomething�� �Ű����� Fraction�� 7�� �Ķ���ͷ� 
	// �־ �ʱ�ȭ�� ��ó�� �۵� 
	// explicit Ű���带 ����� ��� ��ȯ �����ڰ� �۵����� X

	//doSomething(7);			// ��ȯ �����ڰ� �۵��ϴ� ��� 

	// delete Ű����� char�� �Ű������� ���� �ʵ��� ���������Ƿ�, ���� �߻� 
	//Fraction f('c');

	return 0;
}