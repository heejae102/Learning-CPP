#include<iostream>
using namespace std; 

/*

<단항 연산자 오버로딩>

*/

class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0) { _cents = cents; }
	
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	// 단항 연산자(-) 오버로딩 
	Cents operator - () const
	{
		return Cents(-_cents);
	}

	// 단항 연산자(!) 오버로딩 
	bool operator ! () const
	{
		// 무엇을 리턴할지는 문맥 상(프로그램의 목적에 따라) 결정하기 

		// !Cents(...)
		// ex. 멤버 값이 0일 경우 true, 아닐 경우 false 리턴

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