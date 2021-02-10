#include<iostream>
using namespace std; 

/*

<���� �⺻ Ŭ������ ���̾Ƹ�� ��� ����>

class A
{};

class B1 : public A
{};

class B2 : public A
{};

class C : public B1, public B2
{};

���̾Ƹ�� ����� ���� ��� ����������, ���� Ŭ������ 2�� ����� ������ �߻�. 
�̷��� ��쿡 virtual Ű���带 ���� �⺻ Ŭ������ ��ӹ����� ���� �ذ�. 

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
		PoweredDevice(power)	// virtual Ű���带 ���� ��� ��, �⺻ Ŭ���� �����ڵ� ȣ�����־�� ��.
	{

	}
};

int main()
{
	Copier copier(1, 2, 3);

	// virtual Ű���带 ���� ��� ��, 2���� ��� Ŭ������ �ϳ��� �⺻ Ŭ������
	// ��ӹޱ� ������ Scanner, Printer�� �θ� Ŭ������ PoweredDevice�� �ּҰ� ����. 
	// (virtual Ű���带 ������� ���� ��쿡�� �ּҰ� �ٸ���, 
	// �ν��Ͻ��� 2���̹Ƿ� �����ڸ� �� �� ȣ���ϰ� �ȴ�. )
	cout << &copier.Scanner::PoweredDevice::_i << endl; 
	cout << &copier.Printer::PoweredDevice::_i << endl;

	return 0;
}