#include<iostream>
using namespace std; 

/*

<inline �Լ�>

�Լ��� inline���� �����ϸ� ��ġ �Լ��� �ƴ� ��ó�� �۵��Ͽ� �ӵ��� ���� �� �ִ�.

������ inline ������ �������� ���� ���� �ƴ϶� �ǰ����� ������ 
�����Ϸ��� �Ǵ��Ͽ� inline���� ����ϱ� ������ ��쿡�� ���.

�ֽŹ����� �����Ϸ����� inline���� �������� �ʾƵ� ���������� �Ǵ��Ͽ� 
inline���� ����ҹ��� �Լ����� �ڵ������� inline���� ��ȯ�ϱ⵵ ��.

���� inline Ű���带 ����Ѵٰ� Ư���� ���α׷��� �� ����������
inline Ű���带 ������� �ʴ´ٰ� Ư���� ���α׷��� �� ���������� �ʴ´�. 

��, inline Ű���带 �����Ͽ� ������ ���α׷� ������ inline �Լ��� 
���� ���Ǵ� ��� ���α׷��� ũ�Ⱑ Ŀ�� �� �ִ�. 
���� ����ȭ�� ���� inline�� �����ϱ⺸�ٴ� ���� ���α׷��� 
�˰������̳� �ý��� ����� �����ϴ� ������� ����ȭ�� �ϴ� ���� ����. 

*/


int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl; 
	cout << min(3, 2) << endl; 

	//inline �Լ� ��� �� ���������δ� �Ʒ��� ���� �۵� 
	cout << (5 > 6 ? 6 : 5) << endl; 
	cout << (3 > 2 ? 2 : 3) << endl;

	return 0;
}