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
// 해당 코드를 컴파일할 때 특정한 데이터 타입으로 
// 컴파일해야 한다는 것을 명시적으로 선언하는 것. 
// 특정한 함수에 대해서 명시하는 것 외에 클래스 자체를 명시하는 것도 가능. 

template class MyArray<char>;
template class MyArray<double>;

// print 함수를 char, double 타입으로 인스턴스화할 것을 명시하는 것. 
//template void MyArray<char>::print();
//template void MyArray<double>::print();

