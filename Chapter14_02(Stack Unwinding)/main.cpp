#include<iostream>
using namespace std; 

/*

<예외처리와 스택 되감기>

함수가 어떠한 함수를 호출하고, 
그 함수가 또 다른 함수를 호출한다면 
스택의 호출구조가 차례대로 쌓여나갈 것. 

만약 가장 안 쪽에 있는 함수가 예외를 던진다면
스택을 되감아가면서 어디서 예외를 받을 지 찾게 된다.

※ 예외 던지기를 한 이후, 해당 예외를 catch 하지 못하고 되감기를 하는 경우
해당 함수 내에 있는 명령은 무시하고 이전의 스택으로 되감기 
해당 예외를 catch한 이후에만 정상적으로 함수가 작동하게 된다.

만약 throw한 자료형과 일치하는 catch 문이 존재하지 않을 경우, 런타임 에러 발생 

*/


// 함수명 뒤에 throw(자료형) -> 해당 자료형을 throw 할 수도 있다는 것을 명시
// 하지만 마이크로소프트에서는 특정 자료형에 대한 것보다는 throw한다는 사실을 주로 기억 
// 일반적으로 잘 쓰이는 문법은 아니다. 
// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void last() /*throw()*/	// throw() 괄호 안을 비울 경우 throw 함수를 사용하지 않는다는 의미 
{
	cout << "Last" << endl;
	cout << "Throws exeption" << endl;

	// 1. throw 예외 던지기를 했으므로 그 이후의 명령은 무시하고 되감기 시작 
	throw - 1;

	cout << "End last" << endl;
}

//void last()
//{
//	cout << "Last" << endl; 
//	cout << "Throws exeption" << endl; 
//
//	// 1. throw 예외 던지기를 했으므로 그 이후의 명령은 무시하고 되감기 시작 
//	throw - 1;
//
//	cout << "End last" << endl; 
//}

void third()
{
	// 2. 되감기를 통해 last 함수에서 왔지만, catch문이 없으므로 다시 되감기 

	cout << "Third" << endl; 

	last();

	cout << "End third" << endl; 
}

void second()
{
	// 3. 되감기를 통해 third 함수에서 왔고 catch 문이 존재하지만,
	// -1(int) 을 throw 했으므로 double 자료형과 일치하지 않아 다시 되감기 

	cout << "Second" << endl; 

	try
	{
		third();
	}

	catch (double)
	{
		cerr << "Second caught double exception" << endl; 
	}

	cout << "End second" << endl; 
}

void first()
{
	// 4. 되감기를 통해 second 함수에서 왔고 catch 문이 존재하면서,
	// throw 한 값과 catch 문의 자료형이 일치하기 때문에 catch 문의 명령 실행 
	// 예외를 catch 했으므로 해당 함수의 나머지 명령 역시 정상적으로 실행 

	cout << "First" << endl; 

	try
	{
		second();
	}

	catch (int)
	{
		cerr << "First caught int exception" << endl; 
	}

	cout << "End first" << endl; 
}

int main()
{
	cout << "Start" << endl; 

	try
	{
		first();
	}

	catch (int)
	{
		// cerr : cout 함수와 기능상 비슷한 함수 
		cerr << "main caught int exception" << endl; 
	}

	// 모든 자료형을 다 받을 수 있는 catch 
	catch (...)	// catch-all handlers
	{
		cerr << "main caught ellipsis exception" << endl; 
	}

	// uncaught exceptions

	cout << "End main" << endl; 

	return 0;
}