#include<iostream>
#include<string>
using namespace std; 

/*

<���� ������> Delegating Constructors 

�����ڰ� �ٸ� �����ڸ� ����ϴ� ��. 

*/

class Student
{
private:
	int _id; 
	string _name; 

public:
	//���1. �ֱ� C++ �������� ���Ե� ���� 
	Student(const string &name_in)
		//: _id(0), _name(name_in) {}	// �����ϱ� �����ϰ� ���������� ���� ���� ���� 
		: Student(0, name_in) {}

	//���2. �̷��� ����� �� ��õ�ϱ⵵ ��. 
	void init(const int &id_in, const string &name_in)
	{
		_id = id_in;
		_name = name_in;
	}

	Student(const int &id_in, const string &name_in)
		//: _id(id_in), _name(name_in)
	{
		init(id_in, name_in);
	}

	void print()
	{
		cout << _id << " " << _name << endl; 
	}
};

int main()
{
	Student st1(1, "Violet");
	st1.print();

	Student st2("Violet");
	st2.print();

	return 0;
}