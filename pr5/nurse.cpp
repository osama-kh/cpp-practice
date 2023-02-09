#include "nurse.h"

nurse::nurse():employee()//defaulte constructor
{
	name_of_hospital = "unknown";
	training_and_courses = 0;
}

nurse::nurse(string name, string last_name, string id, int seniority_years, string name_of_hospital, int training_and_courses)
:employee(name,last_name,id, seniority_years, nurse_salary())
{
	set_name_of_hospital(name_of_hospital);
	set_training_and_courses(training_and_courses);
}

nurse::~nurse()
{
}

nurse& nurse:: operator =(const nurse& other) {
	this->equal(other);
	this->equal_e(other);
	this->name_of_hospital = other.name_of_hospital;
	this->training_and_courses = other.training_and_courses;

	return *this;
}
bool nurse::nurse_excellence()// check nurse excellence
{
	if (get_seniority_years() <= training_and_courses) {
		return true;
	}
	else false;
}

int nurse::nurse_salary()// calculate nurse salary
{

	return 6500+(training_and_courses*50);
}

void nurse::print_nurse()//print nurse details
{
	cout << "------ Nurse details ------\n";
	employee::print_employee();
	cout << "name of hospital: " << name_of_hospital << endl;
	cout << "number of training courses: " << training_and_courses<<endl;
	cout << "salary: " << nurse_salary()<<endl;
	cout << "excellence: ";
	check_excellence(nurse_excellence());
}
//set and get functions
void nurse::set_name_of_hospital(const string name_of_hospital)
{
	this->name_of_hospital = name_of_hospital;
}

void nurse::set_training_and_courses(const int training_and_courses)
{
	this->training_and_courses = training_and_courses;
}

string nurse::get_name_of_hospital()
{
	return name_of_hospital;
}

int nurse::get_training_and_courses()
{
	return training_and_courses;
}

void nurse::set_an_arguments(const string name, const string last_name, const string id, const int seniority_years, const string name_of_hospital, const int training_and_courses)
{
	set_name(name);
	set_last_name(last_name);
	set_id(id);
	set_seniority_years(seniority_years);
	set_name_of_hospital(name_of_hospital);
	set_name_of_hospital(name_of_hospital);
	set_training_and_courses(training_and_courses);
	set_salary(nurse_salary());
}
