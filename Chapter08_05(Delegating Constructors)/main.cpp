#include<iostream>
#include<string>
using namespace std; 

/*

<위임 생성자> Delegating Constructors 

생성자가 다른 생성자를 사용하는 것. 

*/

class Student
{
private:
	int _id; 
	string _name; 

public:
	//방법1. 최근 C++ 버전에서 도입된 문법 
	Student(const string &name_in)
		//: _id(0), _name(name_in) {}	// 수정하기 불편하고 문법적으로 좋지 못한 구조 
		: Student(0, name_in) {}

	//방법2. 이러한 방식을 더 추천하기도 함. 
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