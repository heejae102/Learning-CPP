#include<iostream>
using namespace std; 

// void pointer (=generic pointer)

enum Type
{
	INT,
	FLOAT,
	CHAR
};

int main()
{
	//포인터가 어떤 크기의 데이터를 참조하든지 포인터 변수 자체의 크기는 일정하므로
	//void 포인터도 데이터의 크기와 상관없이 어떤 데이터도 참조할 수 있다.
	//단, 데이터형이 void이므로 주소값을 넘겨받은 변수가 어떤 데이터형인지 
	//추측할 수 있는 단서가 없다. 

	//같은 이유로, 연산 시 기준으로 삼을 데이터 크기를 모르기 때문에
	//포인터 연산도 불가능하다. 

	int i = 5;
	float f = 3.5f;
	char c = 'a';

	void *ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	//+1을 할 때 + 연산을 실행 할 메모리 단위를 모르기 때문에 오류 발생 
	//cout << ptr + 1 << endl; 

	//또한, 해당 메모리를 어떠한 데이터형으로 표현해야 할지 모르기 때문에
	//포인터로 de-referencing(역참조)도 불가능 
	//대신 주소값은 가져올 수 있다. 
	//cout << *ptr << endl; 
	cout << ptr << endl; 

	//void 포인터로 역참조 시, 바꾸고자 하는 데이터의 포인터형으로 캐스팅 필요 
	//이렇듯 사용이 매우 불편하지만 다형성을 구현하기 위해
	//부득이하게 사용해야 하는 경우가 있을 수 있다. 
	Type type = FLOAT;

	switch (type)
	{
	case INT:
		cout << *static_cast<int*>(ptr) << endl;
		break;
	case FLOAT:
		cout << *static_cast<float*>(ptr) << endl;
		break;
	case CHAR:
		cout << *static_cast<char*>(ptr) << endl;
		break;
	default:
		break;
	}

	return 0;
}