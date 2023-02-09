#include "employee.h"

employee::employee():person()//defaulte constructor
{
	seniority_years = 0;
	salary = 6500;
	excellence = false;
}

employee::employee(string name, string last_name, string id, int seniority_years, int salary)
:person( name,last_name,id)
{
	set_seniority_years(seniority_years);
	set_salary(salary);
	set_excellence(excellence);
}

employee::~employee()
{
}
employee& employee::operator=(const employee& other) {
	this->seniority_years = other.seniority_years;
	this->salary = other.salary;
	this->excellence = other.excellence;
	return *this;
}

void employee::equal_e(const employee& other)
{
	this->seniority_years = other.seniority_years;
	this->salary = other.salary;
	this->excellence = other.excellence;
}
//get and set function
int employee::get_seniority_years()
{
	return seniority_years;
}

int employee::get_salary()
{
	return salary;
}

bool employee::get_excellence()
{
	return excellence;
}

void employee::set_seniority_years(const int seniority_years)
{
	this->seniority_years = seniority_years;
}

void employee::set_salary(const int salary)
{
	this->salary = salary;
}

void employee::set_excellence( bool excellence)
{
	this -> excellence = excellence;
}

void employee::check_excellence(bool ex)// check excellence for employee
{
	this->excellence = ex;
	if (excellence == true)
		cout << "excellent worker\n";
	else
		cout << "ordinary worker\n";
}



 void employee::print_employee()// print employee detailes
{
	person::print_p();
	cout << "seniority: " << seniority_years<<endl;
	



}
