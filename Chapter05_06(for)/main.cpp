#include<iostream>
using namespace std; 

int pow(int base, int exponent)
{
	int result = 1; 

	for (int count = 0; count < exponent; count++)
	{
		result *= base; 
	}

	return result;
}

int main()
{
	//�ݺ� Ƚ���� ������ �ִ� ��쿡 ����ϱ� ����. 

	//for (int count = 0; count < 10; count++)
	//{
	//	cout << count << endl; 
	//}

	int count = 0;

	//���ǹ��� �ۼ����� ������ ���ѷ����� ���� ��. 
	//for (;;)
	//{
	//	cout << count << endl; 
	//}

	cout << pow(2, 7) << endl;

	//for (int i = 10; count >= 0; count--)
	//{
	//	cout << count << endl; 
	//}

	//for���� ���ǹ� ������ ���ǿ� ����� ������ ���� �� ����ϴ� �͵� ���� 
	//���ǽĿ��� i�� j�� �Բ� ����� �� ����. 
	//for (int i = 0, j = 0; i < 10; i++, j--)
	//{
	//	cout << i << " " << j << endl; 
	//}

	//for (int i = 0, j = 0; (i + j) < 10; i++, j += 2)
	//{
	//	cout << i << " " << j << endl; 
	//}

	//�߸��� ���� 
	//unsigned(��ȣ�� ����) �����̹Ƿ� 0������ �ùٸ� ���� ���� �� �ִ�.
	//0���� i--�� �ϰ� �Ǹ� ������ �� ���� ���� �����Ƿ� ���ǰ˻簡 �����
	//������� �ʾƼ� ���ѷ����� ������ �ȴ�. 
	//for (unsigned int i = 10; i >= 0; i--)
	//{
	//	cout << i << endl; 
	//}

	//�ݸ� ���ǰ˻翡�� i���� 0�� �ɶ� ������ false�� �Ǿ�
	//for���� ����ǹǷ� i���� ������ �������� �ʱ� ������ �Լ� ���� �۵� 
	for (unsigned int i = 10; i > 0; i--)
	{
		cout << i << endl;
	}
}