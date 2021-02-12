#include "MyArray.h"

template<typename T>
inline void MyArray<T>::print()
{
	for (int i = 0; i < _length; i++)
	{
		std::cout << _data[i] << " ";
	}

	std::cout << std::endl;
}

// explicit instantiation
// �ش� �ڵ带 �������� �� Ư���� ������ Ÿ������ 
// �������ؾ� �Ѵٴ� ���� ��������� �����ϴ� ��. 
// Ư���� �Լ��� ���ؼ� ����ϴ� �� �ܿ� Ŭ���� ��ü�� ����ϴ� �͵� ����. 

template class MyArray<char>;
template class MyArray<double>;

// print �Լ��� char, double Ÿ������ �ν��Ͻ�ȭ�� ���� ����ϴ� ��. 
//template void MyArray<char>::print();
//template void MyArray<double>::print();

