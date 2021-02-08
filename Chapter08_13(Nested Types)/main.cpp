#include<iostream>
using namespace std; 

/*

<Ŭ���� �ȿ� ���Ե� �ڷ���> Nested Types

Ŭ���� �ȿ� ���ԵǾ� �ִ� �ڷ���. 
���� ��� FruitType �̶�� enum�� �ڷ����� 
�ٸ� �������� ������� �ʰ� Fruit ��ü �������� ����� ��� 
�ش� ��ü ������ �����ؼ� ����� �� �ִ�. 

�ٸ� ��ü�鵵 �Բ� ����ؾ� �ϴ� �ڷ����� ��� �ٱ��� ������, Ÿ ��ü��κ��͵� 
���� �����ϰ� �����ϴ� ���� ������ Ư�� ��ü �������� ���Ǵ� �ڷ����� ��� 
�ش� ��ü ������ �����ؼ� ����ϴ� �͵� ���� ���. �ֱٿ��� �ش� ����� ���� ���. 

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
	// Ŭ���� �� �ڷ������� ���� �� ��� Ŭ���� ���ӽ����̽��� ����Ͽ� ȣ�� 
	Fruit apple(Fruit::APPLE);

	if (apple.getType() == Fruit::BANANA)
	{
		cout << "Banana" << endl; 
	}

	return 0;
}