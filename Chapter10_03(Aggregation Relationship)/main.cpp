#include<iostream>
#include "Lecture.h"
using namespace std;

int main()
{
	// Association Relationship

	// 각 교수, 학생들은 강의 클래스와 별개로 선언해두고, 강의 클래스에 교수 및 학생 등록 시 
	// 주소를 넘겨서 등록하기 때문에 서로 다른 강의에서 교수, 학생의 데이터 값이 변경되어도
	// 같은 주소의 객체이므로 값이 동일하게 변경된다. 

	// 현재 프로그램상으로는 강의1, 강의2가 같은 교수, 학생 인스턴스를 공유하는 형태이지만
	// 분산처리해서 작업하는 프로그램의 경우 이와 같은 형태로 구현할 수 없다. 
	// 분산처리 시 컴퓨터의 메모리가 분리되어 있기 때문에 따로 짜주어야 한다. 
	// 각 데이터를 분리시켜 사본을 다른 컴퓨터가 가지고 있도록 하고, 해당 데이터 값이 변할 경우
	// 다른 컴퓨터의 데이터도 업데이트될 수 있도록 싱크로나이즈되는 형태로 구현해주어야 한다. 

	Student *std1 = new Student("Jack Jack", 0);
	Student *std2 = new Student("Dash", 1);
	Student *std3 = new Student("Violet", 2);

	Teacher *teacher1 = new Teacher("Prof. Hong");
	Teacher *teacher2 = new Teacher("Prof. Good");

	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(teacher1);
	lec1.registerStudent(std1);
	lec1.registerStudent(std2);
	lec1.registerStudent(std3);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(teacher2);
	lec2.registerStudent(std1);
	lec2.registerStudent(std2);

	// test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		// event 
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}

	//========================================================================//

	// Delete Memory (if necessary)

	delete std1;
	delete std2;
	delete std3;

	delete teacher1;
	delete teacher2;

	//========================================================================//

	// Composition Relationship
	// 강의 클래스 내에 소속된 학생들은 같은 학생들임에도 불구하고
	// 서로 다른 인스턴스이므로, 학생 객체 내 값이 변화될 경우 같은 학생끼리 데이터 값이 일치하지 X 
	// 하나의 강의를 삭제하면 해당 객체 내에 딸려있던 강사, 학생들까지 모두 삭제됨. 

	//Lecture lec1("Introduction to Computer Programming");

	//lec1.assignTeacher(Teacher("Prof. Hong"));
	//lec1.registerStudent(Student("Jack Jack", 0));
	//lec1.registerStudent(Student("Dash", 1));
	//lec1.registerStudent(Student("Violet", 2));

	//Lecture lec2("Computational Thinking");
	//lec2.assignTeacher(Teacher("Prof. Good"));
	//lec2.registerStudent(Student("Jack Jack", 0));


	return 0;
}