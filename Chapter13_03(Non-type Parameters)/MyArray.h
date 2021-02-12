#pragma once
#include<iostream>
#include<assert.h>

/*

��, �̷��� ���ø����� �ڷ����� �ƴ� �Ű������� ���� ���, 
�Լ��� �ٵ� cpp ���Ͽ� ���� �ű� ��, ������ �Ű����� ���� ���� 
��� ������� �ν��Ͻ� ������ �� �־���ϹǷ� ���� ��ٷο� ���� �ƴ�. 

(plate void MyArray<char, 0>::print();
 plate void MyArray<char, 1>::print();
 plate void MyArray<char, 2>::print(); . . .)

���� �̷��� ���� �Լ��� ��� ���� ���� ��� ����ִ� ���� ����. 

*/
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	int _length;
	T* _data;
	// _data[T_SIZE];	����� �ʹ� Ŀ�� ��� �����Ҵ��ϴ� ���� ���� �� ����.

public:
	MyArray()
	{
		_data = new T[T_SIZE];
	}

	MyArray()
	{
		delete[] _data;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return _data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
		{
			std::cout << _data[i] << " ";
		}

		std::cout << std::endl;
	}
};

