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

	// std��� namespace �� Ư���� �� ������ ����� ��� namespace ��ü�� using �������� �ʰ�,
	// std �� Ư���� Ű���常 ���� using���� �����Ͽ� ����� �� �ִ�. 

	//using std::cout;
	//using std::cin;
	//using std::endl;

	//using namespace a;
	//using namespace b; 

	//namespace a�� b ��� my_var ������ �����Ƿ� � ������ 
	//������ ����ؾ� �� �� ���� ambiguity ������ �߻� 
	//cout << my_var << endl; 

	//1.������ �տ� ��� �� ���� �����̽� ���� ���� ��� ���� ���� 
	cout << a::my_var << endl; 

	//2. �������� ������ ������ ���� ���� 
	{
		using namespace a;
		cout << my_var << endl; 
		
		//std ���� �ȿ� count ��� ������ ����ؼ� ���� �߻� 
		//cout << count << endl; 
		cout << a::count << endl; 
	}

	{
		using namespace b;
		cout << my_var << endl; 
	}

	//using namespace�� Ư�� ������� ���� ������ ���� ���  
	//�ش� ����� include�ϴ� ��� cpp���Ͽ� ������ �־� ������ �߻��� �� ����.
	//���� ������� �������� ����ϴ� ���� ������ ��. 
	//������ ������Ϻ��ٴ� cpp���Ͽ� ����ִ� ���� ����. 

	return 0;
}