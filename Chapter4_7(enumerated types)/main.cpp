#include<iostream>
#include<typeinfo>
#include<string>
using namespace std; 

//열거형
//열거형 자료형 내 변수명끼리 겹치지 않아야 함(전역변수처럼 작용)
//열거형 자료형을 여러 cpp파일 내에서 사용할 경우 헤더 파일에 
//열거형 자료형을 정의해놓고 include해서 사용하면 됨. 

/*
	<열거형에 값이 들어가는 방식> 

	1) 변수에 특정한 값을 집어넣지 않는다면 맨 위의 변수부터 차례대로 0,1,2,3... 

	2) 어떠한 변수에 특정한 값을 집어넣는다면 그 변수의 뒤는 차례대로 ++1 되는 방식. 
	0
	1
	5
	6
	7
	.
	.

	3) 각각의 값을 수동으로 할당 가능 

	4) 수동으로 값을 할당하는 경우 서로 다른 변수에 같은 값을 입력하면 
	변수 구분이 어려울 수 있으므로 각 밸류는 서로 다른 값으로 지정할 것. 


	<enum형 입출력 방식>
	
	cout : enum형 값을 출력 시 정수형으로 값을 출력 
	cin  : cin으로 enum형 변수에 값을 받는 것은 불가능 
		   int형 변수에 값을 받아 우회하는 방식으로 사용 

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

	// 내부적으로는 int형 변수처럼 작용하지만,
	// enum형 변수의 값을 int형 변수에 대입하는 것은 가능하지만 
	// int형 변수의 값을 enum형 변수에 대입하는 것은 불가능 
	// 단, casting을 통해 대입하는 것은 가능 

	int blue = COLOR_BULE;
	cout << blue << " " << COLOR_BULE << endl; 

	//paint = blue;
	paint = static_cast<Color>(blue);
	cout << paint << " " << blue << endl; 

	//cin을 enum형 변수에 값을 받는 것은 불가능 
	//cin >> paint;

	int in_paint;
	cin >> in_paint; 

	if (in_paint == COLOR_BLACK) paint = COLOR_BLACK;
	//...

	//str형 데이터를 입력받아 아래와 같이 사용도 가능하지만 권장하지 않음.
	//오타로 값을 잘못 입력할 수도 있어 성능에 문제가 생길 수 있음. 
	string str_paint;
	cin >> str_paint;

	if (str_paint == "COLOR_BLAC") paint = COLOR_BLACK;

}