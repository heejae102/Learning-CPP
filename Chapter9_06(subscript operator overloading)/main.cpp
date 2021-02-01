#include<iostream>
#include<cassert>
using namespace std; 

/*

<첨자 연산자 오버로딩>

*/

class IntList
{
private:
	int _list[10];

public:
	void setItem(int index, int value)
	{
		_list[index] = value;
	}

	int getItem(int index)
	{
		return _list[index];
	}

	int* getList()
	{
		return _list;
	}

	// 첨자 연산자 오버로딩 
	int& operator [] (const int index)
	{
		// 배열의 원소에 접근하는 인덱스의 범위를 지정해주어야 범위초과 오류가 발생하지 않음.
		// 첨자 연산자 오버로딩은 빈번히 사용하는 함수이므로 if문보다는 assert를 사용하는 것이 퍼포먼스에 유리 
		assert(index >= 0);
		assert(index < 10);

		// 리턴 값을 읽거나 바꾸는 것 모두 가능하게 하기 위해 래퍼런스 값 리턴 
		// 리턴 값이 항상 주소를 가지는 L value여야 하므로 래퍼런스로 리턴
		return _list[index];
	}

	// 클래스를 const형으로 선언하여 사용하는 경우 값을 불러오는 것을
	// 가능하게 하기 위해 const형 함수를 오버로딩 
	const int& operator [] (const int index) const
	{
		// 배열의 원소에 접근하는 인덱스의 범위를 지정해주어야 범위초과 오류가 발생하지 않음.
		// 첨자 연산자 오버로딩은 빈번히 사용하는 함수이므로 if문보다는 assert를 사용하는 것이 퍼포먼스에 유리 
		assert(index >= 0);
		assert(index < 10);

		// 함수 내에서 멤버를 수정하지 않는 const형 함수를 선언했으므로, 리턴형도 const형으로 선언
		// 값을 불러오는 것은 가능하지만 불러온 값을 수정하는 것은 불가능 
		return _list[index];
	}
};

int main()
{
	//IntList my_list;

	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl; 

	//my_list.getList()[3] = 10;
	//cout << my_list.getList()[3] << endl;

	//--------------------------------------------------------------//

	IntList my_list;

	my_list[3] = 10;
	cout << my_list[3] << endl; 

	// 리스트를 포인터형으로 사용하는 경우, 첨자 연산자를 오버로딩하여 사용할 때 연산자를 바로 사용하면 X
	// 먼저 디래퍼런싱을 한 다음에 연산자를 호출해야 함. 
	IntList *list = new IntList;

	// 아래 문장은 list의 배열이 되므로 문법적으로 의도가 다르다고 할 수 있다. 
	
	//list[3] = *list;	// 의도가 다름.	 
	//list[3] = 10;		// Wrong
	(*list)[3] = 10;	// OK

	return 0;
}