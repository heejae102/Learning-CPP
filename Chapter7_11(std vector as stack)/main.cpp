#include<iostream>
#include<vector>
using namespace std; 

/*

	<����>

	size : �� �߿��� size��ŭ ����Ѵ�.

	capacity : ���� �޸𸮴� capacity��ŭ ������ �ִ�.

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

	////���� ������ �Ҵ�� ������ ũ�⺸�� ū ������� resize�� ��� 
	////size�� capacity ��� �� ū ������� ����ǰ�,
	////���� �������� ���� ���� ������ ��� 0���� �ʱ�ȭ 
	//v.resize(10);

	////������ �Ҵ�� ������ ũ�⺸�� ���� ������� resize�� ��� 
	////capacity�� ���� ������ ũ�⸦ ������ ä�� size�� resize�� ������ ����
	////capacity���� ���� ������ size�� �Ѿ ������ ���� �����Ϸ��� �ϸ� ���� �߻� 
	//v.resize(2);

	//for (auto &e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl; 

	//cout << v.size() << " " << v.capacity() << endl; 


	////----------------------------------------------------------------------//


	////reserve 

	////�޸𸮸� �Ҵ��Ͽ� capacity�� �÷����� ������� �ʴ� ���� 

	////���ͷ� ����ϰ� �޸𸮸� �Ҵ�/�����ϴ� ��� reserve�� ����ϰ� ��
	////�ִ� �޸� ������ �����س�����, �޸𸮸� �Ҵ�/���� �ϸ鼭 �޸𸮸� �����ϴ� ��
	////����� ���ʿ��� ������ ���� �� �־ �����ս��� ���� �� �ִ�. 

	//v.reserve(1024);

	//for (auto &e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//cout << v.size() << " " << v.capacity() << endl;


	//----------------------------------------------------------------------//


	//������ reserve�� �̿��Ͽ� ����ó�� ����ϱ� 
	
	//���͸� ����ϸ鼭 reserve�� ������ �����س��� push back�� �ϸ� 
	//capacity�� ���� �ø� �ʿ䰡 ���� ������ new, delete�� ȣ������ �ʾƼ� 
	//ȿ���� �� ����. �ݴ�� push pop�� �ص� capacity�� ������ ä�� ����� �پ���. 
	//��, reserve�� �ʹ� ū ũ�⸦ ��Ƴ��� ��� capacity�� �ʹ� Ŀ�� 
	//�޸𸮰� ����� ������ ������, �����͸� �ٷ��� �ʴ� �Ϲ����� ��쿡�� ū ������ ����. 

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