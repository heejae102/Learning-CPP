#include<iostream>

namespace a
{
	int my_var(10);
	int count(123);
}

namespace b
{
	int my_var(20);
}

int main()
{
	using namespace std; 

	// std라는 namespace 내 특정한 몇 가지만 사용할 경우 namespace 전체를 using 선언하지 않고,
	// std 내 특정한 키워드만 따로 using으로 선언하여 사용할 수 있다. 

	//using std::cout;
	//using std::cin;
	//using std::endl;

	//using namespace a;
	//using namespace b; 

	//namespace a와 b 모두 my_var 변수가 있으므로 어떤 공간의 
	//변수를 사용해야 할 지 몰라서 ambiguity 오류가 발생 
	//cout << my_var << endl; 

	//1.변수명 앞에 사용 할 네임 스페이스 공간 명을 적어서 구분 가능 
	cout << a::my_var << endl; 

	//2. 스코프로 영역을 나눠서 구분 가능 
	{
		using namespace a;
		cout << my_var << endl; 
		
		//std 공간 안에 count 라는 변수를 사용해서 오류 발생 
		//cout << count << endl; 
		cout << a::count << endl; 
	}

	{
		using namespace b;
		cout << my_var << endl; 
	}

	//using namespace를 특정 헤더에서 전역 범위로 넣을 경우  
	//해당 헤더를 include하는 모든 cpp파일에 영향을 주어 오류가 발생할 수 있음.
	//따라서 헤더에서 전역으로 사용하는 것은 주의할 것. 
	//가급적 헤더파일보다는 cpp파일에 집어넣는 것이 좋다. 

	return 0;
}