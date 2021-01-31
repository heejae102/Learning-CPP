#include<iostream>
using namespace std; 

/*

<���� ������ �����ε�>

*/

class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0) { _cents = cents; }
	
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	// ���� ������(-) �����ε� 
	Cents operator - () const
	{
		return Cents(-_cents);
	}

	// ���� ������(!) �����ε� 
	bool operator ! () const
	{
		// ������ ���������� ���� ��(���α׷��� ������ ����) �����ϱ� 

		// !Cents(...)
		// ex. ��� ���� 0�� ��� true, �ƴ� ��� false ����

		return (_cents == 0) ? true : false;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents &cents)
	{
		out << cents._cents;
		return out;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(0);

	cout << cents1 << endl;
	cout << -cents1 << endl; 
	cout << -(Cents(-10)) << endl;

	cout << !cents1 << " " << !cents2 << " " << !Cents(0) << endl; 

	return 0;
}