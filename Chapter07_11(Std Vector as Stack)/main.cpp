#include<iostream>
#include<vector>
using namespace std; 

/*

	<벡터>

	size : 그 중에서 size만큼 사용한다.

	capacity : 실제 메모리는 capacity만큼 가지고 있다.

*/

void printStack(const vector<int> &stack)
{
	for (const auto &element : stack)
	{
		cout << element << " ";
	}
	cout << endl; 
}

int main()
{
	//vector<int> v{ 1,2,3 };

	////resize 

	////원래 기존에 할당된 원소의 크기보다 큰 사이즈로 resize할 경우 
	////size와 capacity 모두 더 큰 사이즈로 변경되고,
	////값이 설정되지 않은 원소 값들은 모두 0으로 초기화 
	//v.resize(10);

	////기존에 할당된 원소의 크기보다 작은 사이즈로 resize할 경우 
	////capacity는 원래 원소의 크기를 유지한 채로 size만 resize한 값으로 변경
	////capacity범위 내에 있지만 size를 넘어선 원소의 값에 접근하려고 하면 오류 발생 
	//v.resize(2);

	//for (auto &e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl; 

	//cout << v.size() << " " << v.capacity() << endl; 


	////----------------------------------------------------------------------//


	////reserve 

	////메모리만 할당하여 capacity를 늘려놓고 사용하지 않는 상태 

	////벡터로 빈번하게 메모리를 할당/해제하는 경우 reserve로 사용하게 될
	////최대 메모리 영역을 지정해놓으면, 메모리를 할당/해제 하면서 메모리를 복사하는 데
	////생기는 불필요한 연산을 줄일 수 있어서 퍼포먼스를 높일 수 있다. 

	//v.reserve(1024);

	//for (auto &e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//cout << v.size() << " " << v.capacity() << endl;


	//----------------------------------------------------------------------//


	//벡터의 reserve를 이용하여 스택처럼 사용하기 
	
	//벡터를 사용하면서 reserve로 영역을 지정해놓고 push back을 하면 
	//capacity를 따로 늘릴 필요가 없기 때문에 new, delete를 호출하지 않아서 
	//효율이 더 좋다. 반대로 push pop을 해도 capacity는 유지한 채로 사이즈만 줄어든다. 
	//단, reserve로 너무 큰 크기를 잡아놓은 경우 capacity가 너무 커서 
	//메모리가 낭비될 여지가 있으나, 빅데이터를 다루지 않는 일반적인 경우에는 큰 문제가 없다. 

	vector<int> stack;

	stack.reserve(1024);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0; 
}