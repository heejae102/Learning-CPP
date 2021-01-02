#include<iostream>
#include<string>
using namespace std; 

/*

class�� const������ ���� �� ���

1. �ش� Ŭ���� �� ������� ���� �Ұ�
2. const������ �����  ��� �Լ��� ȣ�� ����
3. �Լ� ���ο��� ��� ���� �������� �ʴ��� �Լ��� const������ ������� �ʾ��� ��� ȣ�� �Ұ�
4. const������ ����� �Լ���� ������ ���� �ڵ忡 ��� �������� �����ϴ�
������ ���� ��� �ش� �Լ��� ȣ�� �Ұ��� (���ʿ� ������ �ܰ迡�� ����)
5. ����Լ��� const������ ������ �� �ִ� ���, const������ �����ϴ� ���� ���� ������ ���� 

*/

class Something
{
public:
	int _value = 0;
	 
	/*
	
	<Copy Constructor>
	
	- ���� Ŭ������ ��ü�� �Ű������� �޾� ��ü�� �ʱ�ȭ�ϴ� ��.  
	- ����Ʈ �����ڰ� �����ϵ� ����Ʈ ���� �����ڵ� ���� 
	- �����ڰ� �����ϴ��� ��������ڰ� ���ǵǾ����� ���� ���, 
	����Ʈ ���� �����ڰ� �ڵ����� ȣ��Ǿ� ��� �� ��� ���� ���� 
	
	*/
	//���� ����Ʈ �����ڰ� �����ϵ���, 
	//����Ʈ ���� �����ڰ� ������ ����. 
	Something(const Something &input)
	{
		_value = input.getValue();

		cout << "Copy Constructor" << endl; 
	}

	Something()
	{
		cout << "Constructor" << endl; 
	}

	void setValue(int value) { _value = value; }
	int getValue() const { return _value; } 
};

// �Ű������� ��ü�� �����鼭 ���� ������ ȣ�� 
// ���� ���� �Ű������� �Ѿ�� ��ü�� ������ ���̹Ƿ� 
// �� ��ü�� �ּҿ� �Լ� �� ��ü�� �ּҴ� ���� �ٸ�. 
//void print(Something sth)
//{
//	cout << &sth << endl; 
//	cout << sth._value << endl; 
//}

// ���� �����ڸ� ���� �� ��ü�� ����� ���� ������ �������Ƿ� 
// ���۷����� ���� �Ű������� �Ѿ���� ��ü ��ü�� �����ϴ� ���� ���������� ��� (�ּ� ��ġ)
void print(const Something &sth)
{
	cout << &sth << endl;
	cout << sth._value << endl;
}

class Test
{
public:
	string _value = "default";

	// �Լ��� const�� ������ ���� �Լ� �����ε� ���� 
	// ���� �Լ��� const������ ������ ��� �������� const�� �����ϴ� ���� �Ϲ���  
	const string &getValue() const 
	{
		cout << "Const Version" << endl; 

		return _value; 
	}

	string& getValue() 
	{
		cout << "Non-const Version" << endl; 

		return _value; 
	}
};

int main()
{
	const Something sth;

	//sth.setValue(3);

	// getValue �Լ��� const������ �������� �ʾ��� ���� ���� �߻� 
	//cout << sth.getValue() << endl; 
	//cout << &sth << endl; 
	//print(sth);

	// ��� �Լ��� const ������ ���� �����ε��� ��� 
	// const������ ����� Ŭ���������� const�� �Լ� ȣ�� 
	// �׷��� ���� ��� non-const�� �Լ� ȣ�� 

	Test test1; 
	cout << test1.getValue() << endl; 

	const Test test2;
	test2.getValue();

	return 0;
}