#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

/*

<�� ������ �����ε�>

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

	// std::sort �� ����ϱ� ���ؼ��� > �����ڰ� �ƴ� < �����ڷ� �����ε��� �����ؾ� ��. 
	friend bool operator < (const Cents &c1, const Cents &c2)
	{
		return c1._cents < c2._cents;
	}

	// ����� ������ �����ε� 
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

	// ���� �� ������ ������ ���� 
	std::random_shuffle(begin(arr), end(arr));

	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	// ������ �ٲ� ���͸� �ٽ� ����(sort)�ϱ�
	// sort �Լ��� arr �ȿ� ����ִ� ���� Cents���� ũ�� �񱳸� �˾Ƽ� �� �� �����Ƿ�,  
	// ��ü�� �����ڷ� ���� �� �ֵ��� �� ������ �����ε��� ���� ���־�� ��. 

	std::sort(begin(arr), end(arr));

	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}