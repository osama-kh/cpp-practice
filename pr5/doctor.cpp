#include "doctor.h"

doctor::doctor():employee()//defaulte constructor
{
	name_of_hospital = "unknown";
	professor = false;
	num_of_p_evaluations = 0;
}

doctor::doctor(string name, string last_name, string id, int seniority_years, string name_of_hospital, bool professor, int num_of_p_evaluations)
:employee(name, last_name, id, seniority_years,doctor_salary()) 
{
	set_name_of_hospital(name_of_hospital);
	set_professor(professor);
	set_num_of_p_evaluations(num_of_p_evaluations);
	

}
doctor& doctor:: operator =(const doctor& other){// operator =
	this->equal(other);
	this->equal_e(other);
	this->name_of_hospital = other.name_of_hospital;
	this->professor = other.professor;
	this->num_of_p_evaluations = other.num_of_p_evaluations;

	return *this;

}


doctor::~doctor()
{
}



int doctor::doctor_salary()// to calculate doctors salary
{
	int sum=6500 + 200 * get_seniority_years() + 50 * num_of_p_evaluations;
	if (professor == true)
		sum += 2000;
	

	return sum;
}

bool doctor::doctor_excellence()//check doctor excellence
{
	if (num_of_p_evaluations > 10)
		return true;
	else
		return false;
}

void doctor::print_doctor()//print doctor detailes
{
	cout << "------ doctor details ------\n";
	employee::print_employee();
	cout << "name of hospital: " << name_of_hospital << endl;

		cout << "degree: "; 
		if (professor == true)
			cout << "professor\n ";
		else 
			cout << "doctor\n ";
	cout <<"salary: " << doctor_salary() << endl;
	cout << "excellence: ";
	check_excellence(doctor_excellence());
}




//get and set functions

void doctor::set_name_of_hospital(const string name_of_hospital)
{
	this->name_of_hospital = name_of_hospital;
}

void doctor::set_professor(const bool professor)
{
	this->professor = professor;
}

void doctor::set_num_of_p_evaluations(const int num_of_p_evaluations)
{
	this->num_of_p_evaluations = num_of_p_evaluations;
}

string doctor::get_name_of_hospital()
{
	return name_of_hospital;
}

bool doctor::get_professor()
{
	return professor;
}

int doctor::get_num_of_p_evaluations()
{
	return num_of_p_evaluations;
}

void doctor::set_an_arguments( const string name,const string last_name, const string id, const int seniority_years, const string name_of_hospital, const bool professor, const int num_of_p_evaluations)
{
	set_name(name);
	set_last_name(last_name);
	set_id(id);
	set_seniority_years(seniority_years);
	set_name_of_hospital(name_of_hospital);
	set_professor(professor);
	set_num_of_p_evaluations(num_of_p_evaluations);
}

