#pragma once
#include<iostream>
#include<assert.h>	// for assert()

template<typename T>
class MyArray
{
private:
	int _length;
	T* _data;

public:
	MyArray()
	{
		_length = 0;
		_data = nullptr;
	}

	MyArray(int length)
	{
		_data = new T[length];
		_length = length;
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] _data;
		_data = nullptr;
		_length = 0;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < _length);
		return _data[index];
	}

	int getLength()
	{
		return _length;
	}

	/*
	
	�Լ��� ���� �κ��� cpp�� ���� ������ �Լ�. 
	Ŭ������ ����� ���ø����� ������ Ŭ������ ���, �Լ��� ���Ǹ� 
	cpp���� �� ���� �� ��� �ش� �Լ� �� Ŭ������ ���ø��� ����Ѵٴ� ����
	��������� ���� �������־�� ������ �߻����� X 

	(main ���Ͽ����� ��� ���ϸ� include �ϴµ�, ��� ���� ��������
	�ش� �Լ��� ���ø��� ����ϰ� �ִ��� Ȯ���� ���� �ʱ� ����)

	*/
	void print();
};


