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

	////color와 fruit는 별개의 변수이지만 내부적으로는 int타입으로 사용되므로
	////color와 fruit를 비교하면 내부에 저장된 값이 동일 
	//if (color == fruit)
	//	cout << "Color is fruit?" << endl; 

	//enum형을 class형식으로 선언하면 해당 문제 방지 가능 
	Color color1 = Color::RED;
	Color color2 = Color::BLUE;
	Fruit fruit = Fruit::BANANA;

	//이렇게 클래스 형식으로 선언하면 값을 집어넣을 때 해당 클래스로 영역을 지정해주기 때문에
	//color와 fruit는 서로 다른 영역이므로 값을 비교할 수 없다. 
	//대신 같은 영역에 있는 변수들끼리는 비교 가능 
	//if (color == fruit)
	//	cout << "Color is fruit?" << endl;

	if (color1 == color2) cout << "same color" << endl; 
	else cout << "different clor" << endl; 

	return 0; 
}