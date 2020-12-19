#include<iostream>
using namespace std; 

/*

<재귀적 함수 호출>

작성한 프로그램은 메모리에 저장되어있고,
함수를 호출할 때는 메모리에 저장된 주소를 통해 호출 

재귀함수를 사용할 시 반드시 종료조건이 존재해야 함. 
그렇지 않을 경우 무한정 함수 실행. 

반복실행이 너무 많을 경우 스택 오버플로우가 발생할 수 있다. 
재귀함수는 스택을 사용하기 때문에 프로그램의 성능이 매우 
중요한 경우에는 사용을 지양하는 편이 좋다. 

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

// 피보나치 수열 만들어보기 
// 0 1 2 3 5 8 13 21 ... 

int main()
{
	//countDown(5);

	cout << sumTo(10) << endl; 

	return 0; 
}