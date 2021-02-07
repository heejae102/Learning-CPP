#include<iostream>
using namespace std; 

/*

<다중상속>

하나의 클래스에서 여러 개의 상위 클래스를 상속받는 것. 


※ 다이아몬드 상속 

다중상속을 잘못 사용하여 중복된 상위 객체를 상속받는 구조 
반드시 사용하면 안되는 것은 아니지만, 구조적인 특성으로 인해 문제가 발생할 수 있다. 

ex)
class A
class B1 : public A
class B2 : public A
class C : public B1, public B2

=> 결과적으로 A객체를 2번 상속받게 됨. 

*/

class USBDevice
{
private:
	long _id;

public:
	USBDevice(long id) : _id(id) {}

	long getID() { return _id; }
	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long _id;

public:
	NetworkDevice(long id) : _id(id) {}

	long getID() { return _id; }
	void neworking() {}
};

// 다중상속 
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	// 여러 개의 객체를 상속받을 경우 해당 객체들을 모두 초기화해야.
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id) {}
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.12345);

	my_device.neworking();
	my_device.plugAndPlay();

	// 다중상속 시 접근하려는 상위 클래스의 멤버가 
	// 다른 상위 클래스의 멤버와 이름이 같은 경우 컴파일러가 어떤
	// 클래스에 접근해야 할 지 명확하지 않으므로 오류 발생 
	// 따라서 해당 객체의 네임스페이스:: 로 구분하여 호출 

	cout << my_device.USBDevice::getID() << endl; 
	cout << my_device.NetworkDevice::getID() << endl; 

	return 0;
}