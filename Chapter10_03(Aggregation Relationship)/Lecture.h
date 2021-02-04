#pragma once
#include<vector>
#include "Teacher.h"
#include "Student.h"

class Lecture
{
private:
	std::string _name;

	Teacher *_teacher;
	std::vector<Student*> _students;

public:
	Lecture(const std::string &name_in)
		: _name(name_in) {}

	~Lecture()
	{
		// Do not delete teacher
		// Do not delete students
	}

	void assignTeacher(Teacher *const teacher_input)
	{
		// Teacher의 주소를 넘겨받아 해당 주소를 참조 

		_teacher = teacher_input;
	}

	void registerStudent(Student *const student_input)
	{
		_students.push_back(student_input);

		// 주소가 아닌 일반 객체를 넘겨받아 push back하는 경우, 
		// 객체를 복사하여 원소를 생성하는 것이므로 넘겨받은 객체의 주소와 
		// 생성된 원소의 주소는 일치하지 않는다. 따라서 넘겨받은 
		// student 인스턴스를 그대로 가리키고 싶다면 주소로 넘겨받아야 함. 

		// &student_input != &students[0]
	}

	void study()
	{
		std::cout << _name << " Study " << std::endl << std::endl;

		for (auto &element : _students)
		{
			element->setIntel(element->getIntel() + 1);
		}
	}

	friend std::ostream &operator << (std::ostream &out, const Lecture &lecture)
	{
		out << "Lecture name : " << lecture._name << std::endl;

		out << *(lecture._teacher) << std::endl;

		for (auto element : lecture._students)
		{
			out << *element << std::endl;
		}

		return out;
	}

};

