#include<iostream>
#include<cstring>
using namespace std; 

int main()
{
	// ���ڿ����� �ش� ���ڿ��� �����ϰ� �ִ� ���ڵ� �ܿ� 
	// ���ڿ� �������� '\0' null ���Ұ� ���ԵǾ� �ִ�. 
	// ���� ���ڿ� ������� �ش� ���ڿ��� ���� ���� + 1 

	//char myString[] = "string";

	//for (int i = 0; i < (int)strlen(myString) + 1; i++)
	//{
	//	cout << (int)myString[i] << endl;
	//}

	//cout << sizeof(myString) / sizeof(myString[0]) << endl;

	// NULL ���ڸ� �����ߴ���, �ڿ� ���ڿ��� �� �������� �ұ��ϰ� 
	// NULL ���� �ٷ� �ձ����� ���ڿ��� ��� 
	// �ڹ��ڿ� ��� �� NULL ���ڸ� ���������� ����ϱ� ������

	//char str[256];

	////cin >> str; 
	////str[0] = 'A';
	////str[2] = '\0';
	////getline(cin, str);
	//cin.getline(str, sizeof(str));

	////���鹮�ڿ� �� ���ڴ� �ٸ���. �ƽ�Ű�ڵ� ���� ����غ��� 
	////���鹮�ڴ� 32, NULL ���ڴ� 0 
	//int idx = 0;
	//while (true)
	//{
	//	if (str[idx] == '\0') break; 
	//	cout << str[idx] << ' ' << (int)str[idx] << endl; 
	//	idx++;
	//}

	//strcpy(A, B) : B�� ���ڿ��� A�� �����ϴ� �Լ� 
	//�����ϰ��� �ϴ� ���ڿ��� ���̰� ���� �� ���ڿ��� ���̺��� �� ��� ���� �߻�

	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, source);
	//strcpy_s(dest, sizeof(source), source);

	cout << source << endl; 
	cout << dest << endl; 

	//strcat : ���ڿ� �ڿ� �ٸ� ���ڿ��� ���̴� �Լ� 
	//strcmp : ���ڿ��� ������ ���ϴ� �Լ� 

	char basic[50] = "basic";
	strcat_s(basic, "append");
	cout << basic << endl; 

	//���ڿ��� ���Ͽ� ���� ���� ���  0 ��ȯ
	//���ڿ��� ���Ͽ� ���� ���� ��� -1 ��ȯ 
	cout << strcmp(dest, source) << endl; 
	cout << strcmp(dest, basic) << endl; 

	return 0; 
}