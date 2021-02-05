#include<iostream>
#include<cassert>
using namespace std; 

/*

<���� ������ �����ε�>

���� ���� vs ���� ����

���� ���� : �����͸� �״�� �����Ѵ�. ����Ʈ ���� �������� �۵����. 
           �� ������ �����ͻ� �ƴ϶� ���� ������ �����͵� �״�� �����ϱ� ������ 
		   ��� �޸𸮸� ����Ű�� ���� ���� �����ϸ� �ش� �޸𸮸� �Ȱ��� ����Ű�� ���� ���� ����ȴ�.

���� ���� : ���� ������ �����Ͱ� �ִ� ���, �ش� ���� ���� ����Ű�� �޸��� ������ŭ �޸𸮸� �Ҵ��Ͽ� 
           ���ο� �޸� ������ �ش� �޸𸮸� �����ϰ�, �޸� ���� �����͸� �״�� �����ϴ� ����. 
		   ��, ���� ������ ����Ű�� �����Ϳ� ������ �����͸� ���ο� �޸𸮷� �Ҵ��ϴ� ���. 

*/

class MyString
{
public:
	char *_data = nullptr;
	int _length = 0;

public:
	MyString(const char *source = "")
	{
		assert(source);

		// ���ڿ��� NULL ĳ���Ͱ� �� ������ ���� +1 
		_length = std::strlen(source) + 1;
		
		// �ش� ���� ����ŭ �����Ҵ� 
		_data = new char[_length];

		// �����Ҵ��� �޸𸮿� �������� char �� ���� 
		for (int i = 0; i < _length; i++)
		{
			_data[i] = source[i];
		}

		_data[_length - 1] = '\0';
	}

	// ���� ���� �����ڸ� ���� �� �ð��� ���µ�, ���� ����� 
	// ���ƾ� �ϴ� ��Ȳ�� ��� ���� �����ڰ� ȣ����� �ʵ��� �ƿ� ���ƹ����� ����� �ִ�.
	// ������, ��������� ��������ڸ� �� �����صε��� ����. 
	//MyString(const MyString &source) = delete;

	// ��������� (���� ����)
	MyString(const MyString &source)
	{
		cout << "Copy Constructor Called" << endl; 

		_length = source._length;

		// source ���� �����Ͱ� null �����Ͱ� �ƴ� ��� �޸𸮸� �Ҵ��Ͽ� ���� 
		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; i++)
				_data[i] = source._data[i];
		}
		else _data = nullptr;
	}

	MyString& operator = (const MyString &source)
	{
		cout << "Assignment Operator Called" << endl; 

		// �ڱ��ڽ��� �����ϴ� ��� ���� 
		if (this == &source) // prevent self-assignment
			return *this;

		// ���� �����ڰ� ȣ��� ��� ��ü�� ���� �����ϴ� ��Ȳ�̹Ƿ� ���������,
		// ���� ������ �Ͼ�� ��� �̹� �޸𸮸� ������ ���� ���ɼ��� �����Ƿ�,
		// �̹� ������ �ִ� �޸𸮴� delete �ϵ��� �Ѵ�. 
		delete[] _data;

		_length = source._length;

		// source ���� �����Ͱ� null �����Ͱ� �ƴ� ��� �޸𸮸� �Ҵ��Ͽ� ���� 
		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; i++)
				_data[i] = source._data[i];
		}
		else _data = nullptr;

		return *this;
	}

	~MyString()
	{
		delete[] _data;
	}

	char* getString() { return _data; }
	int getLength() { return _length; }
};

int main()
{
	MyString hello("Hello");

	// data�� �ּ� ��� 
	cout << (int*)hello._data << endl;
	cout << hello.getString() << endl;

	{	
		/*
		
		Copy Initialization �������� ���� ������ ȣ�� 
		(�ʱ�ȭ �� ���� Ÿ���� ��ü�� �����ϴ� ����, �Ϲ� ���� �ÿ��� ���� ����)
		
		���� �ش� ��ü�� ���� �����ڰ� ���� �����Ǿ� ���� �����Ƿ�,
		���� ������ ȣ�� �� ����Ʈ ���� �����ڰ� ȣ��ȴ�. 
		
		����Ʈ ���� �����ڴ� ���� ���� �����ϴ� ���Ҹ� �ϱ� ������, 
		��ü ���� ���� ���� ���� ���, �ش� �޸𸮰� ��°�� ����Ǵ� ���� �ƴ϶�,
		�ش� �޸𸮸� �����ϴ� ���� �״�� �����ϴ� �� ���̴�. 
		(��, ���� �޸𸮸� ������ �����Ϳ� ����� �����Ͱ� �Բ� �����ϴ� ���� �ȴ�.)

		����, ���� ��� �� ���� ��ü�� �����Ǵ� ���� ������ �ش� �޸𸮰� ����� ���, 
		�����ִ� �����ʹ� ������ �޸𸮸� ��� �����ϰ� �ǹǷ� ������ ���� ������ ������ �߻��Ѵ�.
		
		*/

		// ���� �����ڸ� ���� hello ��ü�� ������ ��, �������� ��� �޸𸮰� �����Ǿ����Ƿ�,
		// ������ �ۿ��� �ش� �޸𸮿� �����Ϸ��� �ϸ� �̹� ������ �޸𸮶� ������ �߻�. 
		MyString copy = hello;

		cout << (int*)copy._data << endl; 
		cout << copy.getString() << endl; 
	}

	cout << hello.getString() << endl;


	//----------------------------------------------------------------------------//


	// MyString str1(hello) �� ���� ����� ����.
	MyString str1 = hello;	// Copy Constructor ȣ�� 

	MyString str2;
	str2 = hello;			// Assignment Operator ȣ�� 

	return 0;
}