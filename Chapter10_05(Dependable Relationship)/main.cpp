#include "Worker.h"
using namespace std; 

/*

<의존 관계>

가장 빈번하게 사용할 수 있는 클래스 관계. 

main 함수 내에서도 Worker 헤더파일만 추가해서 사용 가능하다. 
Worker 객체 내에서 Timer를 멤버로 사용하지 않기 때문에 
해당 객체를 사용하는 함수레벨에서만 Timer 객체를 인식하면 되므로
이전의 다른 클래스 관계에 비해 가장 느슨한 관계라고 할 수 있다. 

*/

int main()
{
	Worker().doSomething();

	return 0;
}