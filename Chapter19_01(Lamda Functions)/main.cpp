#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std; 

/*

<���� �Լ��� std::function>

���� �Լ��� �͸� �Լ��ε� �Ҹ���. 

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

	// ���� �Լ��� �Լ� ������ó�� ��� ���� 
	// (�Ķ����) -> ����Ÿ�� {�Լ��� �ٵ�;};
	auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };
	func(123);

	// ������ ���� �Լ��� ��ġ�� �͸��� �� �ִ�.
	// �Լ��� ������ ����ϰ� ������ ���� ���� ��� ���� �Լ��� ����ϸ� �� 
	// Ư�� GUI ������ ���α׷��� �� ����ϰ� ���. 
	[](const int &i) -> void { cout << "Hello, World!" << endl; }(12345);

	{
		string name = "JackJack";

		// introducer[] ���� & ��� ��, ���� �Լ��� ������ �� ���� 
		// �ش� �� ���� �����͸� & ���� ������ �� �ִ�. 
		[&]() {std::cout << name << endl; } ();
		//[&name]() {std::cout << name << endl; } ();

		// [this]() : Ŭ������ ��� ���� 
		// [=]()	: �����͸� ī�� 
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// 1. �Լ� ������ó�� ��� 
	auto func2 = [](int val) { cout << val << endl; };
	for_each(v.begin(), v.end(), func2);	// for_each�� �˰��� ����� ���Ե� �Լ� 

	// 2. �͸��� �Լ��� ��� 
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []() -> int { return 1; }() << endl;

	//==============================================================================//

	std::function<void(int)> func3 = func2;
	func3(123);

	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	{
		// Place Holder 
		// �Ķ���Ͱ� �������� �� �����ϰ� ��� 

		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World"));

		// ���ε� �� �¹��� �Լ��� �����͸� �Ѱ��ְ�, �Ķ���� 1���� �÷��̽� Ȧ���� ��� ��. 
		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("World"));
	}


	return 0;
}