#include<iostream>
using namespace std; 

/*

<���� Ŭ������ ���>

*/

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl; 
	}
};

class MyArray
{
private:
	int _data[5];

public:
	int &operator [](const int &index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		//if (index < 0 || index >= 5) throw Exception();
		if (index < 0 || index >= 5) throw ArrayException();

		return _data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int &x)
	{
		cerr << "Exception" << x << endl; 
	}
	//catch (ArrayException &exception)
	//{
	//	// �ڽ� Ŭ������ throw�ϴµ�, �θ� Ŭ���� ���� catch ������
	//	// �ڽ� Ŭ���� ���� catch �������� ���� ���� ��� 
	//	// �θ� Ŭ���� ���� catch ������ ĳġ (��� ������ �ڷ����� �޶� catch ����)
	//	// => �ڽ� Ŭ���� ���� catch ������ ���� �÷��� �ذ� ���� 
	//	
	//	cout << "doSomething()" << endl; 
	//	exception.report();
	//	throw exception;
	//}
	catch (Exception &exception)
	{
		// �ڽ� Ŭ���� ���� ĳġ���� ���, ������ �߸� �������� 
		// �ڽ� Ŭ������ report �Լ��� �ƴ� �θ� Ŭ������ report �Լ� ���� 

		cout << "doSomething()" << endl;
		exception.report();
		
		// �ڽ� Ŭ���� ���� ĳġ�ص� �θ������� ������� �Ű������� throw�� ���
		// �θ� Ŭ���� ������ �Ѱ��ְ� ��. 

		// �ݸ�, �Ű������� ������� �ʰ� �׳� throw �� ��� ó�� �Ѱ��־���
		// �ڽ� Ŭ���� �״�� throw �ϰ� �ǹǷ� �ڽ� Ŭ���� ������ �Ѱ��ְ� ��. 
		//throw exception;
		throw;
	}
	//catch (ArrayException &exception)
	//{
	//	// �ڽ� Ŭ������ throw�ϴµ�, �θ� Ŭ���� ���� catch ������
	//	// �ڽ� Ŭ���� ���� catch �������� ���� ���� ��� 
	//	// �θ� Ŭ���� ���� catch ������ ĳġ (��� ������ �ڷ����� �޶� catch ����)
	//
	//	cout << "doSomething()" << endl;
	//	exception.report();
	//	throw exception;
	//}
}

int main()
{
	try
	{
		// doSomething �Լ� ���� �� �ش� �Լ� ������ 
		// throw - catch �� ��� �̷�����Ƿ�, main �Լ� ���� catch�� �۵����� X 
		// main �Լ� ���� catch ���� �۵��ϰ� �ϱ� ���ؼ��� ���ܸ� �ٽ� throw �ؾ� ��.
		doSomething();
	}
	catch (ArrayException &exception)
	{
		cout << "main()" << endl; 
		exception.report();
	}
	catch (Exception &exception)
	{
		cout << "main()" << endl;
		exception.report();
	}

	return 0;
}