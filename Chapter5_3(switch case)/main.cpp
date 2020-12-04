#include<iostream>
using namespace std; 

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	switch (color)
	{
	case Colors::BLACK:
		break;
	case Colors::WHITE:
		break;
	case Colors::RED:
		break;
	case Colors::GREEN:
		break;
	case Colors::BLUE:
		break;
	}

	int x = 0;

	//switch�� ������ ������ ������ ���� ������, ����� ���ÿ� �ʱ�ȭ�� �Ұ��� 
	//��, case���� �������� ���θ� ������ ������ �ʱ�ȭ ���� 
	//case�� ������ ������ �����ص� case�� �ٱ��� switch�� ������ ������ ���̳� ��������
	//switch�� ������ ������ ������ �ʱ�ȭ���ִ� case�� ��ġ�� �ʰ� 
	//�ش� ���� ���� ����Ϸ��� �ϸ� ������ ���� �������. 
	
	//switch�� ������ ���� ���� �� �̷� ���������� �����Ƿ�, case���� ��� 
	//�ƿ츣�� ������ �ʿ��ϴٸ� switch�� �ٱ����� �����Ͽ� ����ϴ� ���� ����. 
	//�ε����ϰ� case�� ������ ������ �����ϰ� ����ؾ� �Ѵٸ� ��ȣ�� ����� ��. 

	switch (static_cast<int>(color))
	{
		//�Ұ���
		//int y = 5;

	case 0:
		//�Ұ���
		//int y = 5;
		int z; 
		z = 10;
		break;

	case 1:
	{
		//����
		int y = 5;
		y += x;
		cout << y << endl;
		//cout << z << endl; //z�� �ʱ�ȭ���� ���� ���� 
		break;
	}

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	default:
		break; 
	}
}

int main()
{
	printColorName(Colors::WHITE);
	//printColorName(5);	//�Ű������� enum���̶� int �����ʹ� ���� X

	int x;
	cin >> x;

	switch (x)
	{
	case 0:
		cout << "zero";
		break;

	case 1:
		cout << "one";
		break;

	case 2:
		cout << "two";
		break;
	}

	cout << endl; 
}