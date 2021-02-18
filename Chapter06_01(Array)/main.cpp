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
	//����ü�� �迭�� ��� ���� 
	cout << sizeof(Rectangle) << endl; 

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl; 

	//����ü �迭 ���ٹ� 
	rect_arr[0].length = 10;
	rect_arr[0].width = 20;

	//C++17���ʹ� �迭�� uniform initialization�ϵ��� �ʱ�ȭ ����
	int my_arr1[] = { 0,1,2,3,4 };
	int my_arr2[]{ 0,1,2,3,4 };

	//arry�� index�� enum���� �� ���� �ִ�. 
	StudentName name = DASH;
	
	cout << my_arr1[JACK] << endl; 
	cout << my_arr2[name] << endl; 

	//enum�� ������ ���� num���� �ְ�, �迭 ���� �ÿ� �ѱ� �ε����� ��� ����
	int students_scores[NUM_STUDENTS];	//�л� ���� �� �´� ���� �ѱ� �� ����. 

	// �ڻ���� ������ �Ǵ� ���� �迭�� ������ ���
	// �迭�� ������� ������ Ÿ�ӿ� �����Ǿ�� �Ѵ�. ��Ÿ�ӿ� �����Ǵ� ���� 
	// ����� �������� �ϸ� ������ �߻� 
	
	//size ���� �״�� �������� �ϸ� ���� �߻� 
	//�ش� ���� ���� const������ �����ϸ� ���� ������Ÿ�ӿ� �����ǹǷ� ���� �ذ� 
	//int size = 5; 
	const int size = 5; 
	int test[size];

	return 0; 
}