
#pragma once
#include<iostream>
#include<string.h>
#include "nurse.h"
#include "doctor.h"
#include "sick.h"
#include"corona.h"
#include"employee.h"
#include<string.h>
using namespace std;
class CoronaVirusCrisisManagement
{private:
	employee** workers;
	sick** Patient;
	corona** covid;
	void add_worker_N(nurse*);
	void add_worker_d(doctor*);
	void add_Patient_arr(sick* doc);
	void new_depart(corona*);

	int size_w, size_p, size_c;



	void AddNurse();
	void AddDoctor();
	void AddDepartment();
	void PrintDepartmentDetails();
	void PrintDoctorsDetails();
	void PrintSalary();
	void AddPatient();
	void AddCoronaTestToPatientById();
	void Releasing();
	void PrintExcellenceWorker();
	void PrintNurseWithSmallestSalary();


public:
	CoronaVirusCrisisManagement();
	~CoronaVirusCrisisManagement();
	void printOptions();
	void Menu();


};

