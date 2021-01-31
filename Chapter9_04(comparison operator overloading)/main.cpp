#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

/*

<비교 연산자 오버로딩>

*/

class Cents
{
private:
	int _cents;

public:
	Cents(int cents = 0) { _cents = cents; }

	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	friend bool operator == (const Cents &c1, const Cents &c2)
	{
		return c1._cents == c2._cents;
	}

	// std::sort 를 사용하기 위해서는 > 연산자가 아닌 < 연산자로 오버로딩을 구현해야 함. 
	friend bool operator < (const Cents &c1, const Cents &c2)
	{
		return c1._cents < c2._cents;
	}

	// 입출력 연산자 오버로딩 
	friend std::ostream& operator << (std::ostream &out, const Cents &cents)
	{
		out << cents._cents;
		return out;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(0);

	if (cents1 == cents2) cout << "Equal" << endl;

	cout << std::boolalpha;
	cout << (cents1 == cents2) << endl;


	//---------------------------------------------------------------------//


	vector<Cents> arr(20);

	for (unsigned i = 0; i < 20; i++)
	{
		arr[i].getCents() = i;
	}

	// 벡터 내 원소의 순서를 셔플 
	std::random_shuffle(begin(arr), end(arr));

	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	// 순서가 바뀐 벡터를 다시 정리(sort)하기
	// sort 함수가 arr 안에 들어있는 원소 Cents들의 크기 비교를 알아서 할 수 없으므로,  
	// 객체를 연산자로 비교할 수 있도록 비교 연산자 오버로딩을 구현 해주어야 함. 

	std::sort(begin(arr), end(arr));

	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}