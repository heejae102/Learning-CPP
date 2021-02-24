#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std; 

/*

<람다 함수와 std::function>

람다 함수는 익명 함수로도 불린다. 

*/

void goodbye(const string &s)
{
	cout << "Goodbye" << s << endl;
}

class Object
{
public:
	void hello(const string &s)
	{
		cout << "Hello " << s << endl;
	}
};

int main()
{
	// lamda-introducer				: []
	// lamda-parameter-declaration
	// lamda-return-type-clause
	// compound-statement

	// 람다 함수를 함수 포인터처럼 사용 가능 
	// (파라미터) -> 리턴타입 {함수의 바디;};
	auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };
	func(123);

	// 진정한 람다 함수의 가치는 익명일 때 있다.
	// 함수의 구조가 잡다하게 구현할 것이 많을 경우 람다 함수를 사용하면 편리 
	// 특히 GUI 관련한 프로그래밍 시 빈번하게 사용. 
	[](const int &i) -> void { cout << "Hello, World!" << endl; }(12345);

	{
		string name = "JackJack";

		// introducer[] 내에 & 사용 시, 람다 함수가 구현된 블럭 내의 
		// 해당 블럭 내의 데이터를 & 으로 가져올 수 있다. 
		[&]() {std::cout << name << endl; } ();
		//[&name]() {std::cout << name << endl; } ();

		// [this]() : 클래스의 멤버 정의 
		// [=]()	: 데이터를 카피 
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// 1. 함수 포인터처럼 사용 
	auto func2 = [](int val) { cout << val << endl; };
	for_each(v.begin(), v.end(), func2);	// for_each는 알고리즘 헤더에 포함된 함수 

	// 2. 익명의 함수로 사용 
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []() -> int { return 1; }() << endl;

	//==============================================================================//

	std::function<void(int)> func3 = func2;
	func3(123);

	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	{
		// Place Holder 
		// 파라미터가 여러개일 때 유용하게 사용 

		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World"));

		// 바인드 시 굿바이 함수의 포인터를 넘겨주고, 파라미터 1개를 플레이스 홀더로 잡아 줌. 
		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("World"));
	}


	return 0;
}