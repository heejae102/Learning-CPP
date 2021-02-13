#pragma once
#include<iostream>

template <class T>
class Storage
{
private:
	T _value; 

public:
	Storage(T value)
	{
		_value = value;
	}

	~Storage() {}

	void print()
	{
		std::cout << _value << '\n';
	}
};

// templatized 된 클래스 내에서 print 함수를 사용할 때 
// double 타입으로 instantiation 될 경우 특수하게 처리 

/*

※ 주의할 점은 아래의 코드를 cpp 파일로 옮기게 되면, main에는 헤더 파일만 
include 되기 때문에 아래와 같은 특수한 인스턴스 상황에 대해서는 인지하지 못하므로
헤더 파일에 있는대로만 동작하게 된다. 

▼ 해결방법 

1. 템플릿의 특수화가 필요할 경우 헤더 파일 내에 모두 정의한다. 
2. 헤더 파일을 여러 개 두고 정리한다. 
3. 특수한 인스턴스화에 대해 정의된 cpp 파일을 main 에 include 한다. 

3번은 여러 오류를 동반할 수 있으므로 권장하지 않음. 보편적으로는 1번을 많이 사용.
프로젝트와 상황에 따라 적절한 방법을 택하여 사용할 것. 

*/

template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << _value << '\n';
}

