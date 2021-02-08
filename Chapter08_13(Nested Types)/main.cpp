#include<iostream>
using namespace std; 

/*

<클래스 안에 포함된 자료형> Nested Types

클래스 안에 포함되어 있는 자료형. 
예를 들어 FruitType 이라는 enum형 자료형을 
다른 곳에서는 사용하지 않고 Fruit 객체 내에서만 사용할 경우 
해당 객체 내에서 선언해서 사용할 수 있다. 

다른 객체들도 함께 사용해야 하는 자료형의 경우 바깥에 빼놓고, 타 객체들로부터도 
접근 가능하게 선언하는 것이 좋지만 특정 객체 내에서만 사용되는 자료형의 경우 
해당 객체 내에서 선언해서 사용하는 것도 좋은 방법. 최근에는 해당 방법도 많이 사용. 

*/

enum FruitType
{
	APPLE,
	BANNA,
	CHERRY,
};

class Fruit
{
public:
	enum FruitType
	{
		APPLE,
		BANANA,
		CHERRY,
	};

	class InnerClass
	{

	};

	struct InnerStruct
	{

	};

private:
	FruitType m_type; 

public:
	Fruit(FruitType type) :m_type(type) {}

	FruitType getType() { return m_type; }
};

int main()
{
	// 클래스 내 자료형으로 선언 한 경우 클래스 네임스페이스를 사용하여 호출 
	Fruit apple(Fruit::APPLE);

	if (apple.getType() == Fruit::BANANA)
	{
		cout << "Banana" << endl; 
	}

	return 0;
}