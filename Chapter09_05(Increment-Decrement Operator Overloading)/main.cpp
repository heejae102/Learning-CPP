#include<iostream>
using namespace std; 

/*

<���� ������ �����ε�>

���� �����ڴ� �������̳�, �������̳Ŀ� ����
���� ����� �ٸ��Ƿ� �׿� �°� �����ε��ϱ� 

*/

class Digit
{
private:
	int _digit;

public:
	Digit(int digit = 0) : _digit(digit) {}

	// ������ (prefix)
	Digit& operator ++ ()
	{
		++_digit;

		// �ڱ� �ڽ��� ���� (�ڱ� �ڽ��� ���� ���� �����ϹǷ� ���۷��������� ����)
		return *this; 
	}

	// ������ (postfix) : �������� ��� �Ķ���ͷ� ���� �����͸� �־���. 
	Digit operator++ (int)
	{
		// �������� ��� �ϴ� ������ ���� ���� ���� �ٲٴ� ����

		Digit temp(_digit);
		//_digit++;

		// �̹� ������ ������ �����ε��� ��������Ƿ�, �ش� ������ε� ����
		++(*this);

		return temp;
	}

	// ����� ������ �����ε� 
	friend ostream& operator << (ostream &out, const Digit &d)
	{
		out << d._digit;
		return out;
	}
};

int main()
{
	Digit d(5);

	cout << ++d << endl; 
	cout << d << endl; 

	cout << d++ << endl; 
	cout << d << endl; 

	return 0;
}