#include<iostream>
using namespace std; 

/*

<����� ���α׷���>

syntax error  : ������ ����. �����Ϸ��� �����ؼ� ���� ����

semantic error: ������ ����. ���α׷��� ��������δ� ������ ������
�ǵ��ϴ� �ٿ� �ٸ��� ������ ������ ���ϴ� ��� 

violated assumption : ������ �Է¹����� �Ѿ ���� �ԷµǴ� ���� ����

*/

int main()
{
	//violated assuption 

	string hello = "Hello, my name is violet";

	cout << "Input from 0 to " << hello.size() << endl;

	while (1)
	{
		int idx;
		cin >> idx;

		if (idx >= 0 && idx <= hello.size())
		{
			cout << hello[idx] << endl; 
			break;
		}
		else cout << "Please try again" << endl; 
	}


	return 0;
}