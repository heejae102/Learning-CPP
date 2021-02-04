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
		// Teacher�� �ּҸ� �Ѱܹ޾� �ش� �ּҸ� ���� 

		_teacher = teacher_input;
	}

	void registerStudent(Student *const student_input)
	{
		_students.push_back(student_input);

		// �ּҰ� �ƴ� �Ϲ� ��ü�� �Ѱܹ޾� push back�ϴ� ���, 
		// ��ü�� �����Ͽ� ���Ҹ� �����ϴ� ���̹Ƿ� �Ѱܹ��� ��ü�� �ּҿ� 
		// ������ ������ �ּҴ� ��ġ���� �ʴ´�. ���� �Ѱܹ��� 
		// student �ν��Ͻ��� �״�� ����Ű�� �ʹٸ� �ּҷ� �Ѱܹ޾ƾ� ��. 

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

