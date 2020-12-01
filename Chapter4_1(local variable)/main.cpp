#include<iostream>

//굳이 같은 변수 혹은 함수명을 사용하고 싶다면 네임스페이스로 구분 
//네임스페이스는 중첩도 가능 

namespace work1
{
	namespace work11
	{
		int a = 1;

		void doSomething()
		{
			a += 3;
		}
	}
}

namespace work2
{
	int a = 1;

	void doSomething()
	{
		a += 5;
	}
}

int main()
{
	using namespace std;

	/*
	
	지역 변수(local variable)의 범위(scope)와 지속기간(duration)
	
	:: 영역 결정 연산자(scope resolution operator)  

	*/

	int apple = 5;

	cout << apple << endl; 

	if(true)
	{
		//지역 변수와 전역 변수는 이름이 같아도 서로 다른 것으로 인식
		//해당 스코프 내에서는 지역 변수만 인식 
		//스코프를 벗어나면 지역 변수는 사라지고 전역 변수만 인식 
		//하지만 헷갈리지 않도록 가급적 다른 변수명을 사용하는 것이 좋다. 

		int apple = 1;
		cout << apple << endl; 
	}

	cout << apple << endl; 

	cout << work1::work11::a << endl; 
	cout << work2::a << endl; 

	return 0; 
}