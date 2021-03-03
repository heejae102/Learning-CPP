#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<numeric>	// std::inner_product
using namespace std; 

/*

<비쥬얼 스튜디오로 프로파일링 하기>

정밀하게 측정하고 싶은 경우, 
메모리 프로파일링과 CPU 프로파일링을 따로 하는 것이 좋음.
(일반적으로는 크게 상관 없음.)

프로파일링을 통해 전체 메모리 사용량과 
각 함수에서 사용되는 사용량 등을 비교하면서,
최적화가 필요한 곳이 어디인지 찾을 수 있음. 

프로그래밍 스킬 레벨에서 최적화하는 것은 한계가 있고,
알고리즘 레벨에서 최적화를 해나가는 것이 중요.

디버그 모드, 릴리즈 모드에 대해 프로파일링 가능 
디버그 모드에서는 코드를 좀 더 자세히 분석할 수 있지만
실제 릴리즈 모드의 퍼포먼스와 다를 수 있음. 
따라서, 릴리즈 모드에서도 프로파일링을 해주는 것이 좋음.

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