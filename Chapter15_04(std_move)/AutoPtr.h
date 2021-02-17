#pragma once
#include<iostream>

template<class T>
class AutoPtr
{
private:

public:
	T* _ptr;

public:
	AutoPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{
		std::cout << "AutoPtr default constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;
	
		if (_ptr != nullptr) delete _ptr;
	}

	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		// deep copy
		_ptr = new T;
		*_ptr = *a._ptr;
	}

	AutoPtr& operator = (const AutoPtr&  a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		if (&a == this) return *this;

		if (_ptr != null) delete _ptr;

		// deep copy 
		_ptr = new T;
		*_ptr = *a._ptr;

		return *this;
	}

	AutoPtr(AutoPtr&& a)
		: _ptr(a._ptr)
	{
		a._ptr = nullptr;

		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator = (AutoPtr&& a)
	{
		std::cout << "AutoPtr move assignment" << std::endl;

		if (&a == this) return *this;

		if (!_ptr) delete _ptr;

		// shallow copy
		_ptr = a._ptr;
		a._ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *_ptr; }

};

