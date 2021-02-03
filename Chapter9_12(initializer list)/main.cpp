#include<iostream>
#include<cassert>
#include<initializer_list>
using namespace std; 

/*

<멤버 이니셜라이저 리스트>

기본 자료형으로 배열을 만들 때 이니셜라이저 리스트를 
통해서 값을 편리하게 초기화할 수 있다. 

클래스와 같은 사용자 정의 자료형에서도, 
이니셜라이저 리스트를 통해 생성자나 대입 연산자를 편하게 만들 수 있다.  

*/

class IntArray
{
private:
	unsigned _length = 0;
	int *_data = nullptr;

public:
	IntArray(unsigned length) : _length(length)
	{
		_data = new int[length];
	}

	~IntArray()
	{
		delete[] this->_data;
	}

	IntArray(const std::initializer_list<int> &list)
		: IntArray(list.size())
	{
		int count = 0;

		for (auto &element : list)
		{
			_data[count] = element;
			count++;
		}

		// 이니셜라이저 리스트는 대괄호 오퍼레이터(인덱스 입력)를 
		// 제공하지 않으므로 아래 코드는 오류 발생 

		//for (unsigned count = 0; count < list.size(); count++)
		//{
		//	_data[count] = list[count];
		//}
	}

	// 이니셜라이저 리스트를 이용해서 생성자를 구현할 경우 
	// 대입 연산자 오버로딩도 함께 구현 해두면 좋다. 나중에 시간 날 때 구현 해볼 것. 

	// 출력 연산자 오버로딩 
	friend ostream &operator << (ostream &out, IntArray &arr)
	{
		for (unsigned i = 0; i < arr._length; i++)
		{
			out << arr._data[i] << " ";
		}

		out << endl; 
		return out;
	}
};


int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };	// 부등호 오른쪽에 있는 것이 이니셜라이저 리스트(초기자 리스트) 

	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	// 이니셜라이저 리스트로 형변환 
	auto il = { 10,20,30 };


	//------------------------------------------------------------------------------//


	//IntArray int_array{ 1,2,3,4,5 };
	IntArray int_array = { 1,2,3,4,5 };

	cout << int_array << endl; 

	return 0;
}