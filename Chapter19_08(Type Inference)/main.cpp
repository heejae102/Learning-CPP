#include<iostream>
#include<vector>
#include<algorithm>	// std::min
using namespace std; 

/*

<�ڷ��� �߷�(Type Inference) auto�� decltype>

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

		// auto�� ���� iterator�� ������ �������� �ʰ� ���ϰ� ��밡�� 
		for (auto itr = vect.begin(); itr != vect.end(); itr++)
		{
			cout << *itr;
		}

		// auto�� ���� ����� 
		for (auto itr : vect)	// for(const auto &itr : vect)
		{
			cout << itr;
		}
	}

	void ex2()
	{
		// auto�� �⺻���� ������ ������ ������ ������ ���ľ�� ��� �����ϹǷ�
		// Ư���� Ư���� �ο��ϰ� ���� ��� auto�� �����ϸ鼭 ����.

		int x = int();

		auto auto_x = x;
		const int &crx = x;

		// auto�� �߷� �� const, &(���۷���)�� �����ϹǷ� int Ÿ������ �߷� 
		auto auto_crx1 = crx;

		// auto������ const, &(���۷���) �������� ����ϰ� ���� ��� �Ʒ��� ���� ����
		const auto& auto_crx2 = crx;

		// volatile ������ ���� ���� ��ȭ�ϱ� ������ ����ȭ �� ���޶�� �ǹ�
		// �ַ� ��Ƽ�������� ������ �� ��� 
		volatile int vx = 1024;

		// auto �������� ���� �� volatile�� ���� 
		auto avx = vx;

		// auto�� volatile Ư���� �߰��ϰ� ���� ��� �Ʒ��� ���� ���� 
		volatile auto vavx = vx;
	}

	// ���ø����� �����͸� ���� ��, 
	// auto�� ���������� ������ �� �����ǰ� ����Ʈ Ÿ�Ը� ����.
	//template<class T>
	//void func_ex3(T arg) {}

	// �������� ������ ��� �޾Ƽ� ������ ������ �߷��ؾ� �� ���, 
	// �Ʒ��� ���� T�� �޴� �κп� �ʿ��� ������ �ٿ��� ����. 
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
		
		// ���� auto �������� �����͸� ���� ��, ���ľ�(const ��)�� ����������, 
		// ���۷����� auto�� ������ �� �ش� �����Ͱ� const������ ��� 
		// �ڵ����� const & �������� �����͸� �ް� �ȴ�. 
		auto &rc = c;

		// const �����̹Ƿ� ������ �� ���� �Ұ��� (error) 
		//rc = 123;		
	}

	void ex5()	// amendment
	{
		int i = 42;

		// &&(���� ���ۻ���)�� r-value ���۷����� �����ϰ� �ʹٴ� �ǵ� 

		// ������ �����ʿ� ���ԵǴ� ���簡 l-value�̹Ƿ� l-value �������� ����. 
		auto&& ri_1 = i;	// l-value

		// �����ʿ� ���ԵǴ� ���簡 pure r-value�̹Ƿ� r-value �������� ����. 
		auto&& ri_2 = 42;	// r-value
	}

	void ex6()
	{
		int x = 42;
		const int *p1 = &x;
		auto p2 = p1;

		//*p2 = 43;	// error
	}

	// lhs, rhs �� �����ִ� �Լ��ε�, �� ������ �ڷ����� �޶�(ex. int, float)
	// ������� �ڷ����� ������ ���� ������ ���� ����. 
	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		// ��� ���� ������ ������ ���� �𸣹Ƿ� auto �������� �߷� 
		auto prod1 = lhs * rhs;

		// C++11 ������ �Ϻ� �����Ϸ����� �ذ��ϴ� ���. ������� type�� ���� 
		//typedef typeof(lhs*rhs) product_type;		// pre-C++11 'some' compilers 
		
		// ��� C++���� ����ϴ� ��� (declared type)
		// lhs * rhs �� ������ �����ϴ� ���� �ƴϰ�, ��� Ÿ�Ը� �߷� 
		typedef decltype(lhs*rhs) product_type;
		product_type prod2 = lhs * rhs;

		// �Ʒ��� ���� ���� 2������ 1�������� �ٿ��� ��� ���� 
		decltype(lhs*rhs) prod3 = lhs * rhs;
	}

	// return type���� declared type�� ����ϴ� �͵� ���� 
	template<typename T, typename S>
	// ��, �Ʒ��Ͱ� ���� ����� �Ұ��� (�����Ϸ��� �д� ������ ���� �߻�)
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

		// �������� ������ 
		const S *p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		
		// �����ʹ� ����� �߷� 
		auto d = p;

		// p�� const������, m_x�� const�� �ƴϹǷ� e�� �Ϲ� int��
		auto e = p->m_x;

		// decltype�� auto�� ����� �ٸ��� 'declared'��� ���״�� 
		// �����Ͱ� ����� ���� �״�� ���� ���� ������. 

		typedef decltype(x)			x_type;
		typedef decltype(cx)		cx_type;
		typedef decltype(crx)		crx_type;
		typedef decltype(p->m_x)	m_x_type;	// 'declared' type. 

		// ��ȣ�� �� ������ ���۷����� ����. (add references to L-values)
		// �̹� ���ۻ��� �ϳ� �پ��ִٸ� �״�� ���� 

		typedef decltype((x))		x_with_parens_type;
		typedef decltype((cx))		cx_with_parens_type;
		typedef decltype((crx))		crx_with_parens_type;
		
		// ���۷����� �����鼭, const�� �Բ� ����. 
		// ���۷����̱� ������ ��ȭ�Ǹ� �ȵȴٴ� const�� ������ ���� ������ ��. 
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

		// std::vector�� �����ε��Ǿ��ִ� vector[index]�� vector�� <int> �����̶��
		// int &���۷��� ������ ������. ���� �����ϴ� Ÿ�Կ� ���� int & 
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

		// decltype���� ���� ������ ��� �� �� �������� �ڷ����� ���� 
		// L-value�� ���� &(���ۻ���)�� �ٴ´�. 
		typedef decltype(d1 < d2 ? d1 : d2) cond_type;	// result is L-value. & is added.
		auto c = d1 < d2 ? d1 : d2;

		// x�� ����, d2�� double Ÿ���̹Ƿ� ������ �� ū double������ ����. 
		typedef decltype(x < d2 ? x : d2) cond_type_mixed;	// promotion of x to double
		auto d = x < d2 ? x : d2;
	}

	// T, S�� Ÿ���� ���� ��� ���� Ÿ�Կ� ���۷����� �ٰ� �ȴ�. 
	template<typename T, typename S>
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	// ���� ������ �ذ��� ������, ���� Ÿ�Կ� ���۷����� ���� ��� 
	// ���۷����� ������ ������ ���¸� �����ϴ� ���� 
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
		
		// vect�� ����ֱ� ������ �Ʒ� �ڵ忡�� ������ �߻��ؾ� ������,
		// decltype�� ��ȣ �� ������ ������ �������� �ʰ�, ������ Ÿ�ӿ� 
		// �����ϱ� ������ ������ �߻����� �ʴ´�. 
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