#include "corona.h"

//corona department

corona::corona()//defaulte constructor
{
	cout << "-------- new department --------\n";
	cout << "Enter the hospital name:\n";
	cin>>name_of_hospital ;

	size_dr = 1;
	size_nu = 2;
	size_sk = 0;
	dr_covid = new doctor*[size_dr];

	for (int i = 0; i < size_dr; i++) {
	(dr_covid)[i] = new doctor();
	new_doctor(dr_covid[i]);
	cout << endl;
	}

	
	nu_covid = new nurse*[size_nu];
	for (int i = 0; i < size_nu; i++){
		(nu_covid)[i] = new nurse();
		new_nurse(nu_covid[i]);
		cout << endl;

	}
	sk_covid = new sick * [size_sk];

	
}
 
corona::corona(string name_of_hospital)
{
	
	this->name_of_hospital = name_of_hospital;

}

corona::~corona()
{
	delete[]dr_covid;
	delete[]nu_covid;
	delete[]sk_covid;
}

void corona::AddDoctor(doctor* doc)// function to add a doctor to the doctors array
{
	int i;
	doctor** help;
	help = new doctor*[size_dr];
	for (i = 0; i < size_dr; i++) {
		help[i] = dr_covid[i];
	}
	int old = size_dr;
	size_dr += 1;
	dr_covid = new doctor*[size_dr];
	for (i = 0; i < old; i++)
		dr_covid[i] = help[i];
	dr_covid[size_dr - 1] = doc;


}

void corona::AddNurse(nurse* nur)// function to add a nurse to the nurses array
{
	int i;
	nurse** help;
	help = new nurse*[size_nu];
	for (i = 0; i < size_nu; i++) {
	help[i] = nu_covid[i];
	}
	int old = size_nu;
	size_nu += 1;
	nu_covid = new nurse*[size_nu];
	for (i = 0; i < old; i++)
		nu_covid[i] = help[i];
	nu_covid[size_nu-1] = nur;


}

void corona::AddPatient(sick* pat)// function to add a patient to the patients array
{
	if(size_dr>=1 && size_nu>=2){
	int i;
	sick** help;
	help = new sick*[size_sk];
	for (i = 0; i < size_sk; i++) {
		help[i] = sk_covid[i];
	}
	int old = size_sk;
	size_sk += 1;
	sk_covid = new sick*[size_sk];
	for (i = 0; i < old; i++)
		sk_covid[i] = help[i];
	sk_covid[size_sk-1] = pat;
}
	else {
		cout << "There are no enough doctors and nurses in the department! \n";
	}

}
void corona::remove_Patient(sick* pat)//function to remove patient
{
	
	if (size_sk == 0) { cout << "\nthere are no patient's in this department!\n"; }
else{
		if (pat->get_num_of_N_tests() >= 2) {
	int i,j=0;
	sick** help;
	help = new sick* [size_sk];
	for (i = 0; i < size_sk; i++) {
		help[i] = sk_covid[i];
	}
	int size_new = size_sk - 1;
	delete[]sk_covid;
	if(size_new>0){
	sk_covid= new sick* [size_new];
	for (i = 0; i < size_sk; i++) {
		if (help[i]->get_id() != pat->get_id()) {
			sk_covid[j] = help[i];
			j++;
		}
	}
}
	size_sk -= 1;
}
	}

}



void corona::print_corona()// print the department
{
	int i;
	cout <<endl<<endl<< "------ department details ------\n";
	cout << "name of hospital: " << name_of_hospital << endl;
	cout << " the workers in this department: \n";

	for (i = 0; i < size_dr; i++) {
		dr_covid[i]->print_doctor();
		cout << endl;
	}
	
	for (i = 0; i < size_nu; i++){
		nu_covid[i]->print_nurse();
		cout << endl;
		}
	cout << "number of patients in the department: " << size_sk<<endl;

}

