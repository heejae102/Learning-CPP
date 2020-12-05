#include<iostream>
#include<cstdlib>	//std::rand(), std::srand()
#include<ctime>
#include<random>
using namespace std; 

// 난수처럼 보이는 수를 만드는 함수 
unsigned int PRNG()
{
	static unsigned int seed = 5523;	//seed number 

	seed = 825379 * seed + 2396403;

	// 간단한 예제에서는 나머지 연산자를 사용해도 괜찮지만 
	// 정밀한 결과가 필요한 경우에는 좋지 않은 결과가 나올 수 있음. 
	return seed % 32768;
}

//범위 내의 난수 추출하기 
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);

	return min + static_cast<int>((max - min + 1)*(rand())*fraction);
}


int main()
{
	/*
	
	random number generation
	
	*/

	//for (int count = 1; count <= 100; count++)
	//{
	//	cout << PRNG() << "\t"; 

	//	if (count % 5 == 0) cout << endl; 
	//}

	//시드 넘버에 따라 값이 고정됨. 
	//따라서 프로그램을 구동할 때마다 값이 랜덤하게 나오도록 하려면
	//시드 넘버 값을 바꿔주어야 함.
	//보통 현재시간(타임) 값을 이용해서 시드 넘버 값을 바꿔줌. 
	//단, 디버깅을 할 때는 랜덤 넘버가 고정된 것이 좋음. 

	//srand(5323);	//seed
	//srand(static_cast<unsigned int>(time(0)));

	//for (int count = 1; count <= 100; count++)
	//{
	//	cout << std::rand() << "\t";

	//	if (count % 5 == 0) cout << endl;
	//}

	random_device rd; 
	mt19937 mersenne(rd());	//create a mesenne twister

	//1이상 6이하의 수를 return하는데 각 값이 나올 확률은 모두 동일하다. 
	uniform_int_distribution<> dice(1, 6);

	for (int i = 0; i < 20; i++)
	{
		cout << dice(mersenne) << endl; 
	}


	return 0; 
}