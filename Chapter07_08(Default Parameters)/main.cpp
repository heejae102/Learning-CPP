#include<iostream>
using namespace std; 

/*

<디폴트 매개변수> 
= default parameter, optional parameter, default argument

별개의 매개변수가 입력되지 않는 경우 사용되는 디폴트 매개변수
매개변수가 여러개일 때도 디폴트 매개변수를 사용할 수 있으나,
매개변수가 복수인 경우 디폴트 매개변수는 가장 오른쪽에서부터 순차적으로 기입되어야 한다. 
(중간에 건너뛰거나 왼쪽부터 기입하면 안됨.)

※ 주의사항1.
함수의 선언과 정의가 분리되어있는 경우,
디폴트 매개변수는 둘 중 한 쪽에서만 사용되어야 한다. 
함수의 선언에서 디폴트 매개변수를 사용한 경우 
정의에서는 사용해선 안되고, 반대의 경우도 마찬가지이다. 
보통은 헤더파일의 함수의 선언에 디폴트 매개변수를 기입한다.
(함수들을 리뷰할 경우 헤더파일을 보기 때문)

※ 주의사항2.
함수를 오버로딩하여 디폴트 매개변수를 사용할 때, 
매개변수의 개수가 다름에도 불구하고 디폴트 매개변수가 있기 때문에
함수 호출 시에 ambiguity 오류가 발생할 수 있는 경우가 있다. 
따라서 함수를 오버로딩하는 경우 디폴트 매개변수를 사용하는 데 주의 필요. 

*/

void print(int x, int y = 10, int z = 20)
{
	cout << x << ' ' << y << ' ' << z << endl;
}

void printStr(string str) {}
void printStr(char ch = 'abc') {}

//두 함수는 매개변수의 개수가 다르지만, 2번째 함수에 디폴트 매개변수가 하나 
//설정되어있기 때문에 결론적으로 인자값을 하나만 받아도 되는 함수이다.
//즉, 두 개의 함수 모두 인자 값을 하나만 받아도 되는 함수이기 때문에 
//인자를 하나만 넘기면서 함수를 호출할 경우 ambiguous call 오류가 발생 
void ambiguous(int x) {}
void ambiguous(int x, int y = 20) {}

int main()
{
	print(0);
	print(1, 2);
	print(1, 2, 3);

	//------------------------------------------------------------------//


	//printStr 함수는 비슷한 매개변수를 받지만, char형으로 매개변수를 받는
	//함수 쪽에 디폴트 매개변수가 설정되어 있으므로 매개변수로 넘기는 인자 값이
	//없는 경우 해당 함수를 실행하게 됨. 
	printStr();


	//------------------------------------------------------------------//


	//오버로딩된 함수 중 두 개 이상이 인수 목록과 일치 
	//ambiguous(10);


	return 0;
}