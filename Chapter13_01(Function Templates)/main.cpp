#include<iostream>
#include"Cents.h"
using namespace std; 

/*

<�Լ� ���ø�> Function Templates

���ø��� ���� ���� �ڷ����� ���� ����� �ڵ��� �ݺ��ۼ��� ������ ��. 

���ø��� Ŭ���� �ڷ����� ������ �����ѵ�, �� Ŭ������ ����� ���
�ش� Ŭ������ ����ϱ� ���� �ʿ��� �Լ� �� ��ɵ��� ���� �������־�� ��. 

���ø��� �ν��Ͻ�ȭ (Template Instantiation) 
�����Ϸ��� �Լ�(Ŭ����) ���ø����κ��� ���� C++ �Լ�(Ŭ����)�� ����� ����

��, ��� Ÿ�Կ� ���������� Generalized �� ���ø��� 
Ư�� Ÿ�Կ� �����Ǿ� �۵��ϴ� ������ '���ø��� �ν��Ͻ�ȭ'��� �θ���.  

*/

// ���� �ڵ带 ���� Ÿ������ �����Ű�� ���� 
// ���ʿ��ϰ� �ݺ����� �ڵ带 �ۼ��ؾ� �Ѵ�. 
// �ݸ� ���ø��� ����ϸ� �ϳ��� �ڵ常���� ��� Ÿ�Կ� ���� ���� 

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
	// ���ø����� �ۼ��� �ϳ��� �Լ� ������ ��� Ÿ�Կ� ���� ���� 

	std::cout << getMax(1, 2) << std::endl;
	std::cout << getMax(3.14, 1.592) << std::endl;
	std::cout << getMax(1.2f, 3.4f) << std::endl;
	std::cout << getMax('a', 'c') << std::endl;

	std::cout << getMax(Cents(5), Cents(10)) << std::endl;

	return 0;
}