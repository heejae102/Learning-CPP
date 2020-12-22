#include<iostream>
#include<string>
#include<vector>
using namespace std; 

/*

<객제지향과 프로그래밍과 클래스> 

데이터와 기능을 묶어놓은 것을 오브젝트(객체)라고 부른다. 

객체를 프로그래밍 언어로서 구현하는 키워드가 클래스. 
즉, 클래스는 오브젝트(객체)라는 개념을 문법으로 구현할 때 사용하는 것. 

구조체에도 데이터와 함수를 넣을 수 있지만, 
클래스는 좀 더 객체지향적인 프로그래밍을 도와준다.
일반적으로 구조체는 데이터만 집어넣는 방식으로 사용한다. 
(C 언어에서 구조체는 함수를 포함하지는 못할 것)

정의해놓은 객체를 실제 메모리 상에서 사용할 수 있도록 
선언하는 것(변수화)을 인스턴스화(instanciation)라고 하며, 
해당 객체 변수를 인스턴스(instance)라고 부른다. 

객체지향적 프로그래밍을 사용하면 코드가 간결해지고 
전체적인 코드의 볼륨이 줄어들면서 그만큼 오류가 발생할 확률을 줄여준다.

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