#include<iostream>
using namespace std; 

int main()
{
	int x = 10;

	//null statement
	if (x > 10)
		;

	if (x > 10)
	{

	};

	//이렇게 될 경우 if문이 바로 종료되고 
	//괄호는 별개의 스코프로 작동해서 x = 1이 항상 실행
	if (x > 10);
	{
		x = 1;
	}

	//아래 괄호 안의 연산은 쪼개서 말하면 아래와 같다.
	//따라서 괄호 내에 0의 값이 들어가서 false이므로 if문 내 명령은 실행되지 X
	//x = 0;
	//if(x)

	if (x = 0)
	{
		cout << x << endl; 
	}
}
