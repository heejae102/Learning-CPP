#include<iostream>
using namespace std;

/*

<���� �Ҹ���>

*/

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *_array;

public:
	Derived(int length)
	{
		_array = new int[length];
	}

	~Derived() override
	{
		cout << "~Derived()" << endl;
		delete[] _array;
	}
};

int main()
{
	//Derived derived(5);

	/*

	<���⼺�� �̿��Ͽ� �ڽ� Ŭ������ �޸� ����>

	�ڽ� Ŭ������ �������� ��������� �𸣴� ��찡 ��κ��̱� ������
	���� Ŭ���� �����͸� ���� �ڽ� Ŭ������ �޸𸮸� �����ϴ� ��찡 ����.

	������ �̷��� �ڽ� Ŭ������ ����Ű�� �θ� �����͸� ���� �޸𸮸� ���� �� ���
	�ڽ� Ŭ������ �Ҹ��ڴ� ȣ����� �ʰ�, �θ� Ŭ������ �Ҹ��ڸ� ȣ��Ǵ� ���� �߻�.
	�ᱹ �ڽ� Ŭ�������� �Ҵ�� �޸𸮰� �������� �ʾƼ� �޸� ������ �߻��ϰ� �ȴ�.

	�̷��� ��� virtual Ű���带 ����ϸ� �ڽ� Ŭ������ �Ҹ��ڿ�
	�θ� Ŭ������ �Ҹ��ڰ� ��� ȣ��ǹǷ� ������ �ذ�ȴ�.
	(�ڽ� Ŭ���� �Ҹ��� ȣ�� -> �θ� Ŭ���� �Ҹ��� ȣ��)

	�� �θ� - �ڽ� Ŭ���� ���� �Ҹ��ڵ� override Ű���带 ����Ͽ�
	�������̵��� �� �ִµ�, ���� Ŭ������ virtual Ű���带 �ٿ��� ���� ����

	*/

	Derived *derived = new Derived(5);
	Base *base = derived;
	delete base;

	return 0;
}