#include<iostream>
#include "Monster.h"
using namespace std;

/*

<구성관계의 클래스>

몬스터(전체) - 포지션2D(부품) 는 '구성'의 관계를 가진다

- 포지션2D는 몬스터의 일부로서 몬스터가 생성될 때 함께 생성되고,
몬스터가 사라질 때 함께 사라지게 된다.

- 따라서 멤버(부품)의 존재는 클래스가 관리해야 한다(메모리 해제 등)

- 몬스터(상위 클래스)는 포지션2D를 가져다 쓰기만 하고,
포지션2D의 멤버가 내부적으로는 어떻게 작용하는지는 모르는 편일수록 좋다.

- 포지션2D 객체 자체는 다른 클래스에서도 사용될 수 있지만,
몬스터 객체 내에 있는 포지션2D 인스턴스는 다른 클래스에서 쓸 필요도 없고, 쓰여서도 안 된다.

- 단방향성 : 몬스터 클래스는 포지션2D가 어떠한 방식으로 작동하는지, 어떠한 멤버로 구성되어있는지
알아야 하지만 포지션2D는 몬스터 클래스에 대해 알아야 할 필요가 없다.

*/

int main()
{
	Monster mon1("Sanson", Position2D(0, 0));
	cout << mon1 << endl;

	//while (1)
	{
		// event
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}

	return 0;
}