#include<iostream>
using namespace std; 

//함수의 파라미터를 const 래퍼런스로 받는 경우 
//인자를 좀 더 유동적으로 이용 가능 (변수, 상수, 변수+상수)
void doSomething(const int &x)
{
	cout << x << endl; 
}

int main()
{
	//const형의 데이터를 받을 때는 래퍼런스도 const화 시켜야 함.
	//const 래퍼런스형으로 선언 시 참조하는 값을 변경할 수 X 
	//래퍼런스 변수로 다른 래퍼런스 변수가 참조하는 값을 참조하는 것도 가능 

	const int x = 5;
	const int &ref_x = x;
	const int &ref_2 = ref_x;

	//주소가 모두 x변수의 주소로 동일하다. 
	cout << &x << endl; 
	cout << &ref_x << endl; 
	cout << &ref_2 << endl; 

	//원래 리터럴 값은 래퍼런스 변수로 참조할 수 없지만, 
	//const 래퍼런스로 선언 시 리터럴 값을 참조할 수 있다. 
	const int &ref_y = 3 + 4;

	//const형 변수와 비슷하지만, 함수 파라미터로 사용할 때 
	//const 래퍼런스형을 사용하면 굉장히 편리 
	const int value = 3 + 4;

	//리터럴의 메모리 주소도 출력 가능 
	cout << &ref_y << endl; 
	cout << ref_y << endl; 

	//-------------------------------------------------//

	//함수의 파라미터를 const 래퍼런스로 받는 경우 
	//인자를 좀 더 유동적으로 이용 가능 (변수, 상수, 변수+상수)

	int a = 1;

	doSomething(a);
	doSomething(1);
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}