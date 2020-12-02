#include<iostream>
#include<typeinfo>
#include<string>
using namespace std; 

//������
//������ �ڷ��� �� �������� ��ġ�� �ʾƾ� ��(��������ó�� �ۿ�)
//������ �ڷ����� ���� cpp���� ������ ����� ��� ��� ���Ͽ� 
//������ �ڷ����� �����س��� include�ؼ� ����ϸ� ��. 

/*
	<�������� ���� ���� ���> 

	1) ������ Ư���� ���� ������� �ʴ´ٸ� �� ���� �������� ���ʴ�� 0,1,2,3... 

	2) ��� ������ Ư���� ���� ����ִ´ٸ� �� ������ �ڴ� ���ʴ�� ++1 �Ǵ� ���. 
	0
	1
	5
	6
	7
	.
	.

	3) ������ ���� �������� �Ҵ� ���� 

	4) �������� ���� �Ҵ��ϴ� ��� ���� �ٸ� ������ ���� ���� �Է��ϸ� 
	���� ������ ����� �� �����Ƿ� �� ����� ���� �ٸ� ������ ������ ��. 


	<enum�� ����� ���>
	
	cout : enum�� ���� ��� �� ���������� ���� ��� 
	cin  : cin���� enum�� ������ ���� �޴� ���� �Ұ��� 
		   int�� ������ ���� �޾� ��ȸ�ϴ� ������� ��� 

*/

enum Color	//user-defined data types
{
	COLOR_BLACK,
	COLOR_RED,
	COLOR_BULE,
	COLOR_GREEN
};

enum Feeling
{
	HAPPY,
	JOY,
	TIRED,
	BLUE
};

//int computeDamage(int weapon_id)
//{
//	if (weapon_id == 0) //sword
//	{
//		return 1; 
//	}
//
//	if (weapon_id == 1)
//	{
//		return 2;
//	}
//}

int main()
{
	Color paint = COLOR_BLACK;
	Color house(COLOR_BULE);
	Color appleP{ COLOR_RED };

	cout << paint << " " << COLOR_BLACK << endl; 

	// ���������δ� int�� ����ó�� �ۿ�������,
	// enum�� ������ ���� int�� ������ �����ϴ� ���� ���������� 
	// int�� ������ ���� enum�� ������ �����ϴ� ���� �Ұ��� 
	// ��, casting�� ���� �����ϴ� ���� ���� 

	int blue = COLOR_BULE;
	cout << blue << " " << COLOR_BULE << endl; 

	//paint = blue;
	paint = static_cast<Color>(blue);
	cout << paint << " " << blue << endl; 

	//cin�� enum�� ������ ���� �޴� ���� �Ұ��� 
	//cin >> paint;

	int in_paint;
	cin >> in_paint; 

	if (in_paint == COLOR_BLACK) paint = COLOR_BLACK;
	//...

	//str�� �����͸� �Է¹޾� �Ʒ��� ���� ��뵵 ���������� �������� ����.
	//��Ÿ�� ���� �߸� �Է��� ���� �־� ���ɿ� ������ ���� �� ����. 
	string str_paint;
	cin >> str_paint;

	if (str_paint == "COLOR_BLAC") paint = COLOR_BLACK;

}