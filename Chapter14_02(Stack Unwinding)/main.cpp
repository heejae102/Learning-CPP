#include<iostream>
using namespace std; 

/*

<����ó���� ���� �ǰ���>

�Լ��� ��� �Լ��� ȣ���ϰ�, 
�� �Լ��� �� �ٸ� �Լ��� ȣ���Ѵٸ� 
������ ȣ�ⱸ���� ���ʴ�� �׿����� ��. 

���� ���� �� �ʿ� �ִ� �Լ��� ���ܸ� �����ٸ�
������ �ǰ��ư��鼭 ��� ���ܸ� ���� �� ã�� �ȴ�.

�� ���� �����⸦ �� ����, �ش� ���ܸ� catch ���� ���ϰ� �ǰ��⸦ �ϴ� ���
�ش� �Լ� ���� �ִ� ����� �����ϰ� ������ �������� �ǰ��� 
�ش� ���ܸ� catch�� ���Ŀ��� ���������� �Լ��� �۵��ϰ� �ȴ�.

���� throw�� �ڷ����� ��ġ�ϴ� catch ���� �������� ���� ���, ��Ÿ�� ���� �߻� 

*/


// �Լ��� �ڿ� throw(�ڷ���) -> �ش� �ڷ����� throw �� ���� �ִٴ� ���� ���
// ������ ����ũ�μ���Ʈ������ Ư�� �ڷ����� ���� �ͺ��ٴ� throw�Ѵٴ� ����� �ַ� ��� 
// �Ϲ������� �� ���̴� ������ �ƴϴ�. 
// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void last() /*throw()*/	// throw() ��ȣ ���� ��� ��� throw �Լ��� ������� �ʴ´ٴ� �ǹ� 
{
	cout << "Last" << endl;
	cout << "Throws exeption" << endl;

	// 1. throw ���� �����⸦ �����Ƿ� �� ������ ����� �����ϰ� �ǰ��� ���� 
	throw - 1;

	cout << "End last" << endl;
}

//void last()
//{
//	cout << "Last" << endl; 
//	cout << "Throws exeption" << endl; 
//
//	// 1. throw ���� �����⸦ �����Ƿ� �� ������ ����� �����ϰ� �ǰ��� ���� 
//	throw - 1;
//
//	cout << "End last" << endl; 
//}

void third()
{
	// 2. �ǰ��⸦ ���� last �Լ����� ������, catch���� �����Ƿ� �ٽ� �ǰ��� 

	cout << "Third" << endl; 

	last();

	cout << "End third" << endl; 
}

void second()
{
	// 3. �ǰ��⸦ ���� third �Լ����� �԰� catch ���� ����������,
	// -1(int) �� throw �����Ƿ� double �ڷ����� ��ġ���� �ʾ� �ٽ� �ǰ��� 

	cout << "Second" << endl; 

	try
	{
		third();
	}

	catch (double)
	{
		cerr << "Second caught double exception" << endl; 
	}

	cout << "End second" << endl; 
}

void first()
{
	// 4. �ǰ��⸦ ���� second �Լ����� �԰� catch ���� �����ϸ鼭,
	// throw �� ���� catch ���� �ڷ����� ��ġ�ϱ� ������ catch ���� ��� ���� 
	// ���ܸ� catch �����Ƿ� �ش� �Լ��� ������ ��� ���� ���������� ���� 

	cout << "First" << endl; 

	try
	{
		second();
	}

	catch (int)
	{
		cerr << "First caught int exception" << endl; 
	}

	cout << "End first" << endl; 
}

int main()
{
	cout << "Start" << endl; 

	try
	{
		first();
	}

	catch (int)
	{
		// cerr : cout �Լ��� ��ɻ� ����� �Լ� 
		cerr << "main caught int exception" << endl; 
	}

	// ��� �ڷ����� �� ���� �� �ִ� catch 
	catch (...)	// catch-all handlers
	{
		cerr << "main caught ellipsis exception" << endl; 
	}

	// uncaught exceptions

	cout << "End main" << endl; 

	return 0;
}