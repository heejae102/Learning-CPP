#include<iostream>
using namespace std; 

//함수에서 인자로 배열을 받을 경우, 배열의 모든 원소를 복사해서 
//가져오는 것이 아니라 배열의 배열의 첫 번째 원소 주소값만 복사

//따라서 함수 내에서 인자로 넘어온 지역변수는 해당 배열을 전부 복사한 것이 아니며,
//주소값을 복사하여 포인터 변수에 담은 것이기 때문에, 해당 변수의 주소 값을 출력하면
//포인터 변수의 주소 값이 출력되므로 인자로 넘긴 변수의 주소값과 다르다. 

void doSomething(int students_scores[/*20*/])
{
	//인자로 넘겨받은 변수의 주소값을 저장한 포인터의 주소값
	cout << &students_scores << endl; 
	
	//단, 넘겨받은 배열의 주소값을 출력하면 원 변수의 주소값과 일치 
	cout << students_scores << endl; 
	cout << &students_scores[0] << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << students_scores[3] << endl;

	//students_score는 배열 전체가 아니라 배열의 첫번째 주소 값을 저장하고 있는
	//포인터 변수이므로 해당 변수의 사이즈를 측정하면 포인터의 사이즈 값이 나온다.
	cout << sizeof(students_scores) << endl; 
	cout << sizeof(&students_scores) << endl; 
}

int main()
{
	const int num_students = 10;

	int students_scores[10];
	students_scores[0] = 1;
	students_scores[1] = 2;
	students_scores[2] = 3;
	students_scores[3] = 4;
	students_scores[4] = 5;

	//배열에서 변수명(식별자)은 내부적으로 주소로 사용된다.
	//따라서 주소 연산자를 사용하지 않아도 변수명을 주소로 사용할 수 있다. 
	cout << students_scores << endl;
	cout << &students_scores << endl; 
	cout << &students_scores[0] << endl;
	cout << &students_scores[1] << endl;
	cout << &students_scores[2] << endl;
	cout << &students_scores[3] << endl;
	cout << &students_scores[4] << endl;

	cout << sizeof(students_scores) << endl; 

	cout << endl;
	doSomething(students_scores);

	return 0; 
}