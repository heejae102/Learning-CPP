#include<iostream>
#include<cassert>
#include<initializer_list>
using namespace std; 

/*

<��� �̴ϼȶ����� ����Ʈ>

�⺻ �ڷ������� �迭�� ���� �� �̴ϼȶ����� ����Ʈ�� 
���ؼ� ���� ���ϰ� �ʱ�ȭ�� �� �ִ�. 

Ŭ������ ���� ����� ���� �ڷ���������, 
�̴ϼȶ����� ����Ʈ�� ���� �����ڳ� ���� �����ڸ� ���ϰ� ���� �� �ִ�.  

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

		// �̴ϼȶ����� ����Ʈ�� ���ȣ ���۷�����(�ε��� �Է�)�� 
		// �������� �����Ƿ� �Ʒ� �ڵ�� ���� �߻� 

		//for (unsigned count = 0; count < list.size(); count++)
		//{
		//	_data[count] = list[count];
		//}
	}

	// �̴ϼȶ����� ����Ʈ�� �̿��ؼ� �����ڸ� ������ ��� 
	// ���� ������ �����ε��� �Բ� ���� �صθ� ����. ���߿� �ð� �� �� ���� �غ� ��. 

	// ��� ������ �����ε� 
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
	int my_arr1[5] = { 1,2,3,4,5 };	// �ε�ȣ �����ʿ� �ִ� ���� �̴ϼȶ����� ����Ʈ(�ʱ��� ����Ʈ) 

	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	// �̴ϼȶ����� ����Ʈ�� ����ȯ 
	auto il = { 10,20,30 };


	//------------------------------------------------------------------------------//


	//IntArray int_array{ 1,2,3,4,5 };
	IntArray int_array = { 1,2,3,4,5 };

	cout << int_array << endl; 

	return 0;
}