#include<iostream>
using namespace std; 

enum StudentName
{
	JACK,			//0
	DASH,			//1	
	VIOLET,			//2
	NUM_STUDENTS	//3
};

struct Rectangle
{
	int length; 
	int width; 
};

int main()
{
	//구조체도 배열로 사용 가능 
	cout << sizeof(Rectangle) << endl; 

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl; 

	//구조체 배열 접근법 
	rect_arr[0].length = 10;
	rect_arr[0].width = 20;

	//C++17부터는 배열도 uniform initialization하듯이 초기화 가능
	int my_arr1[] = { 0,1,2,3,4 };
	int my_arr2[]{ 0,1,2,3,4 };

	//arry의 index로 enum값이 들어갈 수도 있다. 
	StudentName name = DASH;
	
	cout << my_arr1[JACK] << endl; 
	cout << my_arr2[name] << endl; 

	//enum의 마지막 값을 num으로 주고, 배열 선언 시에 넘길 인덱스로 사용 가능
	int students_scores[NUM_STUDENTS];	//학생 수와 딱 맞는 값을 넘길 수 있음. 

	// ★사이즈가 고정이 되는 정적 배열을 선언할 경우
	// 배열의 사이즈는 컴파일 타임에 결정되어야 한다. 런타임에 결정되는 값을 
	// 사이즈에 넣으려고 하면 에러가 발생 
	
	//size 값을 그대로 넣으려고 하면 에러 발생 
	//해당 변수 값을 const형으로 선언하면 값이 컴파일타임에 고정되므로 오류 해결 
	//int size = 5; 
	const int size = 5; 
	int test[size];

	return 0; 
}