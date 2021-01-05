#include<iostream>
using namespace std;

/*

<���� ��� ����>

*/

class Something
{
public:
	// static ��� ������ �ʱ�ȭ �Ұ��� 
	//static int _value = 1;
	static int _value;

	// static const ��� ������ �ʱ�ȭ�� �����ϳ� �� ������ �Ұ���
	static const int c_value = 5;
	
	// static const expression ��� ������ ������ Ÿ�ӿ� ���� �����Ǿ�� �Ѵ�. (�Ϲ��� ��Ÿ�ӿ��� ����)
	static constexpr int s_value = 1; 

};

// define in cpp (���Ǵ� �� ������ �־�� �ϹǷ� cpp ���Ͽ� �����ؾ� �Ѵ�. ��� ���Ͽ� �� ��� ���� �߻�)
int Something::_value = 1;

int generateID()
{
	// static���� �����Ͽ� �Լ��� ������ ������� �ʰ� ����
	static int s_id = 0;
	return ++s_id;
}

int main()
{
	cout << generateID() << endl; 
	cout << generateID() << endl;
	cout << generateID() << endl;

	// static�� �������� �����ϱ� ������ �ν��Ͻ�ȭ���� �ʾƵ� �̹� �޸𸮿� �Ҵ�Ǿ��־� ��� ����
	cout << &Something::_value << " " << Something::_value << endl; 

	Something st1;
	Something st2; 

	st1._value = 2; 

	cout << &st1._value << " " << st1._value << endl; 
	cout << &st2._value << " " << st2._value << endl; 

	// �ν��Ͻ��� ������ �ʰ� �� ���� ���� 
	Something::_value = 1024;
	cout << &Something::_value << " " << Something::_value << endl;

	return 0; 
}