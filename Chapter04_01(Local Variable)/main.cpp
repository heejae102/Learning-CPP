#include<iostream>

//���� ���� ���� Ȥ�� �Լ����� ����ϰ� �ʹٸ� ���ӽ����̽��� ���� 
//���ӽ����̽��� ��ø�� ���� 

namespace work1
{
	namespace work11
	{
		int a = 1;

		void doSomething()
		{
			a += 3;
		}
	}
}

namespace work2
{
	int a = 1;

	void doSomething()
	{
		a += 5;
	}
}

int main()
{
	using namespace std;

	/*
	
	���� ����(local variable)�� ����(scope)�� ���ӱⰣ(duration)
	
	:: ���� ���� ������(scope resolution operator)  

	*/

	int apple = 5;

	cout << apple << endl; 

	if(true)
	{
		//���� ������ ���� ������ �̸��� ���Ƶ� ���� �ٸ� ������ �ν�
		//�ش� ������ �������� ���� ������ �ν� 
		//�������� ����� ���� ������ ������� ���� ������ �ν� 
		//������ �򰥸��� �ʵ��� ������ �ٸ� �������� ����ϴ� ���� ����. 

		int apple = 1;
		cout << apple << endl; 
	}

	cout << apple << endl; 

	cout << work1::work11::a << endl; 
	cout << work2::a << endl; 

	return 0; 
}