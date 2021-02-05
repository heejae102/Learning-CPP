#include<iostream>
using namespace std; 

class Mother
{
// private ���� �����ڴ� �ڽ� Ŭ���������� ������ �Ұ���
// protectd�� ���� �� �ڽ� Ŭ���������� ���� ���� 
protected:
	int _i;

public:
	Mother(const int &i_in)
		: _i(i_in) 
	{
		std::cout << "Mother Constructor Called" << std::endl;
	}

	void setValue(const int &i_in)
	{
		_i = i_in;
	}

	int getValue()
	{
		return _i;
	}
};

/*

1. Ŭ�������� �������� �κе��� ��� �θ� Ŭ������ ����� ����ϵ��� �����ν� �ڵ��� �� ��
2. �ڽ�Ŭ������ �θ�Ŭ�����κ��� ���� �͵��� ���� ����� �� �ִ�.
3. �ϳ��� �θ� Ŭ������ ���� ���� ���� Ŭ������ ���� �� �ִ�. 

*/

class Child : public Mother
{
private:
	double _d;

public:

	/*
	
	�������� ���� ������ �޸𸮰� �Ҵ�� �� 
	���� �ٷ� �ʱ�ȭ�ϱ� �����̴�. 
	�ڽ� Ŭ������ ������ �� �θ� Ŭ������ �������� �����Ƿ�
	�̴ϼȶ����� ����Ʈ���� �θ��� ����� ���� �Ұ��� 

	�ڽ� Ŭ������ ������ ���� �θ� Ŭ������ �����ڸ� �Բ� ȣ�� 
		
	*/

	// �ڽ�Ŭ���� ������1.
	//Child(const int &i_in, const double &d_in)
	//	//: _i(i_in), _d(d_in)	// ȣ����� ����.
	//{
	//	Mother::setValue(i_in);
	//	_d = d_in;
	//}

	// �ڽ�Ŭ���� ������2. 
	// �θ� Ŭ������ �����ڸ� ȣ���Ͽ� �θ��� ����� �ٷ� �ʱ�ȭ ���� 
	// �̴ϼȶ����� ����Ʈ�� ����� �� ����� ���� 
	Child(const int &i_in, const double &d_in)
		: Mother(i_in), _d(d_in) {}

	void setValue(const int &i_in, const double &d_in)
	{
		// _i = i_in;
		// �θ� Ŭ������:: �� ���� �θ� Ŭ������ ����� ���� ���� 

		Mother::setValue(i_in);
		_d = d_in;
	}

	void setValue(const double &d_in)
	{
		_d = d_in;
	}

	double getValue()
	{
		return _d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mother(1024);
	cout << mother.getValue() << endl; 

	Child child(128, 256);
	//child.setValue(128);
	//child.Mother::setValue(256);

	cout << child.Mother::getValue() << endl; 
	cout << child.getValue() << endl; 

	return 0; 
}