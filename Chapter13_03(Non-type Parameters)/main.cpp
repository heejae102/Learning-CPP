#include<iostream>
using namespace std; 

/*

<자료형이 아닌 템플릿 매개변수>

*/

int main()
{
	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
	// 위의 경우에 100은 반드시 컴파일 타임에 결정될 필요는 없지만, 
	// 아래와 같이 템플릿에 매개변수로 들어가는 값의 경우 
	// 컴파일 타임에 반드시 결정되어야 함. 

	MyArray<double, 100> my_array;	// std::array<double, 100>

	for (int i = 0; i < my_array.getLength(); i++)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}