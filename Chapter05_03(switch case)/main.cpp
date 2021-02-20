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

	//switch문 내에서 변수를 선언할 수는 있지만, 선언과 동시에 초기화는 불가능 
	//단, case문을 스코프로 감싸면 스코프 내에서 초기화 가능 
	//case문 내에서 변수를 선언해도 case문 바깥인 switch문 내에서 선언한 것이나 마찬가지
	//switch문 내에서 선언한 변수를 초기화해주는 case를 거치지 않고 
	//해당 변수 값을 사용하려고 하면 가비지 값이 들어있음. 
	
	//switch문 내에서 변수 선언 시 이런 문제점들이 있으므로, case문을 모두 
	//아우르는 변수가 필요하다면 switch문 바깥에서 선언하여 사용하는 것이 좋다. 
	//부득이하게 case문 내에서 변수를 선언하고 사용해야 한다면 괄호를 사용할 것. 

	switch (static_cast<int>(color))
	{
		//불가능
		//int y = 5;

	case 0:
		//불가능
		//int y = 5;
		int z; 
		z = 10;
		break;

	case 1:
	{
		//가능
		int y = 5;
		y += x;
		cout << y << endl;
		//cout << z << endl; //z가 초기화되지 않은 상태 
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
	//printColorName(5);	//매개변수가 enum형이라 int 데이터는 들어가지 X

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