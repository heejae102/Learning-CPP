#include<iostream>
#include<string>
using namespace std; 

/*

<������>

�ڽ� Ŭ������ ��ü�� �θ� Ŭ������ 
�����͸� ����Ѵٸ� ��� �ɱ�? 

*/

class Animal
{
protected:
	string _name; 

public:
	Animal(std::string name_in)
		: _name(name_in) {}

	std::string getName() { return _name; }

	// �����ͷ� ��ӹ��� ��ü�� ����ų ��, ������ ����Ű�� ��ü�� Ÿ���� �������� ȣ��
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

	// �ڽ� Ŭ������ �θ� Ŭ������ �����ͷ� ����Ű�� ��� 
	// �ڽ� Ŭ������ �θ� Ŭ����ó�� ĳ���õǾ� �ش� �����ͷ� 
	// ����� ���� ��, �ڽ� Ŭ���� �� ����� �ƴ� �θ� Ŭ���� �� ����� ȣ�� 

	Animal *ptr_animal1 = &cat; 
	Animal *ptr_animal2 = &dog; 

	ptr_animal1->speak();
	ptr_animal2->speak();

	//=================================================================//

	// �̷��� ������ �̿��Ͽ� ���� ���� ���� Ŭ������ ���ϰ� ���� ���� 

	// ���� Ÿ���� ���� Ŭ������ �����ؾ� �� �� 
	// ������ �ش� Ÿ������ �����ؾ� �ϴ� ��� �۾��� ���ŷο���. 

	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; i++)
		cats[i].speak();

	for (int i = 0; i < 2; i++)
		dogs[i].speak();


	// �ݸ� ���� Ÿ���� �ڽ� Ŭ������ �θ� Ŭ������ �����Ϳ� ��Ƽ� �����ϸ�,
	// �ϳ��� ������ Ÿ������ �پ��� ���� Ŭ������ ���� ���� 

	// �� ������ Ÿ������ ���� ���� Ŭ������ ����� 
	// �θ� Ŭ������ ����� ȣ���ϴ� ���� ������ �� ���, 
	// �ش� �θ� Ŭ������ ����� virtual Ű���带 ����ϸ� 
	// �����Ͱ� ����Ű�� ���� ��ü(���� Ŭ����)�� �������� ȣ���ϰ� �ȴ�. 

	Animal *my_animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
							 &dogs[0], &dogs[1] };

	for (int i = 0; i < 7; i++)
		my_animals[i]->speak();

	return 0; 
}