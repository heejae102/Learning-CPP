#include"AutoPtr.h"
#include"Resource.h"
#include"Time.h"
using namespace std; 

/*

<�̵� �����ڿ� �̵� ����>

�����͸� ���� deep copy�ؼ� �ѱ�� ���� �ƴ϶�,
�����͸� �Ѱܼ� �����Ǹ� ������Ų�ٴ� ����

-> �����͸� �Ѱ��ֱ� ������ ��� ���� �����͸� ���� ������ �ʿ䰡 ��� �ӵ��� ����. 

*/

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10000000));
	
	return res;
}

int main()
{
	streambuf* orig_buf = cout.rdbuf();
	cout.rdbuf(NULL);	// disconnect cout from buffer

	Time timer;

	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
	}

	cout.rdbuf(orig_buf);
	//std::cout << timer.elapsed() << std::endl; 

	return 0;
}