#include<iostream>
using namespace std; 

void doSomething(int &num)
{
	cout << "doSomething : " << &num << endl; 

	num = 10; 
	cout << "In doSomething " << num << endl;
}

//배열도 래퍼런스 형식으로 파라미터를 취할 수 있다.
//단, 배열의 사이즈를 반드시 기입해야 한다. 
void printElements(int (&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl; 
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st; 
};

int main()
{
	//참조 변수 

	//int value = 5;

	//int *ptr = nullptr;
	//ptr = &value;

	////참조 변수로 다른 변수를 받으면 받아오는 변수와 메모리를 공유하는 것처럼
	////ref를 value처럼 해당 변수의 다른 별칭처럼 사용 가능 
	//int &ref = value; 

	////값을 참조하는 것뿐 아니라 변경하는 것도 가능 
	//cout << ref << endl; 
	//ref = 10;
	//cout << value << " " << ref << endl; 

	////참조 변수는 자기 자신의 별개 주소를 가지는 것이 아니라, 
	////참조하는 메모리의 주소와 동일한 주소를 가진다. 
	//cout << &ref << endl; 
	//cout << &value << endl; 
	//cout << ptr << endl; 

	////다른 참조하는 값을 재할당하는 것도 가능하지만, 
	////주소는 처음에 부여된 참조 변수의 주소와 동일 
	//int value2 = 20;
	//ref = value2;

	//cout << ref << endl; 
	//cout << &ref << endl; 
	//cout << &value2 << endl; 


	////참조 변수는 리터럴 값을 받거나, 리터럴화 된 변수를 받을 수 없다.
	////리터럴은 공식적인 메모리 주소를 가지지 못하고, 
	////리터럴화 된 변수를 받으면 해당 변수 값을 수정할 여지가 있기 때문. 
	////후자의 경우 래퍼런스도 const형으로 선언해서 사용하면 가능 
	//
	//const int var = 123;
	////int &reference = 123;  //(X)
	////int &reference = var;  //(X)
	//const int &reference = var; 

	//원래 함수에 파라미터로 넘기고 함수 내에서 해당 변수의 값을
	//수정해도 원래 변수의 값에는 영향을 미치지 않는다. 

	//but, 래퍼런스로 파라미터를 받을 경우 해당 변수를 그대로 넘기는 것으로,
	//래퍼런스로 파라미터를 받아 값을 변경시키면 원래 변수의 값도 변경된다. 
	//주소 값을 출력하면 원래 변수와 함수 내 래퍼런스 변수의 주소 값이 일치 

	//※ 포인터로 파라미터 값을 넘길 경우 포인터 변수에 넘겨진 변수의 주소 값을
	//복사해서 넣어야하므로 별개의 포인터 변수가 하나 필요했지만, 
	//래퍼런스를 사용할 경우 해당 변수가 그대로 넘어오므로 복사가 필요 없다.
	//따라서 퍼포먼스적인 측면에서도 포인터보다 성능이 우수

	//래퍼런스로 파라미터를 받지만 값을 변경하고 싶지 않은 경우 const로 선언

	int num = 5;

	cout << num << endl; 
	cout << "main num : " << &num << endl; 

	doSomething(num);

	cout << num << endl; 

	//////////////////////////////////////

	//객체나 구조체를 사용해서 이름이 길어질 경우에 래퍼런스로 
	//받아서 사용하면 편리하다. 

	Other ot;

	//접근하기까지 거쳐야 하는 것들이 많음...
	ot.st.v1 = 1.0;

	//래퍼런스 변수에 담아서 짧고 편리하게 사용가능 
	//효율적인 측면에서도 속도가 떨어지지 않기 때문에 좋다.
	int &v1 = ot.st.v1;


	//래퍼런스와 포인터 비교 
	//const형 포인터와 기능상 동일하다고 할 수 있다. 
	int value = 5;
	int *const ptr = &value;
	int &ref = value;

	*ptr = 10;
	ref = 10;

	return 0; 
}