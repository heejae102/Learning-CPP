#include<iostream>
using namespace std; 

int main()
{
	cout << "while-loop test" << endl; 

	//int count = 0;
	//while (count < 10)
	//{
	//	cout << count << endl; 

	//	count++; 
	//}

	//unsigned int(��ȣ�� ���� ����) �ڷ����� �� �� ���� ���� �ش� �ڷ�����
	//������ ������ ��� ���(������ �� ���) �����÷ο� ������ �߻��ؼ� 
	//�ùٸ� ���� ��µ��� ����. 

	//unsigned int count = 10;
	//while (count >= 0)
	//{
	//	if (count == 0) cout << "zero" << endl; 
	//	else cout << count << endl; 

	//	count--;
	//}


	//int outer_count = 1; 

	//while (outer_count <= 5)
	//{
	//	int inner_count = 1; 

	//	while (inner_count <= outer_count)
	//	{
	//		cout << inner_count++ << " ";
	//	}

	//	cout << endl; 
	//	++outer_count;
	//}

	// do-while��

	//Ư¡1)
	//���ǿ� ���Ǵ� ������ �ݵ�� do-while�� �ٱ��� �����ؾ� �Ѵ� 
	//do-while�� ���� ���� ��� while ���ǹ� �˻縦 �� �� �̹� ������ 
	//����� �����̹Ƿ� ���� �߻� 

	//Ư¡2) while(����); while ���ǹ� �ڿ� �����ݷ��� �ٿ���� �Ѵ�. 

	int selection;	//must be declared outside do/while loop

	do
	{
		cout << "1. add" << endl; 
		cout << "2. sub" << endl; 
		cout << "3. mul" << endl; 
		cout << "4. div" << endl; 
		cin >> selection;

	} while (selection <= 0 || selection >= 5);

	cout << "You selected " << selection << endl; 

	return 0; 
}