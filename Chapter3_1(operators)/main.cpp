#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	/*

	연산자 우선순위

	우선순위가 같은 연산자를 사용할 때 무엇을 먼저 연산할 지 정하는 것이 결합법칙(associativity)

	결합법칙(Associativity)
	우선순위가 같은 연산자들을 어떤 방향으로 연산할 것인가?
	Left-To-Right : 왼쪽에서 오른쪽 순서로 연산
	Right-To-Left : 오른쪽에서 왼쪽 순서로 연산

	대부분의 경우에서 Left-To-Right 순서로 연산을 하지만,
	몇 가지의 단항 연산자(+,-,!,~ 등)나 대입연산자들의 경우 Right-To-Left 순서로 연산

	연산자 우선순위 및 결합법칙이 애매한 경우에는
	괄호를 사용하여 직접 우선순위를 조정해주는 것이 좋음.

	*/

	//제곱연산이 필요한 경우 

	int x = std::pow(2, 3); //2의 3제곱 
	cout << x << endl;

	return 0;
}