void corona::new_doctor(doctor* doc)//enter a new doctor to the department
{

	cout << "Enter doctor details: \n";
	string name; 
	cout << "doctor name: ";
	cin >> name;

	string last_name; 
	cout << "doctor last name: ";
	cin >> last_name;

	string id;
	cout << "doctor ID: ";
	cin >> id;

	int seniority_years;
	cout << "seniority years: ";
	cin >> seniority_years;

	string name_of_hospital;
	cout << "name of hospital: ";
	cin >> name_of_hospital;

	bool professor;
	cout << "have professor degree: ";
	cin >> professor;

	int num_of_p_evaluations;
	cout << "number of postive feedbacks: ";
	cin >> num_of_p_evaluations;

	doc->set_an_arguments(name,last_name, id,  seniority_years,  name_of_hospital,  professor,  num_of_p_evaluations);


	
}

void corona::to_doctor()
{
	for (int i = 0; i < size_dr; i++)
		dr_covid[i]->print_doctor();
	cout << endl;
}

void corona::to_nurse()
{
	for (int i = 0; i < size_nu; i++)
		nu_covid[i]->print_nurse();
	cout << endl;
}

void corona::to_sick()
{
	for (int i = 0; i < size_sk; i++)
		sk_covid[i]->print_sick();
	cout << endl;
	
}


void corona::new_nurse(nurse* nu)//enter a new nurse to the department
{
	cout << "Enter nurse details: \n";
	string name;
	cout << "nurse name: ";
	cin >> name;

	string last_name;
	cout << "nurse last name: ";
	cin >> last_name;

	string id;
	cout << "nurse ID: ";
	cin >> id;

	int seniority_years;
	cout << "seniority years: ";
	cin >> seniority_years;

	string name_of_hospital;
	cout << "name of hospital: ";
	cin >> name_of_hospital;

	int training_and_courses;
	cout << "number of training courses: ";
	cin >> training_and_courses;

	nu->set_an_arguments(name, last_name, id, seniority_years, name_of_hospital, training_and_courses);


}

void corona::check_excelence()
{
	int i;
	if (size_dr > 0) {
		for ( i = 0; i < size_dr; i++)
		{
			if (dr_covid[i]->get_excellence() != false)
				dr_covid[i]->print_doctor();

		}
		cout << endl;
		for (i = 0; i < size_dr; i++)
		{
			if (nu_covid[i]->get_excellence() != false)
				nu_covid[i]->print_nurse();

		}
		cout << endl;


	}
		

}


void corona::new_patient(sick* pa)//enter a new patient to the department
{
	cout << "Enter patient details: \n";

	string name;
	cout << "patient name: ";
	cin >> name;

	string last_name;
	cout << "patient last name: ";
	cin >> last_name;

	string id;
	cout << "patient ID: ";
	cin >> id;

	
	string name_of_hospital;
	cout << "name of hospital: ";
	cin >> name_of_hospital;

	int num_of_covid_test;
	cout << "number  of corona tests : ";
	cin >> num_of_covid_test;

	int num_of_N_tests;
	cout << "number of negtive tests: ";
	cin >> num_of_N_tests;

	pa->set_an_arguments(name, last_name, id, name_of_hospital, num_of_covid_test, num_of_N_tests);


}
// get function to variables
int corona::get_size_dr() const
{
	return size_dr;
}

int corona::get_size_nu() const
{
	return size_nu;
}

int corona::get_size_sk() const
{
	return size_sk;
}

doctor** corona::get_doctor() const
{
	return dr_covid;
}

nurse** corona::get_nurse() const
{
	return nu_covid;
}

sick** corona::get_sick() const
{
	return sk_covid;
}

string corona::get_name_of_hospital()
{
	return name_of_hospital;
}

void corona::nurse_lower_salary() {//get nurse lower salary

	int i;
	int min_salary= nu_covid[0]->get_salary();
	for (i = 1; i < size_nu; i++) {
		if (nu_covid[i]->get_salary() < min_salary)
		{

			
			min_salary = nu_covid[i]->get_salary();

		}

	}

	for (i = 0; i < size_nu; i++) {
		
		if (nu_covid[i]->get_salary() == min_salary) {
			nu_covid[i]->print_nurse();
			cout << endl;
		}


	}



}
