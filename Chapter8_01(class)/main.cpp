#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*

<��������� ���α׷��ְ� Ŭ����> 

�����Ϳ� ����� ������� ���� ������Ʈ(��ü)��� �θ���. 

��ü�� ���α׷��� ���μ� �����ϴ� Ű���尡 Ŭ����. 
��, Ŭ������ ������Ʈ(��ü)��� ������ �������� ������ �� ����ϴ� ��. 

����ü���� �����Ϳ� �Լ��� ���� �� ������, 
Ŭ������ �� �� ��ü�������� ���α׷����� �����ش�.
�Ϲ������� ����ü�� �����͸� ����ִ� ������� ����Ѵ�. 
(C ���� ����ü�� �Լ��� ���������� ���� ��)

�����س��� ��ü�� ���� �޸� �󿡼� ����� �� �ֵ��� 
�����ϴ� ��(����ȭ)�� �ν��Ͻ�ȭ(instanciation)��� �ϸ�, 
�ش� ��ü ������ �ν��Ͻ�(instance)��� �θ���. 

��ü������ ���α׷����� ����ϸ� �ڵ尡 ���������� 
��ü���� �ڵ��� ������ �پ��鼭 �׸�ŭ ������ �߻��� Ȯ���� �ٿ��ش�.

*/

// Friend : name, address, age, heiht, weight...

class Friend
{
public: // access specifier (public, private, protected)
	string _name;
	string address;
	int age;
	double height; 
	double weight; 

	void print()
	{
		cout << _name << " " << address << " " << age <<
			" " << height << " " << weight << endl; 
	}
};

void print(const string &name, const string &address, const int &age,
	const double &height, const double &weight)
{
	cout << name << " " << address << " " << age << " " <<
		height << " " << weight << endl; 
}


int main()
{
	Friend jj{ "Jack Jack", "Uptown", 2, 30, 10 };

	jj.print();

	vector<Friend> my_friends;
	my_friends.resize(2);

	for (auto &element : my_friends)
	{
		element.print();
	}


	//string name; 
	//string address; 
	//int age; 
	//double height;
	//double weight; 

	return 0;
}