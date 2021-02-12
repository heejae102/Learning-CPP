#include<iostream>
using namespace std; 

/*

<Call by address>

매개변수로 주소 값을 넘겨 받아서 해당 주소를 통해 값을 참조하는 것.
call by value와 달리 값을 역참조하기 때문에 실제 변수 값에 영향. 

하지만 포인터 변수 차원에서는 call by value와 같이 작동하여 
인자로 받는 포인터 변수와 함수 내 매개변수인 포인터 변수는 상이한 변수이다. 
(즉, 원 변수의 주소 값과 매개변수의 주소 값이 다르다.)

*/

//포인터 변수로 주소를 전달받아 해당 변수를 사용할 경우, 
//주소로 역참조가 가능하기 때문에 원 변수값을 수정할 수 있다.

//하지만, 이것도 포인터 변수 자체는 call by value로, 포인터 변수를 선언하면서 
//인자로 넘겨받은 주소 값을 복사한 것이다. 
//즉, 오리지널 포인터 변수의 주소값과 함수 내 매개변수의 주소값은 다르다. 

//역참조로 변수값을 수정할 수 있기 때문에 함수의 출력값처럼 이용하기도 한다. 

void test(int *ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl; 
}

//데이터형 앞에 const가 붙으면 역참조하여 값을 수정하지 않겠다는 의미 
//변수명 앞에 const가 붙으면 해당 포인터 변수로 다른 주소 값을 참조하지 않겠다는 의미 

//C스타일 코딩 

void print(const int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl; 
	}
}

void print(int *const array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl;
	}

	//변수명 앞에 const가 붙었으므로 array가 다른 주소값을 참조할 수 X 
	//int x = 5;
	//array = &x;
}

int main()
{
	int value = 5;

	cout << value << " " << &value << endl; 

	int *ptr = &value;

	cout << "main &ptr : " << &ptr << endl; 

	test(ptr);
	test(&value);
	
	//리터럴은 메모리 주소가 없으므로 안됨. 매개변수를 const로 선언해도 안됨. 
	//test(5);


	//--------------------------------------------------------------------//

	int arr[5]{ 1,2,3,4,5 };

	print(arr, 5);

	return 0;
}