#include<iostream>
#include<string>
using namespace std; 

/*

<다형성>

자식 클래스의 객체에 부모 클래스의 
포인터를 사용한다면 어떻게 될까? 

*/

class Animal
{
protected:
	string _name; 

public:
	Animal(std::string name_in)
		: _name(name_in) {}

	std::string getName() { return _name; }

	// 포인터로 상속받은 객체를 가리킬 때, 실제로 가리키는 객체의 타입을 기준으로 호출
	virtual void speak() const
	{
		cout << _name << " ??? " << endl; 
	}
};

class Cat : public Animal
{
public:
	Cat(std::string name_in)
		: Animal(name_in) {}

	void speak() const
	{
		cout << _name << " Meow " << endl; 
	}
};

class Dog : public Animal
{
public:
	Dog(std::string name_in)
		: Animal(name_in) {}

	void speak() const
	{
		cout << _name << " Woof " << endl; 
	}
};

int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	//=================================================================//

	// 자식 클래스를 부모 클래스의 포인터로 가리키는 경우 
	// 자식 클래스가 부모 클래스처럼 캐스팅되어 해당 포인터로 
	// 멤버에 접근 시, 자식 클래스 내 멤버가 아닌 부모 클래스 내 멤버를 호출 

	Animal *ptr_animal1 = &cat; 
	Animal *ptr_animal2 = &dog; 

	ptr_animal1->speak();
	ptr_animal2->speak();

	//=================================================================//

	// 이러한 성질을 이용하여 여러 개의 하위 클래스를 편리하게 관리 가능 

	// 여러 타입의 하위 클래스에 접근해야 할 때 
	// 일일이 해당 타입으로 접근해야 하는 경우 작업이 번거로워짐. 

	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; i++)
		cats[i].speak();

	for (int i = 0; i < 2; i++)
		dogs[i].speak();


	// 반면 여러 타입의 자식 클래스를 부모 클래스의 포인터에 담아서 접근하면,
	// 하나의 데이터 타입으로 다양한 하위 클래스에 접근 가능 

	// ※ 포인터 타입으로 인해 하위 클래스의 멤버가 
	// 부모 클래스의 멤버를 호출하는 것이 문제가 될 경우, 
	// 해당 부모 클래스의 멤버에 virtual 키워드를 사용하면 
	// 포인터가 가리키는 실제 객체(하위 클래스)를 기준으로 호출하게 된다. 

	Animal *my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
							 &dogs[0], &dogs[1] };

	for (int i = 0; i < 7; i++)
		my_animals[i]->speak();

	return 0; 
}