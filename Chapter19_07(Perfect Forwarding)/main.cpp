#include<iostream>
#include<vector>
#include<utility>
using namespace std; 

/*

<완벽한 전달(Perfect Forwarding)과 std::forward>

*/

struct MyStruct
{};

// L-value 래퍼런스를 파라미터로 받음. 
void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

// R-value 래퍼런스를 파라미터로 받음. 
void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

// 템플릿으로 설정 시, 매개변수로 넘길 때 L,R value 정보 값이 사라져서 
// 전부 L-value 래퍼런스로 보내게 됨. 
//template<typename T>
//void func_wrapper(T t)
//{
//	func(t);
//}

// <Perfect Forwarding>
// forward 함수 사용 시, 매개변수로 들어온 값(t)의 
// value에 맞는 형태(L,R-value)로 값을 리턴해줌. 
template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
}

class CustomVector
{
public:
	unsigned n_data = 0;
	int *ptr = nullptr; 

	CustomVector(const unsigned &_n_data, const int &_init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);
	}

	CustomVector(CustomVector &l_input)
	{
		cout << "Copy Constructor" << endl;

		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; i++)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector &&r_input)
	{
		cout << "Move Constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned &_n_data, const int &_init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];

		for (unsigned i = 0; i < n_data; i++)
			ptr[i] = _init;
	}

};

void doSomething(CustomVector &vec)
{
	cout << "Pass by L-reference" << endl;
	CustomVector new_vec(vec);
}

void doSomething(CustomVector &&vec)
{
	cout << "Pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec));
}

// 여기서도 템플릿 인스턴스 시, Perfect Forwarding으로 보내야 
// L,R value에 맞게 매개변수를 보낼 수 있다. 
template<typename T>
//void doSomethingTemplate(T vec)
void doSomethingTemplate(T &&vec)
{
	//doSomething(vec);
	doSomething(std::forward<T>(vec));
}

int main()
{
	// 예시 1. 

	/*
	MyStruct s;

	//func(s);			// L-value 래퍼런스로 보냄.
	//func(MyStruct());	// R-value 래퍼런스로 보냄. 

	func_wrapper(s);						
	func_wrapper(MyStruct());		
	*/


	//=================================================================//


	// 예시 2. 

	CustomVector my_vec(10, 1024);

	//CustomVector temp(my_vec);				// Copy Constructor(L-value)
	//CustomVector temp(std::move(my_vec));		// Move Constructor(R-value)

	//cout << my_vec.n_data << endl;

	//doSomething(my_vec);
	//doSomething(CustomVector(10, 8));

	doSomethingTemplate(my_vec);
	doSomethingTemplate(CustomVector(10, 8));

	my_vec;

	return 0;
}