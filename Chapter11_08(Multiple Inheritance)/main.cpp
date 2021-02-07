#include<iostream>
using namespace std; 

/*

<���߻��>

�ϳ��� Ŭ�������� ���� ���� ���� Ŭ������ ��ӹ޴� ��. 


�� ���̾Ƹ�� ��� 

���߻���� �߸� ����Ͽ� �ߺ��� ���� ��ü�� ��ӹ޴� ���� 
�ݵ�� ����ϸ� �ȵǴ� ���� �ƴ�����, �������� Ư������ ���� ������ �߻��� �� �ִ�. 

ex)
class A
class B1 : public A
class B2 : public A
class C : public B1, public B2

=> ��������� A��ü�� 2�� ��ӹް� ��. 

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

// ���߻�� 
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	// ���� ���� ��ü�� ��ӹ��� ��� �ش� ��ü���� ��� �ʱ�ȭ�ؾ�.
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id) {}
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.12345);

	my_device.neworking();
	my_device.plugAndPlay();

	// ���߻�� �� �����Ϸ��� ���� Ŭ������ ����� 
	// �ٸ� ���� Ŭ������ ����� �̸��� ���� ��� �����Ϸ��� �
	// Ŭ������ �����ؾ� �� �� ��Ȯ���� �����Ƿ� ���� �߻� 
	// ���� �ش� ��ü�� ���ӽ����̽�:: �� �����Ͽ� ȣ�� 

	cout << my_device.USBDevice::getID() << endl; 
	cout << my_device.NetworkDevice::getID() << endl; 

	return 0;
}