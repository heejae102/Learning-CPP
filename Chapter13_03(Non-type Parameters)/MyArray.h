#pragma once
#include<iostream>
#include<assert.h>

/*

단, 이렇게 템플릿으로 자료형이 아닌 매개변수가 들어올 경우, 
함수의 바디를 cpp 파일에 따로 옮길 때, 가능한 매개변수 값에 대해 
모두 명시적인 인스턴스 선언을 해 주어야하므로 여간 까다로운 것이 아님. 

(plate void MyArray<char, 0>::print();
 plate void MyArray<char, 1>::print();
 plate void MyArray<char, 2>::print(); . . .)

따라서 이러한 경우는 함수를 헤더 파일 내에 모두 집어넣는 것이 낫다. 

*/
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	int _length;
	T* _data;
	// _data[T_SIZE];	사이즈가 너무 커질 경우 동적할당하는 편이 나을 수 있음.

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

