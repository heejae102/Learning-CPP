#include<iostream>
using namespace std; 

int add(const int &a,const int &b)
{
	return a + b;
}

int main()
{
	/*
	
	���� ������ 
	
	*/

	int x = 6, y = 6;

	//��ġ ������ 
	cout << x << " " << y << endl; 
	cout << x++ << " " << y-- << endl; 
	cout << x << " " << y << endl; 

	//��ġ ������ 
	cout << x << " " << y << endl; 
	cout << ++x << " " << ++y << endl; 
	cout << x << " " << y << endl; 

	//1. �����߻��� ����(undefined value ���� ��Ȯ���� ����)
	int z = 1;
	//z = z++; 
	
	//2. �����߻��� ����(�����Ϸ��� ���� �ٸ� ���� �߻�) 
	//�Ѱ��ִ� �Ű������� ������ ���� �ٸ� ���� ok 
	int num = add(z, ++z);
	cout << num << endl; 

	return 0;
}