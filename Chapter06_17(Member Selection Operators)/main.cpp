#include<iostream>
using namespace std; 

struct Person
{
	int age;
	double weight; 
};

int main()
{
	// 포인터와 참조의 멤버 선택 연산자 

	Person person;
	person.age = 5;
	person.weight = 30;

	// 구조체도 래퍼런스형으로 선언하여 참조 가능 
	Person &ref = person;
	ref.age = 15;

	// 단, 포인터로 구조체를 참조하는 경우 ->를 통해 각원소에 접근
	//역참조하여 . 을 통해 접근하는 것은 가능 
	Person *ptr = &person;
	ptr->age = 30;

	//.연산자가 *연산자보다 우선순위가 높으므로 괄호를 사용해야 함.
	(*ptr).age = 20;

	//래퍼런스를 통해 포인터가 참조하는 대상을 참조하는 것도 가능
	Person &ref2 = *ptr;
	ref2.age = 50;

	cout << &person << endl; 
	cout << ptr << endl; 
	cout << &ref2 << endl; 

	return 0;
}