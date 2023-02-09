#pragma once
#include "employee.h"
class nurse :public employee
{
private:
	string name_of_hospital;
	int training_and_courses;
public:

	nurse();
	nurse(string name, string last_name, string id, int seniority_years, string name_of_hospital, int training_and_courses);
	~nurse();

	nurse& operator=(const nurse& other);

	bool nurse_excellence();
	int nurse_salary();
	void print_nurse();

	void set_name_of_hospital(const string );
	void set_training_and_courses(const int);
	string get_name_of_hospital();
	int get_training_and_courses();

	void set_an_arguments(string name, string last_name, string id, int seniority_years, string name_of_hospital, int training_and_courses);

};

