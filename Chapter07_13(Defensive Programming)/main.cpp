#include<iostream>
using namespace std; 

/*

<방어적 프로그래밍>

syntax error  : 문법적 오류. 컴파일러에 의존해서 정정 가능

semantic error: 문맥적 오류. 프로그래밍 언어적으로는 오류가 없으나
의도하는 바와 다르게 논리적인 오류를 범하는 경우 

violated assumption : 가정된 입력범위를 넘어간 값이 입력되는 등의 오류

*/

int main()
{
	//violated assuption 

	string hello = "Hello, my name is violet";

	cout << "Input from 0 to " << hello.size() << endl;

	while (1)
	{
		int idx;
		cin >> idx;

		if (idx >= 0 && idx <= hello.size())
		{
			cout << hello[idx] << endl; 
			break;
		}
		else cout << "Please try again" << endl; 
	}


	return 0;
}