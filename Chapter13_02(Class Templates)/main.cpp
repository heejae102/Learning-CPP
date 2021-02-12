#include<iostream>
#include "MyArray.h"
using namespace std; 

/*

<클래스 템플릿> Class Templates

*/

int main()
{
	// 클래스 내에서 멤버로 템플릿을 사용했기 때문에, 클래스 선언 시 
	// 해당 템플릿에 들어갈 자료형 타입을 설정 해주어야 오류 발생 X 
	// MyArray my_array(10);

	MyArray<char> my_array(10);

	for (int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i + 65;
	}

	my_array.print();

	return 0;
}