#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string.h>

using namespace std;

#define NAME_SIZE 51
#define ID_SIZE 10

class Employee
{
private:
	char full_name[NAME_SIZE];
	char id[ID_SIZE];
	int years_of_seniority;
	int number_of_excellence;
	bool degree;

public:
	Employee();
	Employee(char full_name[], char id[], int years_of_seniority, int number_of_excellence, bool degree);
	Employee(const Employee &other);

	int Bonus();
	int Salary();
	void Show_Employee();

	char* get_full_name();
	char* get_id();
	int get_years_of_seniority();
	int get_number_of_excellence();
	bool get_degree();

	void set_full_name(const char full_name[]);
	void set_id(const char id[]);
	void set_years_of_seniority(const int years_of_seniority);
	void set_number_of_excellence(const int number_of_excellence);
	void set_degree(const bool degree);
};
