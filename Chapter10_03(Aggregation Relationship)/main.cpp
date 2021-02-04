#include<iostream>
#include "Lecture.h"
using namespace std;

int main()
{
	// Association Relationship

	// �� ����, �л����� ���� Ŭ������ ������ �����صΰ�, ���� Ŭ������ ���� �� �л� ��� �� 
	// �ּҸ� �Ѱܼ� ����ϱ� ������ ���� �ٸ� ���ǿ��� ����, �л��� ������ ���� ����Ǿ
	// ���� �ּ��� ��ü�̹Ƿ� ���� �����ϰ� ����ȴ�. 

	// ���� ���α׷������δ� ����1, ����2�� ���� ����, �л� �ν��Ͻ��� �����ϴ� ����������
	// �л�ó���ؼ� �۾��ϴ� ���α׷��� ��� �̿� ���� ���·� ������ �� ����. 
	// �л�ó�� �� ��ǻ���� �޸𸮰� �и��Ǿ� �ֱ� ������ ���� ¥�־�� �Ѵ�. 
	// �� �����͸� �и����� �纻�� �ٸ� ��ǻ�Ͱ� ������ �ֵ��� �ϰ�, �ش� ������ ���� ���� ���
	// �ٸ� ��ǻ���� �����͵� ������Ʈ�� �� �ֵ��� ��ũ�γ�����Ǵ� ���·� �������־�� �Ѵ�. 

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
	// ���� Ŭ���� ���� �Ҽӵ� �л����� ���� �л����ӿ��� �ұ��ϰ�
	// ���� �ٸ� �ν��Ͻ��̹Ƿ�, �л� ��ü �� ���� ��ȭ�� ��� ���� �л����� ������ ���� ��ġ���� X 
	// �ϳ��� ���Ǹ� �����ϸ� �ش� ��ü ���� �����ִ� ����, �л������ ��� ������. 

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