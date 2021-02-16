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

	// ���� ������ 
	// �Ű������� �ԷµǴ� �����͸� ��ü�� �����Ϳ� �Ѱ��ְ�, 
	// �Ű����� �����ʹ� nullptr�� �ٲ۴�. (�ٲ�ġ���Ͽ� �ּ��� �����ָ� �ϳ��� ��ü�� ����)
	AutoPtr(AutoPtr &a)
	{
		_ptr = a._ptr;
		a._ptr = nullptr;
	}

	// ���� ������ �����ε�
	// �Ű������� �ԷµǴ� �����͸� ��ü�� �����Ϳ� �Ѱ��ְ�, 
	// �Ű����� �����ʹ� nullptr�� �ٲ۴�. (�ٲ�ġ���Ͽ� �ּ��� �����ָ� �ϳ��� ��ü�� ����)
	AutoPtr& operator = (AutoPtr &a)
	{
		// ���� ��ü�� ���� �� �ǳʶٱ� 
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

