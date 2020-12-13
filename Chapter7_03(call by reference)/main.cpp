#include<iostream>
#include<cmath>
#include<vector>
using namespace std; 

/*

<Call by reference>

������ ���� ȣ�� 

�Ű������� ���� �ѱ�� ���� �ƴ϶�, ������ �� �ֵ��� �Ͽ�
�ش� �� ��ü�� ������ �� ����. 

*/

//�Ķ���͸� ���۷��� ������ �ޱ� ������, ���۷��� ������ ���ڷ� �Ѿ����
//������ �����Ͽ� �Լ� ������ �ش� ���� ���� ����� �������� ���������� ����. 
//��, ���� ���簡 �̷������ �ʰ� �������� ���� ��ü�� �Ѿ���� ����. 

//���۷��� ������ ���� ���� ������ ���ͷ��� �޸� �ּҰ� �����Ƿ� 
//���ͷ��� �μ��� ���� �� ���ٴ� ���̴�. ��, const ������ �����ϸ� �ش� ������ �ذ�.

void addOne(int &y)
{
	//���ڷ� �Ѱܹ޴� ������ �ּҰ��� ��ġ 
	cout << y << " " << &y << endl; 

	y++;
}

//C, C++�� return���� 1���� ���� �� �����Ƿ�, ���� ���� �����ؾ� �ϴ� ��� 
//�ش� ���� ���۷��� ������ �Ѱܼ� �Լ� ������ �����ϴ� ����� �ִ�. 
//������ �Է¸� �ϴ� ���� ���ʿ�, ����ϴ� ���� ���������� ���� 

void getSinCos(const double &degrees, double &sin_out, double &cos_out)
{
	const double pi = 3.141592 / 180.0;
	double radians = degrees * pi;

	sin_out = sin(radians);
	cos_out = cos(radians);
}

//(int*)&ptr ���� �ǹ��̹Ƿ� ������ ���� ��� ���� 
typedef int* pint;
void test(pint &ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl;
}

//(int*)&ptr �̰Ͱ� ���� �ǹ� 
//void test(int *&ptr)
//{
//	cout << ptr << " " << &ptr << endl; 
//}

//�����迭�� ���۷����� �ޱ�(�Ѱܹ��� �迭�� ����� �ݵ�� ����) 
void printElements(int(&arr)[5])
{
	for (const auto &element : arr)
	{
		cout << element << endl; 
	}
}

void printElements(const vector<int> &arr)
{
	for (const auto &element : arr)
	{
		cout << element << endl;
	}
}

int main()
{
	//int x = 5;

	//cout << x << " " << &x << endl; 

	//addOne(x);

	//cout << x << " " << &x << endl;


	//----------------------------------------------------------//


	//double sin(0.0);
	//double cos(0.0);

	//getSinCos(30.0, sin, cos);

	//cout << sin << " " << cos << endl; 


	//----------------------------------------------------------//

	//�����͸� ���۷��� ������ �ѱ�� 

	int x = 5;
	pint ptr = &x;

	cout << *ptr << " " << ptr << " " << &ptr << endl; 
	test(ptr);


	//----------------------------------------------------------//

	//�迭�� ���۷��� ������ �ѱ��
	//���� �迭

	int arr[]{ 1,2,3,4,5 };
	printElements(arr);

	//���� �迭 

	vector<int> array{ 1,2,3,4,5 };
	printElements(array);

	return 0;
}