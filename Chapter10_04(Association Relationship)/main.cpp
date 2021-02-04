#include<iostream>
#include<vector>
#include<string>
using namespace std; 

/*

<제휴 관계>

구성 관계나 집합 관계와 다르게 서로가 어딘가에 
종속되지 않은 동등한 관계로써 서로가 서로를 참조하거나 
알고 있어야하기 때문에 한 쪽에서 전방선언이 필요한 구조. (서로가 서로의 멤버를 가짐)
전방선언을 한 후에 상대 객체의 멤버를 사용할 경우, 
상대 객체의 멤버 선언이 이루어지기 전이라, 함수의 바디를 분리하여 사용해야 할 수 있다. 

프로그램의 구조가 복잡해질수록 전방선언을 사용할 때 어려움이 발생할 수 있어
가급적 사용을 지양하는 것이 좋으나, 프로그램에 따라 전방선언을 사용할 수밖에 
없는 상황이 생기기도 하므로 상황에 따라 잘 판단하는 것이 좋다. 

*/

class Doctor;	// Forward Declaration (전방선언)

class Patient
{
private:
	string _name;
	vector<Doctor*> _doctors;

public:
	Patient(const string &name_in)
		: _name(name_in) {}

	void addDoctor(Doctor *new_doctor)
	{
		_doctors.push_back(new_doctor);
	}

	// 전방선언을 했지만, Doctor 객체 내 멤버 요소에 대한 선언을 하지 않은 상태이므로
	// 각 멤버에 대한 정보는 없기 때문에 오류가 발생하게 된다.
	// 따라서 함수의 바디를 분리하여 해당 멤버의 선언 아래로 내릴 것. 
	void meetDoctors();

	friend class Doctor; 
};

class Doctor
{
private:
	string _name;
	vector<Patient*> _patients;

public:
	Doctor(const string &name_in)
		: _name(name_in) {}

	void addPatient(Patient *new_patient)
	{
		_patients.push_back(new_patient);
	}

	void meetPatients()
	{
		for (auto &element : _patients)
		{
			cout << "Meet doctor : " << element->_name << endl;
		}
	}

	friend class Patient;
};

// Doctor 객체 내 멤버(_name)에 접근하기 위해 바디를 분리하여 
// Doctor 객체의 선언이 이루어지고 난 뒤에 함수 정의 
void Patient::meetDoctors()
{
	for (auto &element : _doctors)
	{
		cout << "Meet doctor : " << element->_name << endl;
	}
}

int main()
{
	Patient *p1 = new Patient("Jack");
	Patient *p2 = new Patient("Dash");
	Patient *p3 = new Patient("Violet");

	Doctor *d1 = new Doctor("Doctor K");
	Doctor *d2 = new Doctor("Doctor L");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// Patinets meet doctors
	p1->meetDoctors();

	// Doctors meet patients
	d1->meetPatients();


	//======================================================================//

	// Delete Momories

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0; 
}