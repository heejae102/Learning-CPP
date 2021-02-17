#pragma once
#include<iostream>

class Resource
{
private:

public:
	int *_data = nullptr;
	unsigned _length = 0;

public:
	Resource()
	{
		std::cout << "Resource default constructed" << std::endl; 
	}

	Resource(unsigned length)
	{
		std::cout << "Resource length constructed" << std::endl; 

		this->_data = new int[length];
		this->_length = length;
	}

	Resource(const Resource &res)
	{
		std::cout << "Resource copy constructed" << std::endl; 

		Resource(res._length);

		for (unsigned i = 0; i < _length; i++)
		{
			_data[i] = res._data[i];
		}
	}

	~Resource() 
	{
		std::cout << "Resource destroyed" << std::endl;
	
		if (_data != nullptr) delete[] _data;
	}

	Resource &operator = (Resource &res)
	{
		std::cout << "Resource copy assignment" << std::endl;

		if (&res == this) return *this;

		if (this->_data != nullptr) delete[] _data;

		_length = res._length;
		_data = new int[_length];

		for (unsigned i = 0; i < _length; i++)
		{
			_data[i] = res._data[i];
		}

		return *this;
	}

	void print()
	{
		for (unsigned i = 0; i < _length; i++)
		{
			std::cout << _data[i] << " ";
		}

		std::cout << std::endl; 
	}
};

