#include<iostream>
#include<vector>
#include<algorithm>	// std::min
using namespace std; 

/*

<자료형 추론(Type Inference) auto와 decltype>

*/

class Examples
{
public:

	void ex1()
	{
		std::vector<int> vect;

		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); itr++)
		{
			cout << *itr;
		}

		// auto를 통해 iterator를 일일이 선언하지 않고 편리하게 사용가능 
		for (auto itr = vect.begin(); itr != vect.end(); itr++)
		{
			cout << *itr;
		}

		// auto를 통한 축약형 
		for (auto itr : vect)	// for(const auto &itr : vect)
		{
			cout << itr;
		}
	}

	void ex2()
	{
		// auto는 기본적인 데이터 형식을 제외한 자잘한 수식어는 모두 생략하므로
		// 특정한 특성을 부여하고 싶을 경우 auto를 선언하면서 수식.

		int x = int();

		auto auto_x = x;
		const int &crx = x;

		// auto는 추론 시 const, &(래퍼런스)를 생략하므로 int 타입으로 추론 
		auto auto_crx1 = crx;

		// auto형으로 const, &(래퍼런스) 형식으로 사용하고 싶을 경우 아래와 같이 선언
		const auto& auto_crx2 = crx;

		// volatile 형식은 값이 자주 변화하기 때문에 최적화 시 빼달라는 의미
		// 주로 멀티스레딩을 구현할 때 사용 
		volatile int vx = 1024;

		// auto 형식으로 받을 때 volatile도 생략 
		auto avx = vx;

		// auto에 volatile 특성을 추가하고 싶을 경우 아래와 같이 선언 
		volatile auto vavx = vx;
	}

	// 템플릿으로 데이터를 받을 때, 
	// auto와 마찬가지로 수식은 다 생략되고 디폴트 타입만 받음.
	//template<class T>
	//void func_ex3(T arg) {}

	// 데이터의 수식을 모두 받아서 데이터 형식을 추론해야 할 경우, 
	// 아래와 같이 T로 받는 부분에 필요한 수식을 붙여서 선언. 
	template<class T>
	void func_ex3(const T& arg) {}

	void ex3()
	{
		const int &crx = 123;

		func_ex3(crx);
	}

	void ex4()
	{
		const int c = 0;
		
		// 원래 auto 형식으로 데이터를 받을 때, 수식어(const 등)가 생략되지만, 
		// 래퍼런스로 auto를 선언할 때 해당 데이터가 const형식인 경우 
		// 자동으로 const & 형식으로 데이터를 받게 된다. 
		auto &rc = c;

		// const 형식이므로 데이터 값 변경 불가능 (error) 
		//rc = 123;		
	}

	void ex5()	// amendment
	{
		int i = 42;

		// &&(더블 앰퍼샌드)는 r-value 래퍼런스로 선언하고 싶다는 의도 

		// 하지만 오른쪽에 대입되는 존재가 l-value이므로 l-value 형식으로 받음. 
		auto&& ri_1 = i;	// l-value

		// 오른쪽에 대입되는 존재가 pure r-value이므로 r-value 형식으로 받음. 
		auto&& ri_2 = 42;	// r-value
	}

	void ex6()
	{
		int x = 42;
		const int *p1 = &x;
		auto p2 = p1;

		//*p2 = 43;	// error
	}

	// lhs, rhs 를 곱해주는 함수인데, 두 변수가 자료형이 달라서(ex. int, float)
	// 결과값의 자료형이 무엇이 될지 예측할 수가 없다. 
	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		// 결과 값의 형식이 무엇이 될지 모르므로 auto 형식으로 추론 
		auto prod1 = lhs * rhs;

		// C++11 이전의 일부 컴파일러에서 해결하던 방식. 결과값의 type을 리턴 
		//typedef typeof(lhs*rhs) product_type;		// pre-C++11 'some' compilers 
		
		// 모던 C++에서 사용하는 방식 (declared type)
		// lhs * rhs 를 실제로 연산하는 것은 아니고, 결과 타입만 추론 
		typedef decltype(lhs*rhs) product_type;
		product_type prod2 = lhs * rhs;

		// 아래와 같이 위의 2문장을 1문장으로 줄여서 사용 가능 
		decltype(lhs*rhs) prod3 = lhs * rhs;
	}

	// return type으로 declared type을 사용하는 것도 가능 
	template<typename T, typename S>
	// 단, 아래와과 같이 사용은 불가능 (컴파일러가 읽는 순서상 오류 발생)
	//decltype(lhs * rhs) func_ex8(T lhs, S rhs)	
	auto func_ex8(T lhs, S rhs) -> decltype(lhs * rhs)
	{
		return lhs * rhs;
	}

	void ex7_8()
	{
		func_ex7(1.0, 345);
		func_ex8(1.2, 345);
	}

	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;

		// 구초제의 포인터 
		const S *p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		
		// 포인터는 제대로 추론 
		auto d = p;

		// p는 const이지만, m_x는 const가 아니므로 e는 일반 int형
		auto e = p->m_x;

		// decltype은 auto의 용법과 다르게 'declared'라는 말그대로 
		// 데이터가 선언된 형식 그대로 생략 없이 가져옴. 

		typedef decltype(x)			x_type;
		typedef decltype(cx)		cx_type;
		typedef decltype(crx)		crx_type;
		typedef decltype(p->m_x)	m_x_type;	// 'declared' type. 

		// 괄호가 더 붙으면 래퍼런스를 붙임. (add references to L-values)
		// 이미 앰퍼샌드 하나 붙어있다면 그대로 유지 

		typedef decltype((x))		x_with_parens_type;
		typedef decltype((cx))		cx_with_parens_type;
		typedef decltype((crx))		crx_with_parens_type;
		
		// 래퍼런스가 붙으면서, const가 함께 붙음. 
		// 래퍼런스이기 때문에 변화되면 안된다는 const의 조건을 같이 가져온 것. 
		typedef decltype((p->m_x))	m_w_with_parens_type;
	}

	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		std::vector<int> vect = { 42,43 };

		auto a = foo();
		typedef decltype(foo()) foo_type;

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;

		auto itr = vect.begin();
		typedef decltype(vect.begin()) iterator_type;

		auto first_element = vect[0];

		// std::vector에 오버로딩되어있는 vector[index]는 vector가 <int> 형식이라면
		// int &래퍼런스 형식을 리턴함. 따라서 선언하는 타입에 따라 int & 
		decltype(vect[1]) second_element = vect[1];
	}

	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x * y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx * cy) prod_cxcy_type;	// result is pure R-value
		auto b = cx * cy;

		// decltype에서 삼항 연산자 사용 시 두 데이터의 자료형이 같고 
		// L-value일 때는 &(앰퍼샌드)가 붙는다. 
		typedef decltype(d1 < d2 ? d1 : d2) cond_type;	// result is L-value. & is added.
		auto c = d1 < d2 ? d1 : d2;

		// x는 정수, d2는 double 타입이므로 범위가 더 큰 double형으로 지정. 
		typedef decltype(x < d2 ? x : d2) cond_type_mixed;	// promotion of x to double
		auto d = x < d2 ? x : d2;
	}

	// T, S의 타입이 같을 경우 리턴 타입에 래퍼런스가 붙게 된다. 
	template<typename T, typename S>
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	// 위의 문제를 해결한 구조로, 리턴 타입에 래퍼런스가 있을 경우 
	// 래퍼런스를 제거한 데이터 형태를 리턴하는 구조 
	template<typename T, typename S>
	auto fpmin(T x, S y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}

	void ex12()
	{
		int i = 42;
		double d = 45.1;

		// error : 'std::min' no matching overload function found. 
		//auto a = std::min(i, d);

		auto a = std::min(static_cast<double>(i), d);
	
		int &j = i;

		typedef decltype(fpmin_wrong(d, d))	fpmin_return_type1;
		typedef decltype(fpmin_wrong(i, d))	fpmin_return_type2;
		typedef decltype(fpmin_wrong(j, d))	fpmin_return_type2;
	}

	void ex13()
	{
		std::vector<int> vect;	// vect is empty.
		
		// vect는 비어있기 때문에 아래 코드에서 오류가 발생해야 하지만,
		// decltype은 괄호 내 연산을 실제로 실행하지 않고, 컴파일 타임에 
		// 결정하기 때문에 오류가 발생하지 않는다. 
		typedef decltype(vect[0])	integer;
	}

	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor() {}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer;	//nested type
	}

	void ex15()
	{
		auto lambda = []() {return 42; };
		decltype(lambda) lambda2(lambda);
		decltype((lambda)) lambda3(lambda);

		cout << "Lambda Functions" << endl;
		cout << &lambda << " " << &lambda2 << endl;
		cout << &lambda << " " << &lambda3 << endl;
	}

	void ex16()
	{
		// generic lambda
		auto lambda = [](auto x, auto y)
		{
			return x + y;
		};

		cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;
	}
};

int main()
{
	Examples examples;

	examples.ex1();
	examples.ex2();
	examples.ex3();
	examples.ex10();
	examples.ex12();
	examples.ex14();
	examples.ex15();
	examples.ex16();

	return 0;
}