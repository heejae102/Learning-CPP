#include "Student.h"
#include "Teacher.h"

/*

<����� �⺻>

*/

int main()
{
	Student std("Jack");
	std.setName("Violet");

	Teacher teacher1("Dr. H");
	teacher1.setName("Dr. J");

	std::cout << std << std::endl; 
	std::cout << teacher1 << std::endl; 

	std.doNothing();
	teacher1.doNothing();

	std.study();
	teacher1.teach();

	//================================================================//

	Person person;

	person.setName("Mr. Incredible");
	person.getName();

	// �ڽ� Ŭ�������� ������ ���� �θ� Ŭ�������� ������ ����� ���� X
	//person.study();	// error
	//person.teach();	// error

	return 0; 
}