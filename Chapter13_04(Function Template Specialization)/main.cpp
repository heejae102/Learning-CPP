#include<iostream>
#include"Storage.h"
using namespace std; 

/*

<�Լ� ���ø� Ư��ȭ>

���ø� ���α׷��� �� Ư���� �ڷ������� �ٸ� ����� 
�����ϰ� ���� �� ����ϴ� ��. 

*/

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// getMax��� templatized �� �Լ��� �ִµ�, 
// Ư���� ��� (char���� ���� instantiation�Ǵ� ���) ���� 
// �Ʒ� �Լ��� �����ϵ��� �ϴ� ��. 
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing char" << endl; 

	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(1, 2) << endl;

	// ���������δ� �̷��� ������� �۵�
	// cout << getMax<int>(1, 2) << endl; 
	
	// �Ű������� ������ Ÿ�� ��� ���������� Ÿ���� ������ ��� 
	// cout << getMax<double>(1, 2) << endl; 

	//=======================================================================//

	Storage<int> nValue(5);
	Storage<double> dValue(3.14);

	nValue.print();
	dValue.print();

	return 0;
}