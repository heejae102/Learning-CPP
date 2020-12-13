#include<iostream>
#include<cmath>
#include<vector>
using namespace std; 

/*

<Call by reference>

참조에 의한 호출 

매개변수로 값을 넘기는 것이 아니라, 참조할 수 있도록 하여
해당 값 자체를 변경할 수 있음. 

*/

//파라미터를 래퍼런스 변수로 받기 때문에, 래퍼런스 변수가 인자로 넘어오는
//변수를 참조하여 함수 내에서 해당 변수 값을 변경시 오리지널 변수값에도 영향. 
//즉, 값의 복사가 이루어지지 않고 오리지널 변수 자체가 넘어오는 형태. 

//래퍼런스 변수로 받을 때의 단점은 리터럴은 메모리 주소가 없으므로 
//리터럴을 인수로 받을 수 없다는 것이다. 단, const 형으로 선언하면 해당 문제도 해결.

void addOne(int &y)
{
	//인자로 넘겨받는 변수의 주소값과 일치 
	cout << y << " " << &y << endl; 

	y++;
}

//C, C++은 return값을 1개만 가질 수 있으므로, 여러 개를 리턴해야 하는 경우 
//해당 값을 래퍼런스 변수로 넘겨서 함수 내에서 수정하는 방법이 있다. 
//보통은 입력만 하는 값을 왼쪽에, 출력하는 값을 오른쪽으로 정렬 

void getSinCos(const double &degrees, double &sin_out, double &cos_out)
{
	const double pi = 3.141592 / 180.0;
	double radians = degrees * pi;

	sin_out = sin(radians);
	cos_out = cos(radians);
}

//(int*)&ptr 같은 의미이므로 다음과 같이 사용 가능 
typedef int* pint;
void test(pint &ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl;
}

//(int*)&ptr 이것과 같은 의미 
//void test(int *&ptr)
//{
//	cout << ptr << " " << &ptr << endl; 
//}

//정적배열을 래퍼런스로 받기(넘겨받을 배열의 사이즈를 반드시 기입) 
void printElements(int(&arr)[5])
{
	for (const auto &element : arr)
	{
		cout << element << endl; 
	}
}

void printElements(const vector<int> &arr)
{
	for (const auto &element : arr)
	{
		cout << element << endl;
	}
}

int main()
{
	//int x = 5;

	//cout << x << " " << &x << endl; 

	//addOne(x);

	//cout << x << " " << &x << endl;


	//----------------------------------------------------------//


	//double sin(0.0);
	//double cos(0.0);

	//getSinCos(30.0, sin, cos);

	//cout << sin << " " << cos << endl; 


	//----------------------------------------------------------//

	//포인터를 래퍼런스 변수에 넘기기 

	int x = 5;
	pint ptr = &x;

	cout << *ptr << " " << ptr << " " << &ptr << endl; 
	test(ptr);


	//----------------------------------------------------------//

	//배열을 래퍼런스 변수에 넘기기
	//정적 배열

	int arr[]{ 1,2,3,4,5 };
	printElements(arr);

	//동적 배열 

	vector<int> array{ 1,2,3,4,5 };
	printElements(array);

	return 0;
}