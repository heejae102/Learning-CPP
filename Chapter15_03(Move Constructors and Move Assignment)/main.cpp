#include"AutoPtr.h"
#include"Resource.h"
#include"Time.h"
using namespace std; 

/*

<이동 생성자와 이동 대입>

데이터를 전부 deep copy해서 넘기는 것이 아니라,
포인터만 넘겨서 소유권만 이전시킨다는 개념

-> 포인터만 넘겨주기 때문에 모든 내부 데이터를 전부 복사할 필요가 없어서 속도가 빠름. 

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