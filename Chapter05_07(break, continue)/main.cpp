#include<iostream>
using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch; 
		cin >> ch; 

		if (ch == 'b') break; 

		if (ch == 'r') return; 
	}

	cout << "Hello" << endl; 
}

int main()
{
	//breakOrReturn();

	//for (int i = 0; i < 10; i++)
	//{
	//	if (i % 2 == 0) continue; 
	//	cout << i << endl; 
	//}

	int count(0);

	//do
	//{
	//	if (count == 5) continue; 

	//	cout << count << endl; 
	//	
	//	//이 상황에서 count++;이 do-while문 내부에 있으면
	//	//continue로 인해 변수에 값을 더해주지 않고
	//	//조건식으로 바로 이동하기 때문에 무한루프에 빠지게 됨. 
	//	//count++;

	//} while (count++ < 10);

	while (true)
	{
		char ch; 
		cin >> ch; 

		cout << ch << " " << count << endl; 
		count++;

		if (ch == 'x') break; 
	}

	return 0; 
}