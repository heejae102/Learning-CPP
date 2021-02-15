#include<iostream>
using namespace std; 

/*

<예외 클래스와 상속>

*/

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl; 
	}
};

class MyArray
{
private:
	int _data[5];

public:
	int &operator [](const int &index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		//if (index < 0 || index >= 5) throw Exception();
		if (index < 0 || index >= 5) throw ArrayException();

		return _data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int &x)
	{
		cerr << "Exception" << x << endl; 
	}
	//catch (ArrayException &exception)
	//{
	//	// 자식 클래스를 throw하는데, 부모 클래스 형의 catch 구문이
	//	// 자식 클래스 형의 catch 구문보다 위에 있을 경우 
	//	// 부모 클래스 형의 catch 구문이 캐치 (상속 구조는 자료형이 달라도 catch 가능)
	//	// => 자식 클래스 형의 catch 구문을 위로 올려서 해결 가능 
	//	
	//	cout << "doSomething()" << endl; 
	//	exception.report();
	//	throw exception;
	//}
	catch (Exception &exception)
	{
		// 자식 클래스 형을 캐치했을 경우, 데이터 잘림 현상으로 
		// 자식 클래스의 report 함수가 아닌 부모 클래스의 report 함수 실행 

		cout << "doSomething()" << endl;
		exception.report();
		
		// 자식 클래스 형을 캐치해도 부모형으로 복사받은 매개변수로 throw할 경우
		// 부모 클래스 형으로 넘겨주게 됨. 

		// 반면, 매개변수를 사용하지 않고 그냥 throw 할 경우 처음 넘겨주었던
		// 자식 클래스 그대로 throw 하게 되므로 자식 클래스 형으로 넘겨주게 됨. 
		//throw exception;
		throw;
	}
	//catch (ArrayException &exception)
	//{
	//	// 자식 클래스를 throw하는데, 부모 클래스 형의 catch 구문이
	//	// 자식 클래스 형의 catch 구문보다 위에 있을 경우 
	//	// 부모 클래스 형의 catch 구문이 캐치 (상속 구조는 자료형이 달라도 catch 가능)
	//
	//	cout << "doSomething()" << endl;
	//	exception.report();
	//	throw exception;
	//}
}

int main()
{
	try
	{
		// doSomething 함수 실행 시 해당 함수 내에서 
		// throw - catch 가 모두 이루어지므로, main 함수 내의 catch는 작동하지 X 
		// main 함수 내의 catch 문도 작동하게 하기 위해서는 예외를 다시 throw 해야 함.
		doSomething();
	}
	catch (ArrayException &exception)
	{
		cout << "main()" << endl; 
		exception.report();
	}
	catch (Exception &exception)
	{
		cout << "main()" << endl;
		exception.report();
	}

	return 0;
}