#include<iostream>
using namespace std; 

int main()
{
	enum class Color
	{
		RED,
		BLUE
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
	};

	//Color color = RED; 
	//Fruit fruit = BANANA;

	////color�� fruit�� ������ ���������� ���������δ� intŸ������ ���ǹǷ�
	////color�� fruit�� ���ϸ� ���ο� ����� ���� ���� 
	//if (color == fruit)
	//	cout << "Color is fruit?" << endl; 

	//enum���� class�������� �����ϸ� �ش� ���� ���� ���� 
	Color color1 = Color::RED;
	Color color2 = Color::BLUE;
	Fruit fruit = Fruit::BANANA;

	//�̷��� Ŭ���� �������� �����ϸ� ���� ������� �� �ش� Ŭ������ ������ �������ֱ� ������
	//color�� fruit�� ���� �ٸ� �����̹Ƿ� ���� ���� �� ����. 
	//��� ���� ������ �ִ� �����鳢���� �� ���� 
	//if (color == fruit)
	//	cout << "Color is fruit?" << endl;

	if (color1 == color2) cout << "same color" << endl; 
	else cout << "different clor" << endl; 

	return 0; 
}