#include<iostream>
using namespace std; 

int main()
{
	int x = 10;

	//null statement
	if (x > 10)
		;

	if (x > 10)
	{

	};

	//�̷��� �� ��� if���� �ٷ� ����ǰ� 
	//��ȣ�� ������ �������� �۵��ؼ� x = 1�� �׻� ����
	if (x > 10);
	{
		x = 1;
	}

	//�Ʒ� ��ȣ ���� ������ �ɰ��� ���ϸ� �Ʒ��� ����.
	//���� ��ȣ ���� 0�� ���� ���� false�̹Ƿ� if�� �� ����� ������� X
	//x = 0;
	//if(x)

	if (x = 0)
	{
		cout << x << endl; 
	}
}
