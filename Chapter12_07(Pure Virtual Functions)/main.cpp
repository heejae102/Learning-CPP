#include<iostream>
#include<string>
using namespace std; 

/*

<���� ���� �Լ�, �߻� �⺻ Ŭ����, �������̽� Ŭ����>

1. ���� ���� �Լ� (Pure Virtual Functions)
���� ���� �Լ��� �ٵ� ���� �Լ���, �ڽ� Ŭ�������� 
�ݵ�� �������̵� ���־�� �ϴ� �Լ��̴�. 
(�ڽ� Ŭ�������� �������̵����� ������ ������ �� ���� �߻�)

���� �ٵ� ���ٴ� �������� ���鵵 ������,
Ŭ���� ���� �� ��� ������ �Ѳ����� ������ �� �ֵ��� �����ִ� ���� 

//========================================================================//

2. �߻� �⺻ Ŭ���� (Abstract Classes) 
���� ���� �Լ��� ���Ե� Ŭ������ �߻� Ŭ������� �θ���.

//========================================================================//

3. �������̽� Ŭ���� (Interface Classes)
���� ���� �Լ��θ� �̷���� Ŭ������ �������̽� Ŭ������� �θ���. 

*/

// 1. ���������Լ�-�߻� Ŭ���� ���� 
class Animal
{
protected:
	string _name;

public:
	Animal(std::string name)
		: _name(name) {}

public:
	string getName() { return _name; }

	virtual void speak() const = 0;		// ���������Լ�
};

// �Ʒ��� ���� ���������Լ��� �ٵ� ���� ���� �� ���� ������,  
// ���������Լ��� ��ӹ޴� �ڽ� ������ �ݵ�� �������̵��ؾ� �ϹǷ� (���� ������ ���� �߻�)
// ���� �����س��� �Լ��� ���� �������̵� �� �Լ��� ���� ��������Ƿ� �ǹ� X
void Animal::speak() const
{
	cout << _name << "???" << endl; 
}

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name) {}

	virtual void speak() const
	{
		cout << _name << " Mooo" << endl; 
	}
};

// 2. �������̽� Ŭ���� ���� 
class IErrorLog
{
public:
	// �⺻ Ŭ�������� ���� ���� �Լ��� �������� ���, 
	// �ڽ� Ŭ���������� �ݵ�� �ش� �Լ��� �����ؾ߸� ������ ���� 
	virtual bool reportError(const char *errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char *errorMessage) override
	{
		cout << "Writing error to a file" << endl; 
		return true; 
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char *errorMessage) override
	{
		cout << "Printing error to a console" << endl; 
		return true; 
	}
};

// �������̽� Ŭ������ ��ӹ޴� Ŭ�������� �������̽� Ŭ���� �Ķ���ͷ� �޾Ƽ� 
// ���� �Լ��� ȣ���ϸ� ��ӹ޴� Ŭ�������� �������̵� �� �Լ��� ȣ�� ��. 
// ������ �ٸ� �ڽ� Ŭ�������� ��� �⺻ Ŭ���� �Ķ���ͷ� ���� �� �����Ƿ� ����.  
void doSomething(IErrorLog &log)
{
	log.reportError("Runtime error!!");
}

int main()
{
	Cow cow("Cow");
	//cow.speak();

	//========================================================================//

	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}