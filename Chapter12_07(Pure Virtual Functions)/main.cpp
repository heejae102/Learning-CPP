#include<iostream>
#include<string>
using namespace std; 

/*

<순수 가상 함수, 추상 기본 클래스, 인터페이스 클래스>

1. 순수 가상 함수 (Pure Virtual Functions)
순수 가상 함수는 바디가 없는 함수로, 자식 클래스에서 
반드시 오버라이딩 해주어야 하는 함수이다. 
(자식 클래스에서 오버라이드하지 않으면 컴파일 시 오류 발생)

따라서 바디가 없다는 문법적인 측면도 있지만,
클래스 설계 시 상속 구조를 한꺼번에 설계할 수 있도록 도와주는 문법 

//========================================================================//

2. 추상 기본 클래스 (Abstract Classes) 
순수 가상 함수가 포함된 클래스를 추상 클래스라고 부른다.

//========================================================================//

3. 인터페이스 클래스 (Interface Classes)
순수 가상 함수로만 이루어진 클래스를 인터페이스 클래스라고 부른다. 

*/

// 1. 순수가상함수-추상 클래스 예제 
class Animal
{
protected:
	string _name;

public:
	Animal(std::string name)
		: _name(name) {}

public:
	string getName() { return _name; }

	virtual void speak() const = 0;		// 순수가상함수
};

// 아래와 같이 순수가상함수의 바디를 따로 구현 할 수는 있으나,  
// 순수가상함수는 상속받는 자식 내에서 반드시 오버라이드해야 하므로 (하지 않으면 오류 발생)
// 지금 구현해놓은 함수는 새로 오버라이드 된 함수에 의해 덮어씌여지므로 의미 X
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

// 2. 인터페이스 클래스 예제 
class IErrorLog
{
public:
	// 기본 클래스에서 순수 가상 함수를 생성했을 경우, 
	// 자식 클래스에서는 반드시 해당 함수를 구현해야만 컴파일 가능 
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

// 인터페이스 클래스를 상속받는 클래스들을 인터페이스 클래스 파라미터로 받아서 
// 가상 함수를 호출하면 상속받는 클래스들이 오버라이드 한 함수가 호출 됨. 
// 종류가 다른 자식 클래스들을 모두 기본 클래스 파라미터로 받을 수 있으므로 편리함.  
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