#pragma once
#include "employee.h"
class doctor :public employee
{
private:
	string name_of_hospital;
	bool professor;
	int num_of_p_evaluations;
public:
	doctor();
	doctor(string name, string last_name, string id, int seniority_years, string name_of_hospital, bool professor, int num_of_p_evaluations);
	doctor& operator=(const doctor& other);
	~doctor();

	int doctor_salary();
	bool doctor_excellence();
	 void print_doctor();

	void set_name_of_hospital(const string);
	void set_professor(const bool);
	void set_num_of_p_evaluations(const int);
	string get_name_of_hospital();
	bool get_professor();
	int get_num_of_p_evaluations();

	void set_an_arguments(const string name, const string last_name, const string id, const int seniority_years, const string name_of_hospital, const bool professor, const int num_of_p_evaluations);




};

