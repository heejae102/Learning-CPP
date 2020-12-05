#include<iostream>
#include<cstdlib>	//std::rand(), std::srand()
#include<ctime>
#include<random>
using namespace std; 

// ����ó�� ���̴� ���� ����� �Լ� 
unsigned int PRNG()
{
	static unsigned int seed = 5523;	//seed number 

	seed = 825379 * seed + 2396403;

	// ������ ���������� ������ �����ڸ� ����ص� �������� 
	// ������ ����� �ʿ��� ��쿡�� ���� ���� ����� ���� �� ����. 
	return seed % 32768;
}

//���� ���� ���� �����ϱ� 
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

	//�õ� �ѹ��� ���� ���� ������. 
	//���� ���α׷��� ������ ������ ���� �����ϰ� �������� �Ϸ���
	//�õ� �ѹ� ���� �ٲ��־�� ��.
	//���� ����ð�(Ÿ��) ���� �̿��ؼ� �õ� �ѹ� ���� �ٲ���. 
	//��, ������� �� ���� ���� �ѹ��� ������ ���� ����. 

	//srand(5323);	//seed
	//srand(static_cast<unsigned int>(time(0)));

	//for (int count = 1; count <= 100; count++)
	//{
	//	cout << std::rand() << "\t";

	//	if (count % 5 == 0) cout << endl;
	//}

	random_device rd; 
	mt19937 mersenne(rd());	//create a mesenne twister

	//1�̻� 6������ ���� return�ϴµ� �� ���� ���� Ȯ���� ��� �����ϴ�. 
	uniform_int_distribution<> dice(1, 6);

	for (int i = 0; i < 20; i++)
	{
		cout << dice(mersenne) << endl; 
	}


	return 0; 
}