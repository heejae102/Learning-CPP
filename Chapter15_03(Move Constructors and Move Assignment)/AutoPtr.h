#pragma once
#include<iostream>

template<class T>
class AutoPtr
{
private:
	T* _ptr;

public:
	AutoPtr(T* ptr = nullptr) : _ptr(ptr)
	{
		std::cout << "AutoPtr default constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;
	
		if (_ptr != nullptr) delete _ptr;
	}

	AutoPtr(const AutoPtr &a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		// deep copy
		_ptr = new T;

		// = 연산자 오버로딩을 구현했으므로, 오버로딩된 함수가 실행된다. 
		*_ptr = *a._ptr;
	}

	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment" << std::endl;

		if (&a == this) return *this;	// prevent self-assignment

		if (_ptr != nullptr) delete _ptr;

		// deep copy
		_ptr = new T;
		*_ptr = *a._ptr;

		return *this;
	}

	//AutoPtrr(AutoPtr&& a) : _ptr(a._ptr)
	//{
	//	a._ptr = nullptr;	// really necessary?

	//	std::cout << "AutoPtr move constructor" << std::endl;
	//}

	//AutoPtr& operator = (AutoPtr&& a)
	//{
	//	std::cout << "AutoPtr move assignment" << std::endl;
	//
	//	if (&a == this) return *this;	// prevent self-assignment

	//	if (!_ptr) delete _ptr;

	//	// shallow copy
	//	_ptr = a._ptr;
	//	a._ptr = nullptr;

	//	return *this;
	//}
};

