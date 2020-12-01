#include<iostream>
using namespace std; 

//함수에서 auto 타입 사용 시 해당 auto에 들어갈 타입을 남기는 트레일링 기법도 있음.
//의미가 있겠냐 싶겠지만 줄맞춤 정리할 때 좋고 직관적일 수도 있음. 

auto add(int x, int y)
{
	return x + y;
}

auto add(int x) -> int
{
	return x;
}

auto add(double x, double y) -> double
{
	return x + y;
}

int main()
{
	/*
	
	auto 키워드와 자료형 추론 
	
	어떤 변수가 어떠한 자료형이어야하는지 매번 수동으로 결정한다면 효율이 떨어진다. 
	auto 키워드를 사용하면 입력되는 값에 따라 자동적으로 자료형이 결정된다. 
	
	함수의 리턴 값도 auto 사용 가능 

	단점은 개발자가 정확한 자료형을 확인할 수 없다는 점. 

	*/

	//123은 정수이므로 a는 int 타입이 될 것이 자명. 
	//auto 키워드를 사용하면 알아서 자료형을 추론해서 집어넣음. 

	//int a = 123; 
	auto a = 123;
	auto b = 123.0;
	auto c = 1 + 2;
	auto d = 1 + 2.0;

	//함수의 리턴 값도 auto를 사용해서 추론 가능 
	//함수의 파라미터에는 사용할 수 없음. 대신 템플릿으로 대체 가능
	auto result = add(3, 7);

	return 0; 
}