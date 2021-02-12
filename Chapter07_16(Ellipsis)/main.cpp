#include<iostream>
#include<cstdarg>	//for ellipsis
using namespace std; 

/*

<Ellipsis>

생략부호 일립시스 

*/

//count는 매개변수의 개수 
double findAverage(int count, ...)
{
	double sum = 0;

	va_list list;

	//count는 들어올 매개변수의 개수 
	va_start(list, count);

	for (int arg = 0; arg < count; arg++)
	{
		//int는 저장할 매개변수의 타입 
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
	
	//count 수와 실제로 들어오는 매개변수의 숫자가 맞지 않아 오류 발생
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; 

	return 0;
}