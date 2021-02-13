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

// 자료형이 bool일 경우, bool을 배열로 만들지 않고, 
// char(8비트)로 8개의 데이터 표현  
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

