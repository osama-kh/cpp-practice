#include "Employee.h"
#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>


Employee::Employee() {
	
	strcpy(full_name, "unknown");
	strcpy(id, "000000000");
	years_of_seniority=0;
	number_of_excellence=0;
	degree = false;
}

Employee::Employee(char full_name[], char id[], int years_of_seniority, int number_of_excellence, bool degree) {
	set_full_name(full_name);
	set_id(id);
	set_years_of_seniority(years_of_seniority);
	set_number_of_excellence(number_of_excellence);
	set_degree(degree);
 }

Employee::Employee(const Employee& other) {


	set_full_name(other.full_name);
	set_id(other.id);
	set_years_of_seniority(other.years_of_seniority);
	set_number_of_excellence(other.number_of_excellence);
	set_degree(other.degree);

}

int Employee::Bonus() {
	if (number_of_excellence * 550 > 3000)
		return 3000;
	else 
		return number_of_excellence * 550;
}

int Employee::Salary() {
	if (degree ==true)
		return (6000 + (1000 * years_of_seniority) + Bonus() + 2000);
	else
		return (6000 + (1000 * years_of_seniority) + Bonus() );
}

void Employee::Show_Employee() {
	cout << endl << "Employee Name :" << this->get_full_name() << endl
		<< "ID :" << this->get_id() << endl
		<< "Seniority :" << this->get_years_of_seniority() << endl
		<< "Excellence :" << this->get_number_of_excellence() << endl
		<< "Degree :";
	if (degree == true)
		cout << "Y";
	else
		cout << "N";
	cout << endl
		<< "Bonus :" << this->Bonus() << endl
		<< "Salary :" << this->Salary() << endl;

}



void Employee::set_full_name(const char full_name[]) {
	if (strlen(full_name) > 51)
		strcpy(this->full_name, "Unknown");
	else 
		strcpy(this->full_name, full_name);

}

void Employee::set_id(const char id[]) {
	if (strlen(id) > 10)
		strcpy(this->id, "000000000");
	else
		strcpy(this->id, id);
}

void Employee::set_years_of_seniority(const int years_of_seniority) {
	if (years_of_seniority < 0) 
		this->years_of_seniority=0;
	else this->years_of_seniority = years_of_seniority;

}

void Employee::set_number_of_excellence(const int number_of_excellence) {
	if (number_of_excellence < 0)
		this->number_of_excellence = 0;
	else this->number_of_excellence = number_of_excellence;
}

void Employee::set_degree(const bool degree) {
	this->degree = degree;

}

char* Employee::get_full_name() {
	return full_name;
}

char* Employee::get_id() {
	return id;
}

int Employee::get_years_of_seniority() {
	return years_of_seniority;
}

int Employee::get_number_of_excellence() {
	return number_of_excellence;
}

bool Employee::get_degree() {
	return degree;
}