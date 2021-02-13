#include<iostream>
using namespace std;

/*

<���ø��� �κ������� Ư��ȭ�ϱ�>

*/

template <class T, int size>
class StaticArray_BASE
{
private:
	T _array[size];

public:
	T *getArray() { return _array; }

	T& operator[](int index)
	{
		return _array[index];
	}

	// ��� �Լ� Ư��ȭ 
	void print()
	{
		for (int count = 0; count < size; count++)
		{
			std::cout << (*this)[count] << ' ';
		}

		std::cout << endl; 
	}
};

// �Լ��� ������ ���̽� �Լ��� ��ӹ޵��� �ϰ�, 
// Ư��ȭ�ؾ��ϴ� �ڷ����� ���� ����� �޴� ������ ����� 
template <class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{

};

template <int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	// Ư��ȭ�ؾ� �ϴ� �Լ��� �������̵� 
	void print()
	{
		for (int count = 0; count < size; count++)
		{
			std::cout << (*this)[count];
		}

		std::cout << endl;
	}
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count = 0; count < size; count++)
	{
		std::cout << array[count] << ' ';
	}

	std::cout << endl; 
}

// �Ϲ� �Լ� Ư��ȭ 
// ��� StaticArray Ŭ������ ���� �Ϲ����� ������ �ϴ� print �Լ���
// char �ڷ����� ���ؼ��� Ư���ϰ� �����ϵ��� Ư��ȭ 
template <int size>
void print(StaticArray<char, size> &array)
{
	for (int count = 0; count < size; count++)
	{
		std::cout << array[count];
	}

	std::cout << endl; 
}

int main()
{
	StaticArray<int, 4> int4;

	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	print(int4);
	int4.print();

	//=======================================================================//

	StaticArray<char, 14> char14;

	char14[0] = 'H';
	char14[1] = 'e';

	// ...

	strcpy_s(char14.getArray(), 14, "Hello, World");
	print(char14);
	char14.print();

	return 0;
}