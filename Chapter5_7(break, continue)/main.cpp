#include<iostream>
using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch; 
		cin >> ch; 

		if (ch == 'b') break; 

		if (ch == 'r') return; 
	}

	cout << "Hello" << endl; 
}

int main()
{
	//breakOrReturn();

	//for (int i = 0; i < 10; i++)
	//{
	//	if (i % 2 == 0) continue; 
	//	cout << i << endl; 
	//}

	int count(0);

	//do
	//{
	//	if (count == 5) continue; 

	//	cout << count << endl; 
	//	
	//	//�� ��Ȳ���� count++;�� do-while�� ���ο� ������
	//	//continue�� ���� ������ ���� �������� �ʰ�
	//	//���ǽ����� �ٷ� �̵��ϱ� ������ ���ѷ����� ������ ��. 
	//	//count++;

	//} while (count++ < 10);

	while (true)
	{
		char ch; 
		cin >> ch; 

		cout << ch << " " << count << endl; 
		count++;

		if (ch == 'x') break; 
	}

	return 0; 
}