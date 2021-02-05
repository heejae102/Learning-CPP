#include "Student.h"
#include "Teacher.h"

/*

<상속의 기본>

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

	// 자식 클래스에서 구현된 것을 부모 클래스에서 가져다 사용할 수는 X
	//person.study();	// error
	//person.teach();	// error

	return 0; 
}