#include<iostream>
#include"Cents.h"
using namespace std; 

/*

<함수 템플릿> Function Templates

템플릿은 여러 가지 자료형에 대해 비슷한 코드의 반복작성을 방지해 줌. 

템플릿에 클래스 자료형도 대응이 가능한데, 단 클래스를 사용할 경우
해당 클래스를 사용하기 위해 필요한 함수 및 기능들을 따로 구현해주어야 함. 

템플릿의 인스턴스화 (Template Instantiation) 
컴파일러가 함수(클래스) 템플릿으로부터 실제 C++ 함수(클래스)를 만드는 과정

즉, 모든 타입에 대응가능한 Generalized 된 템플릿이 
특정 타입에 대응되어 작동하는 과정을 '템플릿의 인스턴스화'라고 부른다.  

*/

// 같은 코드를 여러 타입으로 적용시키기 위해 
// 불필요하게 반복적인 코드를 작성해야 한다. 
// 반면 템플릿을 사용하면 하나의 코드만으로 모든 타입에 대응 가능 

//int getMax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//double getMax(double x, double y)
//{
//	return (x > y) ? x : y;
//}

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	// 템플릿으로 작성된 하나의 함수 만으로 모든 타입에 대응 가능 

	std::cout << getMax(1, 2) << std::endl;
	std::cout << getMax(3.14, 1.592) << std::endl;
	std::cout << getMax(1.2f, 3.4f) << std::endl;
	std::cout << getMax('a', 'c') << std::endl;

	std::cout << getMax(Cents(5), Cents(10)) << std::endl;

	return 0;
}