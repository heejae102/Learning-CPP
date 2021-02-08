#include<iostream>
using namespace std; 

/*

<�Ҹ���> Destructor 

~Ŭ������ �������� �Ķ���Ϳ� ����Ÿ���� ���� Ư�� ����Լ� 

�Ҹ��ڴ� instance�� �޸𸮿��� ������ �� ���ο��� �ڵ����� ȣ��.
�����Ҵ����� ������� ��쿡�� ������ ����� �ڵ����� �޸𸮰� 
�������� �ʱ� ������ delete���� �޸𸮸� ������ �� �Ҹ��ڰ� ȣ��ȴ�. 

����� �ʱ�ȭ�� ���Ǵ� �����ڿ� �޸� �Ҹ��ڴ� ����� ����(delete)�� �ַ� ��� 


*/

class IntArray
{
private:
	int *_arr = nullptr;
	int _length = 0; 

public:
	IntArray(const int &length_in)
	{
		_length = length_in;
		_arr = new int[_length];

		cout << "Constructor" << endl; 
	}

	~IntArray()
	{
		//nullptr�� delete�Ϸ��� �ص� ������ ����⶧���� ����ó�� 
		if(_arr != nullptr) delete[] _arr;
	}

	int size() { return _length; }
};

class Simple
{
private:
	int _id;

public:
	Simple(const int &id_in) : _id(id_in) 
	{
		cout << "Constructor " << _id << endl; 
	}

	~Simple()
	{
		cout << "Destructor " << _id << endl; 
	}
};

int main()
{
	//�Ϲ� ���� ���� ��, ���� ����� ������ �����ڰ� ���� ȣ�� 
	// ���߿� ����� ������ �Ҹ��ڰ� ���� ȣ��(�������� �׾Ƽ� LIFO���� �޸𸮸� ����) 
	//Simple s1(0);

	//Simple *s1 = new Simple(0);
	//Simple s2(1);
	//delete s1; 

	while (true)
	{
		IntArray my_arr(1000);
	}

	return 0;
}