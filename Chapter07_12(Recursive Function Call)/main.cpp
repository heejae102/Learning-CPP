#include<iostream>
using namespace std; 

/*

<����� �Լ� ȣ��>

�ۼ��� ���α׷��� �޸𸮿� ����Ǿ��ְ�,
�Լ��� ȣ���� ���� �޸𸮿� ����� �ּҸ� ���� ȣ�� 

����Լ��� ����� �� �ݵ�� ���������� �����ؾ� ��. 
�׷��� ���� ��� ������ �Լ� ����. 

�ݺ������� �ʹ� ���� ��� ���� �����÷ο찡 �߻��� �� �ִ�. 
����Լ��� ������ ����ϱ� ������ ���α׷��� ������ �ſ� 
�߿��� ��쿡�� ����� �����ϴ� ���� ����. 

*/

void countDown(int count)
{
	cout << count << endl;

	if (count > 0) countDown(--count);
}

int sumTo(int sumto)
{
	if (sumto <= 0) return 0;
	else if (sumto <= 1) return 1;
	else
	{
		const int sum_minus_one = sumTo(sumto - 1);
		cout << sum_minus_one << endl; 
		return sum_minus_one + sumto;
	}
}

// �Ǻ���ġ ���� ������ 
// 0 1 2 3 5 8 13 21 ... 

int main()
{
	//countDown(5);

	cout << sumTo(10) << endl; 

	return 0; 
}