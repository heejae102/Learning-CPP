#include<iostream>
#include<vector>
#include<string>
using namespace std; 

/*

<���� ����>

���� ���質 ���� ����� �ٸ��� ���ΰ� ��򰡿� 
���ӵ��� ���� ������ ����ν� ���ΰ� ���θ� �����ϰų� 
�˰� �־���ϱ� ������ �� �ʿ��� ���漱���� �ʿ��� ����. (���ΰ� ������ ����� ����)
���漱���� �� �Ŀ� ��� ��ü�� ����� ����� ���, 
��� ��ü�� ��� ������ �̷������ ���̶�, �Լ��� �ٵ� �и��Ͽ� ����ؾ� �� �� �ִ�. 

���α׷��� ������ ������������ ���漱���� ����� �� ������� �߻��� �� �־�
������ ����� �����ϴ� ���� ������, ���α׷��� ���� ���漱���� ����� ���ۿ� 
���� ��Ȳ�� ����⵵ �ϹǷ� ��Ȳ�� ���� �� �Ǵ��ϴ� ���� ����. 

*/

class Doctor;	// Forward Declaration (���漱��)

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

	// ���漱���� ������, Doctor ��ü �� ��� ��ҿ� ���� ������ ���� ���� �����̹Ƿ�
	// �� ����� ���� ������ ���� ������ ������ �߻��ϰ� �ȴ�.
	// ���� �Լ��� �ٵ� �и��Ͽ� �ش� ����� ���� �Ʒ��� ���� ��. 
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

// Doctor ��ü �� ���(_name)�� �����ϱ� ���� �ٵ� �и��Ͽ� 
// Doctor ��ü�� ������ �̷������ �� �ڿ� �Լ� ���� 
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