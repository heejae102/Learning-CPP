#include<iostream>
#include<string>
using namespace std; 

// struct  
// ���� �ִ� �����͸� �ѵ� ��� ���ϰ� ����� �� �ִ� ����� ���� �ڷ���
// ������ �Ӹ� �ƴ϶� �Լ�, ���� ����ü�� ����� �� �� �ִ�. 
// �Լ��� �Ķ���ͳ� ���� Ÿ�����ε� �� �� �ִ�.
// ����ü �������� ���� �������� �� ������, ������ ���� �����Ͽ� ���� �������� ��� 
// �������� ������ ���� ���� �����. 

struct Person
{
	double height = 160.;
	float weight = 50.f;
	int age = 20;
	string name = "Jenny Doe"; 

	void print()
	{
		cout << height << " " << weight << " " << age << " " << name << endl; 
	}
};

struct Family
{
	Person me, mom, dad; 
};

struct Employee		// 2 + (2) + 4 + 8 = 16 // 2����Ʈ�� �߰��Ǵ� ���� padding�̶�� �θ�.
{
	short id;		// 2 bytes
	int age;		// 4 bytes 
	double wage;	// 8 bytes
};

Person getMe()
{
	Person me{ 165., 55.f, 20, "Jane Doe" };

	return me; 
}

void printPerson(Person &person)
{
	cout << person.height << " " << person.weight << " " << person.age << " " << person.name << endl; 
}

int main()
{
	//double height; 
	//float weight; 
	//int age;
	//string name; 

	//�ʱ�ȭ���1
	Person me{ 165., 55.f, 20, "Jane Doe" };
	
	//�ʱ�ȭ���2
	me.height = 165.;
	me.weight = 55.f;
	me.age = 20; 
	me.name = "Jane Doe";

	//����ü ���� ����� ������ ���� .�� ����ؼ� ���� 
	//printPerson(me);
	//me.print();

	//���� ����
	//������ ��� �������� ����(����ü, ��ü ��)�� �پ������� ���������鼭 
	//���� �����ڰ� �������� ���� ������� �۵��� �� ����. 
	//������ ������ ������ ����ü������ ����� �� 
	//Person copy;
	//copy = me; 

	//Person copy = me; 
	//copy.print();

	//Person me_from_func = getMe();
	//me_from_func.print();

	//data structure alinement 
	//������ �����͸� �������� 14����Ʈ�� ���;� ������ 16����Ʈ�� ����. 
	//�����͸� ��ġ�ϴ� ��Ŀ� ���ؼ� �����ϴ� �޸� ũ��� �ٸ� ���� ���� �� ����.  
	//�̷��� ����(padding)�Ǵ� �޸𸮰� ������ �޸� ������
	//����� �� ���߸� ����ȭ�ϴ� �� ����. 

	Employee emp1;
	cout << sizeof(emp1) << endl; 

	

}