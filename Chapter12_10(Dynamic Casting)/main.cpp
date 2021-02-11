#include<iostream>
#include<string>
using namespace std;

/*

<���� ����ȯ>

*/

class Base
{
public:
	int _i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl; 
	}
};

class Derived1 : public Base
{
public:
	int _j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl; 
	}
};

class Derived2 : public Base
{
public :
	string _name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl; 
	}
};

int main()
{
	Derived1 d1;
	Base *base = &d1;

	// base�� d1�� �޸� Derived1���� �ִ� ����� ���� �Ұ��� 
	// �� base�� �ٽ� Derived1 ������ Ÿ������ ����ȯ�Ͽ� ���� ����  

	auto *base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->_j << endl; 

	// �ش� �����͸� ���� �������� ���� ���� ���� 
	// ������ �̷��� ����ȯ���� �Դٰ����ϴ� ���� ����� �ÿ��� �˾ƺ��� �����
	// �ڵ� ��ü�� �����ϰ� ����� ������ ������ virtual - override�� �ذ��ϴ� ���� ����. 
	
	base_to_d1->_j = 512;
	cout << d1._j << endl; 

	/*
	
	d1�� ���ʿ� Derived1 Ÿ���� ��ü�����Ƿ�, �̸� Derived2�� 
	dynamic cast �Ϸ��� �� ��� ĳ���ÿ� �����Ͽ� NULL �����Ͱ� ��ȯ�ȴ�. 

	�ݸ� static cast �� ���� ĳ���� �� ���, ĳ���� ��ü�� �����Ѵ�.
	������ �ᱹ �����ʹ� Derived1 ��ü�� ä�� ĳ���ø� ������ ���̱� ������,
	Derived2 ��ü�� ���� �����Ϳ� �����Ϸ��� �ϸ� ������ �߻��Ѵ�. 

	����, ������ ��� ���迡�� ����ȯ�� ���ϴ� ���� ������, 
	�ʿ��� ��Ȳ�� ���� ��쿡�� dynamic cast �� ����Ͽ� ������ �߻��ϴ� ����
	������ �����ϴ� ���� ����. 
	
	*/
	
	//auto *base_to_d2 = dynamic_cast<Derived2*>(base);
	auto *base_to_d2 = static_cast<Derived2*>(base);

	if (base_to_d2 == nullptr) cout << "Casting Failed" << endl; 
	else cout << base_to_d2->_name << endl;

	return 0;
}