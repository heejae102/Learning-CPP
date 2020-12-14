#include<iostream>
using namespace std; 

/*

<inline 함수>

함수를 inline으로 선언하면 마치 함수가 아닌 것처럼 작동하여 속도를 높일 수 있다.

하지만 inline 선언은 강제성을 가진 것이 아니라 권고사항 정도로 
컴파일러가 판단하여 inline으로 사용하기 적합한 경우에만 사용.

최신버전의 컴파일러들은 inline으로 선언하지 않아도 논리적으로 판단하여 
inline으로 사용할법한 함수들은 자동적으로 inline으로 변환하기도 함.

따라서 inline 키워드를 사용한다고 특별히 프로그램이 더 빨라지지도
inline 키워드를 사용하지 않는다고 특별히 프로그램이 더 느려지지도 않는다. 

단, inline 키워드를 남용하여 실제로 프로그램 내에서 inline 함수가 
많이 사용되는 경우 프로그램의 크기가 커질 수 있다. 
따라서 최적화를 위해 inline에 의존하기보다는 실제 프로그램의 
알고리즘이나 시스템 방식을 수정하는 방식으로 최적화를 하는 것이 좋다. 

*/


int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl; 
	cout << min(3, 2) << endl; 

	//inline 함수 사용 시 내부적으로는 아래와 같이 작동 
	cout << (5 > 6 ? 6 : 5) << endl; 
	cout << (3 > 2 ? 2 : 3) << endl;

	return 0;
}