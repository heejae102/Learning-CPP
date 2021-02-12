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
	
	함수의 정의 부분을 cpp에 따로 빼놓은 함수. 
	클래스의 멤버를 템플릿으로 선언한 클래스의 경우, 함수의 정의를 
	cpp파일 에 따로 할 경우 해당 함수 및 클래스가 템플릿을 사용한다는 것을
	명시적으로 따로 선언해주어야 오류가 발생하지 X 

	(main 파일에서는 헤더 파일만 include 하는데, 헤더 파일 내에서는
	해당 함수가 템플릿을 사용하고 있는지 확인이 되지 않기 때문)

	*/
	void print();
};


