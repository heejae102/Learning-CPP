#pragma once

/*

<의존 관계>

Worker - Timer

Worker 객체 내의 doSomething 함수 내에서 Timer 객체를 사용하고 있지만, 
Worker 클래스 내에서는 이에 대해 알 필요가 없으며, 실제로 헤더 파일 
내에 타이머 헤더 파일을 include하지 않았지만 doSomething 함수를 사용하는 데 문제가 없다. 

이렇듯 의존 관계에서는 클래스 레벨에서 서로의 존재를 알 필요는 없다. 
함수의 정의 단계에서만 사용이 되므로 .cpp 파일에만 헤더 파일을 추가하면 되기 때문. 

*/

class Worker
{
public:
	void doSomething();

};

