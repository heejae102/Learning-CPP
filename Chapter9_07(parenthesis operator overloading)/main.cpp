#include<iostream>
using namespace std; 

/*

<��ȣ ������ �����ε�>

��ȣ �����ڴ� Ư¡ �� �Լ��� ȣ���ϴ� ��ȣ�� ����ϹǷ�,
�Լ���üó�� ����� �� ����. 

*/

class Accumulator
{
private:
	int _counter = 0;

public:
	int operator() (int i)
	{
		// counter �� i ���� ���� �� �����ϴ� ���� 
		return (_counter += i);
	}
};

int main()
{
	Accumulator acc;

	// ��ġ �Լ��� ����ϴ� �Ͱ� ����� ���·�, �̸� 'functor'��� �θ�.

	cout << acc(10) << endl; 
	cout << acc(20) << endl; 

	return 0;
}