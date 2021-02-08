#include<iostream>
using namespace std; 

/*

<���� ��� �Լ�>

*/

class Something
{
public:
	// �̳� Ŭ���� : static ��� ������ ��ü ������ �ʱ�ȭ �ϴ� ���. ���������� �����ؼ� �ʱ�ȭ. 
	class _init
	{
	public:
		_init() { s_value = 9876; }
	};

private:
	// static ��� ������ ���� Ŭ������ ��� �ν��Ͻ����� ���� ����(�ϳ��� �ּҷ� ��ΰ� ����)
	static int s_value; 
	int m_value;

	static _init s_initializer;	// �̳� Ŭ���� ���� 

public:
	// static ��� ������ �����ڿ��� �ʱ�ȭ �Ұ��� 
	// ���⼭ static ��� ������ �ʱ�ȭ�Ϸ��� �����ڰ� static�� �Ǿ�� �ϸ�, static �����ڴ� �������� ����.
	Something() :m_value(123)/*, s_value(1024)*/ {}

	static int getValue() 
	{
		// static ��� �Լ� �������� this �����͸� ����� �� ����. 
		// ��, ��������� this �����͸� ����ϴ� ���� �Ұ����� �� �ƴ϶�, 
		// this �����͸� ����ؼ� ������ �� �ִ� ��� ����� ���� ������ �Ұ����ϴ�. 
		
		// 1. this ������ ���� ��� �Ұ� 
		//return this.s_value;
		
		// 2. this ������ ���� ��� �Ұ� 
		// m_value�� this.m_value �� ���� �����̹Ƿ� ���� �Ұ��� 
		//return m_value;
		
		return s_value; 
	}
	
	int temp() { return this->s_value; }
};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{
	// 1.�ش� static ����� private���� ������ direct�� ���� �Ұ���  
	//cout << Something::s_value << endl; 

	// 1���� ��� �ش� ����� ȣ���ϴ� �Լ��� static���� �ٲٸ� �������� ������� 
	// Ư�� �ν��Ͻ� ���̵� ���� ���� 
	cout << Something::getValue() << endl; 

	Something s1;
	//cout << s1.getValue() << endl; 
	//cout << s1._value << endl; 

	// non-static ��� �Լ� ������ ���� 
	int (Something::*fptr1)() = &Something::temp;
	
	/*
	
	Something�̶�� Ŭ���� ���� �����ִ� ����Լ� temp�� �����͸� ������ �ִµ�, 
	�� �������� ��ġ�� �ִ� �Լ��� �����ų �� 's1'�̶�� �ν��Ͻ��� �����͸� �Ѱ��ְ�, 
	's1'�̶�� �ν��Ͻ��� this �����͸� �����ٰ� �ش� �Լ��� �۵���Ű�� ���� 

	���� 's1'�� ���� ������ �۵����� ����. 
	non-static ����Լ��� �ν��Ͻ��� ���ӵ� ���·� �����Ǿ� �ֱ� ������, 
	this �����͸� �Ѱ����� ������ �Լ��� �۵����� �ʴ´�. 
	��, ��� ��� ������ ��� �Լ��� this �����Ͱ� ������ �ִ� ���¶�� �� �� �ִ�. 

	(����Լ��� �ϳ��� �Լ��� �ν��Ͻ��鳢�� �����ϸ�, this �����ͷ� �ش� �Լ��� �ּҿ� 
	�����ϰ��� �ϴ� �ν��Ͻ��� �ּҸ� �Ѱ��ָ� �ش� �ν��Ͻ��� ��� ���� ����Ͽ� �Լ��� ����)
	
	*/

	// non-static ��� �Լ� ������ ��� 
	cout << (s1.*fptr1)() << endl; 

	// static ��� �Լ� ������ ����  
	// static ��� �Լ��� Ư�� �ν��Ͻ��� ������� ȣ�� �����ϹǷ� '��ü��::' �� ���־�� ��.  
	int(*fptr2)() = &Something::getValue;

	// static ��� �Լ� ������ ��� 
	// Ư�� �ν��Ͻ��� ��ġ�� �ʰ� �ٷ� ��� ���� 
	cout << fptr2() << endl; 

	return 0; 
}