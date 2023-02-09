#pragma once
#include<iostream>
#include<string.h>
#include "nurse.h"
#include "doctor.h"
#include "sick.h"
using namespace std;
class corona
{
private:
	string name_of_hospital;
	doctor** dr_covid;
	nurse** nu_covid;
	sick** sk_covid;
	int size_dr, size_nu, size_sk;
public:
	corona();
	corona(string name_of_hospital);
	~corona();
	void AddDoctor(doctor*);
	void AddNurse(nurse*);
	void AddPatient(sick*);
	void remove_Patient(sick* pat);
	void print_corona();
	void new_doctor(doctor*);
	void to_doctor();
	void to_nurse();
	void to_sick();
	void new_nurse(nurse* nu);
	void check_excelence();

	void new_patient(sick* pa);
	int get_size_dr()const;
	int get_size_nu()const;
	int get_size_sk()const;
	doctor** get_doctor()const;
	nurse** get_nurse()const;
	sick** get_sick()const;
	string get_name_of_hospital();

	void nurse_lower_salary();





};

