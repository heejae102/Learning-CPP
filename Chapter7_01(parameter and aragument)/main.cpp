#include<iostream>
using namespace std; 

//int x, int y : parameters
int test(int x, int y);

int test(int x, int y)
{
	//�Լ��� �Ķ���ʹ� ��������ó�� �ۿ��Ͽ� �Լ��� ����Ǹ鼭 
	//�����Ǿ� �Ѱܹ��� argument ���� �����Ͽ� �ʱ�ȭ�ǰ�, 
	//�Լ��� �����鼭 �ٽ� ������� ���� 

	return x + y;
	// x and y are  destroyed here 
}

int main()
{
	int x = 1, y = 2;

	test(6, 7);		//6, 7 : argements (actual parameters)
	test(x, y + 1);

	return 0;
}