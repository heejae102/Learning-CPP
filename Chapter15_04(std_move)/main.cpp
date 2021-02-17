#include<utility>
#include<vector>
#include"AutoPtr.h"
#include"Resource.h"
using namespace std; 

/*

<std::move>

std::move()

��ȣ ���� ������ L-value ���� R-value �� �ٲ㼭 �����ϴ� ���� 
����� �� ���������� �ʿ��� �Լ����� �����ؾ� ��. 

*/

template<class T>
void MySwap(T &a, T &b)
{
	//T tmp = a;
	//a = b;
	//b = tmp;

	// Move semantics �� �̿��� ����
	// �� �� ȿ�������� ��ü ���� 

	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	//{
	//	AutoPtr<Resource> res1(new Resource(10000000));

	//	cout << res1._ptr << endl;

	//	AutoPtr<Resource> res2 = res1;
	//	AutoPtr<Resource> res2 = std::move(res1);	// move semantic ���

	//	cout << res1._ptr << endl; 
	//	cout << res2._ptr << endl; 
	//}

	//{
	//	AutoPtr<Resource> res1(new Resource(3));
	//	res1->setAll(3);

	//	AutoPtr<Resource> res2(new Resource(5));
	//	res2->setAll(5);

	//	MySwap(res1, res2);

	//	res1->print();
	//	res2->print();
	//}

	//{
	//	vector<string> v;
	//	string str = "Hello";

	//	v.push_back(str);

	//	cout << str << endl;
	//	cout << v[0] << endl;

	//	v.push_back(std::move(str));

	//	cout << str << endl; 
	//	cout << v[0] << " " << v[1] << endl;
	//}

	return 0;
}