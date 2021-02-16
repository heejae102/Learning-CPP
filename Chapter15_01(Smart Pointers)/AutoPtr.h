#pragma once
#include<iostream>

template<class T>
class AutoPtr
{
public:
	T *_ptr = nullptr;

public:
	AutoPtr(T *ptr = nullptr)
		: _ptr(ptr) {}

	~AutoPtr()
	{
		if (_ptr != nullptr) delete _ptr;
	}

	// 복사 생성자 
	// 매개변수로 입력되는 포인터를 객체의 포인터에 넘겨주고, 
	// 매개변수 포인터는 nullptr로 바꾼다. (바꿔치기하여 주소의 소유주를 하나의 객체로 유지)
	AutoPtr(AutoPtr &a)
	{
		_ptr = a._ptr;
		a._ptr = nullptr;
	}

	// 대입 연산자 오버로딩
	// 매개변수로 입력되는 포인터를 객체의 포인터에 넘겨주고, 
	// 매개변수 포인터는 nullptr로 바꾼다. (바꿔치기하여 주소의 소유주를 하나의 객체로 유지)
	AutoPtr& operator = (AutoPtr &a)
	{
		// 같은 객체에 대입 시 건너뛰기 
		if (&a == this)
			return *this;

		delete _ptr; 
		_ptr = a._ptr;
		a._ptr = nullptr;
		return *this;
	}

	T& operator*() const { return *_ptr; }
	T* operator->() const { return _ptr; }
	bool isNull() const { return _ptr == nullptr; }
};

