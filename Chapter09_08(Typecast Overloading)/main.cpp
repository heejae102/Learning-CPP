#include<iostream>
using namespace std; 

/*

<����ȯ�� �����ε��ϱ�>

static_cast �����ε�

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

	// Cents ��ü�� int������ ����ȯ�ϴ� �Լ�  
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

	// �޷��� ��Ʈ ����(dollar*100)�� ����ȯ�Ͽ� �����ϴ� �Լ� 
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

	// ����ȯ �����ε� �� �Ʒ��� �����ϰ� �۵�. 
	//int value = (int)cents;
	//value = int(cents);
	//value = static_cast<int>(cents);

	// ����ȯ �����ε��� �ϰ��� ���� �۵� 
	printInt(cents);

	Dollar dol(2);

	// 2�޷��� 200 cents�� ����ȯ �����ε� 
	Cents cent = dol;

	printInt(cent);

	return 0;
}