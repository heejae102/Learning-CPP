#pragma once

template <class T>
class Storage8
{
private:
	T _array[8];

public:
	void set(int index, const T &value)
	{
		_array[index] = value;
	}

	const T& get(int index)
	{
		return _array[index];
	}
};

// �ڷ����� bool�� ���, bool�� �迭�� ������ �ʰ�, 
// char(8��Ʈ)�� 8���� ������ ǥ��  
template<>
class Storage8<bool>
{
private:
	unsigned char _data;

public:
	Storage8() : _data(0) {}

	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value) _data |= mask;
		else _data &= ~mask;
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		return (_data & mask) != 0; 
	}
};

