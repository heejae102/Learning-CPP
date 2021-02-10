#include<iostream>
using namespace std; 

/*

<가상 기본 클래스와 다이아몬드 상속 문제>

class A
{};

class B1 : public A
{};

class B2 : public A
{};

class C : public B1, public B2
{};

다이아몬드 모양의 다중 상속 구조에서는, 상위 클래스가 2개 생기는 문제가 발생. 
이러한 경우에 virtual 키워드를 통해 기본 클래스를 상속받으면 문제 해결. 

*/

class PoweredDevice
{
public:
	int _i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice : " << power << '\n';
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << '\n';
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer : " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power),
		PoweredDevice(power)	// virtual 키워드를 통해 상속 시, 기본 클래스 생성자도 호출해주어야 함.
	{

	}
};

int main()
{
	Copier copier(1, 2, 3);

	// virtual 키워드를 통해 상속 시, 2개의 상속 클래스가 하나의 기본 클래스를
	// 상속받기 때문에 Scanner, Printer의 부모 클래스인 PoweredDevice의 주소가 같음. 
	// (virtual 키워드를 사용하지 않을 경우에는 주소가 다르며, 
	// 인스턴스가 2개이므로 생성자를 두 번 호출하게 된다. )
	cout << &copier.Scanner::PoweredDevice::_i << endl; 
	cout << &copier.Printer::PoweredDevice::_i << endl;

	return 0;
}