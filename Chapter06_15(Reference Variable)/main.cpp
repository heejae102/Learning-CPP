#include<iostream>
using namespace std; 

void doSomething(int &num)
{
	cout << "doSomething : " << &num << endl; 

	num = 10; 
	cout << "In doSomething " << num << endl;
}

//�迭�� ���۷��� �������� �Ķ���͸� ���� �� �ִ�.
//��, �迭�� ����� �ݵ�� �����ؾ� �Ѵ�. 
void printElements(int (&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl; 
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st; 
};

int main()
{
	//���� ���� 

	//int value = 5;

	//int *ptr = nullptr;
	//ptr = &value;

	////���� ������ �ٸ� ������ ������ �޾ƿ��� ������ �޸𸮸� �����ϴ� ��ó��
	////ref�� valueó�� �ش� ������ �ٸ� ��Īó�� ��� ���� 
	//int &ref = value; 

	////���� �����ϴ� �ͻ� �ƴ϶� �����ϴ� �͵� ���� 
	//cout << ref << endl; 
	//ref = 10;
	//cout << value << " " << ref << endl; 

	////���� ������ �ڱ� �ڽ��� ���� �ּҸ� ������ ���� �ƴ϶�, 
	////�����ϴ� �޸��� �ּҿ� ������ �ּҸ� ������. 
	//cout << &ref << endl; 
	//cout << &value << endl; 
	//cout << ptr << endl; 

	////�ٸ� �����ϴ� ���� ���Ҵ��ϴ� �͵� ����������, 
	////�ּҴ� ó���� �ο��� ���� ������ �ּҿ� ���� 
	//int value2 = 20;
	//ref = value2;

	//cout << ref << endl; 
	//cout << &ref << endl; 
	//cout << &value2 << endl; 


	////���� ������ ���ͷ� ���� �ްų�, ���ͷ�ȭ �� ������ ���� �� ����.
	////���ͷ��� �������� �޸� �ּҸ� ������ ���ϰ�, 
	////���ͷ�ȭ �� ������ ������ �ش� ���� ���� ������ ������ �ֱ� ����. 
	////������ ��� ���۷����� const������ �����ؼ� ����ϸ� ���� 
	//
	//const int var = 123;
	////int &reference = 123;  //(X)
	////int &reference = var;  //(X)
	//const int &reference = var; 

	//���� �Լ��� �Ķ���ͷ� �ѱ�� �Լ� ������ �ش� ������ ����
	//�����ص� ���� ������ ������ ������ ��ġ�� �ʴ´�. 

	//but, ���۷����� �Ķ���͸� ���� ��� �ش� ������ �״�� �ѱ�� ������,
	//���۷����� �Ķ���͸� �޾� ���� �����Ű�� ���� ������ ���� ����ȴ�. 
	//�ּ� ���� ����ϸ� ���� ������ �Լ� �� ���۷��� ������ �ּ� ���� ��ġ 

	//�� �����ͷ� �Ķ���� ���� �ѱ� ��� ������ ������ �Ѱ��� ������ �ּ� ����
	//�����ؼ� �־���ϹǷ� ������ ������ ������ �ϳ� �ʿ�������, 
	//���۷����� ����� ��� �ش� ������ �״�� �Ѿ���Ƿ� ���簡 �ʿ� ����.
	//���� �����ս����� ���鿡���� �����ͺ��� ������ ���

	//���۷����� �Ķ���͸� ������ ���� �����ϰ� ���� ���� ��� const�� ����

	int num = 5;

	cout << num << endl; 
	cout << "main num : " << &num << endl; 

	doSomething(num);

	cout << num << endl; 

	//////////////////////////////////////

	//��ü�� ����ü�� ����ؼ� �̸��� ����� ��쿡 ���۷����� 
	//�޾Ƽ� ����ϸ� �����ϴ�. 

	Other ot;

	//�����ϱ���� ���ľ� �ϴ� �͵��� ����...
	ot.st.v1 = 1.0;

	//���۷��� ������ ��Ƽ� ª�� �����ϰ� ��밡�� 
	//ȿ������ ���鿡���� �ӵ��� �������� �ʱ� ������ ����.
	int &v1 = ot.st.v1;


	//���۷����� ������ �� 
	//const�� �����Ϳ� ��ɻ� �����ϴٰ� �� �� �ִ�. 
	int value = 5;
	int *const ptr = &value;
	int &ref = value;

	*ptr = 10;
	ref = 10;

	return 0; 
}