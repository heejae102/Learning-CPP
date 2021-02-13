#include<iostream>
using namespace std;

/*

<템플릿을 부분적으로 특수화하기>

*/

template <class T, int size>
class StaticArray_BASE
{
private:
	T _array[size];

public:
	T *getArray() { return _array; }

	T& operator[](int index)
	{
		return _array[index];
	}

	// 멤버 함수 특수화 
	void print()
	{
		for (int count = 0; count < size; count++)
		{
			std::cout << (*this)[count] << ' ';
		}

		std::cout << endl; 
	}
};

// 함수를 나눠서 베이스 함수를 상속받도록 하고, 
// 특수화해야하는 자료형은 따로 상속을 받는 구조로 만들기 
template <class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{

};

template <int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	// 특수화해야 하는 함수를 오버라이딩 
	void print()
	{
		for (int count = 0; count < size; count++)
		{
			std::cout << (*this)[count];
		}

		std::cout << endl;
	}
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
	for (int count = 0; count < size; count++)
	{
		std::cout << array[count] << ' ';
	}

	std::cout << endl; 
}

// 일반 함수 특수화 
// 모든 StaticArray 클래스에 대해 일반적인 동작을 하던 print 함수를
// char 자료형에 대해서만 특수하게 동작하도록 특수화 
template <int size>
void print(StaticArray<char, size> &array)
{
	for (int count = 0; count < size; count++)
	{
		std::cout << array[count];
	}

	std::cout << endl; 
}

int main()
{
	StaticArray<int, 4> int4;

	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	print(int4);
	int4.print();

	//=======================================================================//

	StaticArray<char, 14> char14;

	char14[0] = 'H';
	char14[1] = 'e';

	// ...

	strcpy_s(char14.getArray(), 14, "Hello, World");
	print(char14);
	char14.print();

	return 0;
}