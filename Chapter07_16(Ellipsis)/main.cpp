#include<iostream>
#include<cstdarg>	//for ellipsis
using namespace std; 

/*

<Ellipsis>

������ȣ �ϸ��ý� 

*/

//count�� �Ű������� ���� 
double findAverage(int count, ...)
{
	double sum = 0;

	va_list list;

	//count�� ���� �Ű������� ���� 
	va_start(list, count);

	for (int arg = 0; arg < count; arg++)
	{
		//int�� ������ �Ű������� Ÿ�� 
		sum += va_arg(list, int);
	}

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	
	//count ���� ������ ������ �Ű������� ���ڰ� ���� �ʾ� ���� �߻�
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; 

	return 0;
}