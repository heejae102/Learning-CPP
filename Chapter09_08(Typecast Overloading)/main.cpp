#include<iostream>
using namespace std; 

/*

<형변환을 오버로딩하기>

static_cast 오버로딩

*/

class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0)
	{
		_cents = cents;
	}

	int getCents() { return _cents; }
	void setCents(int cents) { _cents = cents; }

	// Cents 객체를 int형으로 형변환하는 함수  
	operator int()
	{
		return _cents;
	}
};

class Dollar
{
private:
	int _dollars = 0;

public:
	Dollar(const int &input) : _dollars(input) {}

	// 달러를 센트 단위(dollar*100)로 형변환하여 리턴하는 함수 
	operator Cents()
	{
		return Cents(_dollars * 100);
	}
};

void printInt(const int &value)
{
	cout << value << endl; 
}

int main()
{
	Cents cents(10);

	// 형변환 오버로딩 시 아래가 동일하게 작동. 
	//int value = (int)cents;
	//value = int(cents);
	//value = static_cast<int>(cents);

	// 형변환 오버로딩을 하고나면 정상 작동 
	printInt(cents);

	Dollar dol(2);

	// 2달러를 200 cents로 형변환 오버로딩 
	Cents cent = dol;

	printInt(cent);

	return 0;
}