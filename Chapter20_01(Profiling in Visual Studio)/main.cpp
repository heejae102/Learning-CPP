#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<numeric>	// std::inner_product
using namespace std; 

/*

<����� ��Ʃ����� �������ϸ� �ϱ�>

�����ϰ� �����ϰ� ���� ���, 
�޸� �������ϸ��� CPU �������ϸ��� ���� �ϴ� ���� ����.
(�Ϲ������δ� ũ�� ��� ����.)

�������ϸ��� ���� ��ü �޸� ��뷮�� 
�� �Լ����� ���Ǵ� ��뷮 ���� ���ϸ鼭,
����ȭ�� �ʿ��� ���� ������� ã�� �� ����. 

���α׷��� ��ų �������� ����ȭ�ϴ� ���� �Ѱ谡 �ְ�,
�˰��� �������� ����ȭ�� �س����� ���� �߿�.

����� ���, ������ ��忡 ���� �������ϸ� ���� 
����� ��忡���� �ڵ带 �� �� �ڼ��� �м��� �� ������
���� ������ ����� �����ս��� �ٸ� �� ����. 
����, ������ ��忡���� �������ϸ��� ���ִ� ���� ����.

*/

void func1()
{
	long long sum = 0;

	for (unsigned i = 0; i < 1000'000; i++)
	{
		sum += i;
	}

	cout << sum << endl;
}

void func2()
{
	long long sum = 0;
	
	for (unsigned i = 0; i < 1000'000'000; i++)
	{
		sum += i;
	}

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}

int main()
{

	run();


	int *d = new int[10000];
	float *f = new float[100];

	delete[] d;
	delete[] f;

	return 0;
}