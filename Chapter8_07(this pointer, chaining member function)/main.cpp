#include<iostream>
using namespace std; 

/*

<this pointer>

this : ��ü �ڱ� �ڽ��� ����Ű�� ������ 

this �����ڸ� ���� �ڱ��ڽ��� ��� ������ ��� �Լ��� ��� ���� ���� 
��ü�� ���� �� �� �ν��Ͻ��� ����� ���, ����Լ��� �� ������ŭ �����ϴ� ���� �ƴ϶�
�ϳ��� �Լ��� ���� ��ü�鳢�� �����ϴ� �������� ����Ѵ�. 

���� ���ڸ� �̷� �������� �ϳ��� �Լ��� �ش� �ν��Ͻ��� �ּҿ� �Ķ���͸� ������ ����
������ ��������� �̷��� ����� ���� ����. �������� �۵������ �̿� ���ٴ� �̾߱�. 
ex. Simple::setID(&2, 4);

*/

class Simple
{
private:
	int _id;

public:
	Simple(int id)
	{
		//���� this�� ����Ű�� �ּ��� ��ü�� setID �Լ��� ����Ѵٴ� �ǹ� 
		//this->setID(id);
		//this�� ������ ��.  
		setID(id);
		(*this).setID(id);	// ���� �ǹ� 

		cout << this << endl; 
	}

	void setID(int id) { _id = id; }
	int getID() { return _id; }
};

class Calc
{
private:
	int _value;

public:
	Calc(int init_value) : _value(init_value) { }

	Calc& add(int value) { _value += value; return *this; }
	Calc& sub(int value) { _value -= value; return *this; }
	Calc& mult(int value) { _value *= value; return *this; }

	void print()
	{
		cout << _value << endl; 
	}
};

int main()
{
	Simple s1(1), s2(2);
	cout << &s1 << " " << &s2 << endl; 

	Calc cal(10);
	//cal.add(10);
	//cal.sub(2);
	//cal.mult(5);
	//cal.print();

	/*
	
	<Chaining Member Function>
	
	this �����͸� �̿��� Chaining Member Function�� ���� ����
	�ǿ뼺�� �־�� ���� ���ŷӰų� �ǹ������� �κ��� �ִ�.
	����� ���忡�� �򰥸� �� �ְ�, �������� ������ �� �ֱ� ����.
	�׷��� �̷��� ������� �۵��ϴ� ������ ��ʴ� �˾Ƶ� ��.
	
	*/

	cal.add(5).sub(5).mult(7).print();
	
	//�ӽ� ��ü�� �̿��ؼ��� ���� 
	Calc(20).add(10).print();

	return 0;
}