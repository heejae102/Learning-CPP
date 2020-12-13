#include<iostream>
#include<array>
#include<tuple>
using namespace std; 

//int getValue(int x)
//{
//	int value = x * 2;
//	return value;
//}

//���� ���縦 ���̱� ���� ���� Ÿ���� �ּҷ� ������ �� ������, 
//�Լ� �� ���������� �Լ��� ����Ǹ鼭 ������Ƿ� �Լ� �� ���������� 
//�ּҰ��� �����ϴ� ���� �����ϴ� ���� ����. 

//�ּҰ��� ���� 
//int* getValue(int x)
//{
//	int value = x * 2;
//	return &value;
//}

//���۷����� ���� 
int& getValue(int x)
{
	int value = x * 2;
	return value;
}

//���۷��� ������ ���ϰ� ���� 
int& get(array<int, 100> &my_arr, int idx)
{
	return my_arr[idx];
}

//������ �̷��� �޸𸮸� �Ҵ��� ���, delete�� �ٸ� ������ 
//������ �ؾ��ϱ� ������ �򰥸� �� �����Ƿ� �������� ����. 
int* allocateMemory(int size)
{
	return new int[size];
}

struct TestS
{
	int a, b, c, d;
};

TestS getStruct()
{
	TestS my_s{ 1,2,3,4 };
	return my_s;
}

//Ʃ���� �̿��Ͽ� ���� ���� ���� Ÿ���� �ѱ�� 
//int�� double���� �����Ѵٴ� �ǹ�(����� �������� ���)
tuple<int, double> getTuple()
{
	int a = 10;
	double b = 3.14;

	return make_tuple(a, b);
}

int main()
{
	//�������� �Ѱܿ��� �ּҰ��� �̿��Ͽ� ���� �ʱ�ȭ 

	//1.�Ѱܹ��� �ּ� ���� ������  
	//int value = *getValue(3);

	//2. �ּҰ� ��ü�� �Ѱܹޱ� 
	//(�Լ��� ����� �������� �̹� ������� ������ �����ϴ� ������ ���� �߻�)
	//int *ptr = getValue(3);


	//--------------------------------------------------------------------------//

	
	//�޸𸮸� �Ҵ��Ͽ� �Ҵ��� �޸��� �ּҰ��� �ѱ�� ��쵵 �ִ�. 

	int *arr = allocateMemory(1024);
	delete[] arr;


	//--------------------------------------------------------------------------//


	//���۷��� ������ ����
	//����Ÿ���� ���۷����� ����Ű�� ������ ���� ����Ǿ value�� ����
	int value = getValue(5);

	//�ط��۷����� ���۷��� ������ ���� ���, �Լ��� ���������� �����ϴ� ���̱� ������
	//���� ������� �� ���� �����ϰ� �Ǹ� ������ �߻�
	int &var = getValue(5);

	cout << var << endl; 	
	cout << var << endl;	//�����Ⱚ ��� 


	//--------------------------------------------------------------------------//

	
	//�޸𸮰� �ֹ߼��� �ƴ� ���·� ���� �����鼭 �ش� �޸𸮸� ���۷����Ͽ� 
	//��ġ ����ó�� ����� �� �ִ� ���� 
	std::array<int, 100> my_arr;
	my_arr[30] = 10;

	//my_arr[30] = 1024 �� ���� ���� 
	get(my_arr, 30) = 1024;
	
	cout << my_arr[30] << endl; 


	//--------------------------------------------------------------------------//


	//���� Ÿ������ ����ü�� �ѱ�� 

	TestS my_s = getStruct();
	cout << my_s.a << endl;
	cout << my_s.b << endl; 
	cout << my_s.c << endl; 
	cout << my_s.d << endl; 


	//--------------------------------------------------------------------------//


	//Ʃ�÷� ���ϰ� �ޱ� 
	tuple<int, double> my_tp = getTuple();
	cout << get<0>(my_tp) << endl; 
	cout << get<1>(my_tp) << endl; 

	//c++17 �������� �̷��Ե� ���� 
	//auto[a, b] = getTuple();
	//cout << a << endl; 
	//cout << b << endl; 


	return 0;
}