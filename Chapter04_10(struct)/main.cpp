#include<iostream>
#include<string>
using namespace std; 

// struct  
// 연관 있는 데이터를 한데 묶어서 편리하게 사용할 수 있는 사용자 정의 자료형
// 데이터 뿐만 아니라 함수, 같은 구조체도 멤버로 들어갈 수 있다. 
// 함수의 파라미터나 리턴 타입으로도 들어갈 수 있다.
// 구조체 내에서도 값을 정의해줄 수 있으나, 변수를 직접 선언하여 값을 재정의할 경우 
// 재정의한 값으로 최종 값이 저장됨. 

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

struct Employee		// 2 + (2) + 4 + 8 = 16 // 2바이트가 추가되는 것을 padding이라고 부름.
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

	//초기화방법1
	Person me{ 165., 55.f, 20, "Jane Doe" };
	
	//초기화방법2
	me.height = 165.;
	me.weight = 55.f;
	me.age = 20; 
	me.name = "Jane Doe";

	//구조체 내의 멤버에 접근할 때는 .을 사용해서 접근 
	//printPerson(me);
	//me.print();

	//복사 가능
	//하지만 멤버 데이터의 종류(구조체, 객체 등)가 다양해지고 복잡해지면서 
	//대입 연산자가 예측하지 못한 방식으로 작동할 수 있음. 
	//가급적 간단한 구조의 구조체에서만 사용할 것 
	//Person copy;
	//copy = me; 

	//Person copy = me; 
	//copy.print();

	//Person me_from_func = getMe();
	//me_from_func.print();

	//data structure alinement 
	//각각의 데이터만 따지고보면 14바이트가 나와야 하지만 16바이트가 나옴. 
	//데이터를 배치하는 방식에 의해서 예상하는 메모리 크기와 다른 값이 나올 수 있음.  
	//이렇게 낭비(padding)되는 메모리가 없도록 메모리 순서나
	//사이즈를 잘 맞추면 최적화하는 데 도움. 

	Employee emp1;
	cout << sizeof(emp1) << endl; 

	

}