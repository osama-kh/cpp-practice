#include "CoronaVirusCrisisManagement.h"

void CoronaVirusCrisisManagement::add_worker_N(nurse* doc)// add doctor to worker array
{
	int i;
	employee** help;
	help = new employee * [size_w];
	for (i = 0; i < size_w; i++) {
		help[i] = workers[i];
	}
	int old = size_w;
	size_w += 1;
	workers = new employee * [size_w];
	for (i = 0; i < old; i++)
		workers[i] = help[i];
	workers[size_w - 1] = doc;
}

void CoronaVirusCrisisManagement::add_worker_d(doctor* doc) // add nurse to worker array
{
	int i;
	employee** help;
	help = new employee * [size_w];
	for (i = 0; i < size_w; i++) {
		help[i] = workers[i];
	}
	int old = size_w;
	size_w += 1;
	workers = new employee * [size_w];
	for (i = 0; i < old; i++)
		workers[i] = help[i];
	workers[size_w - 1] = doc;
}

void CoronaVirusCrisisManagement::add_Patient_arr(sick* doc) // add patient to patient array
{
	int i;
	sick** help;
	help = new sick * [size_p];
	for (i = 0; i < size_p; i++) {
		help[i] = Patient[i];
	}
	int old = size_p;
	size_p+= 1;
	Patient = new sick * [size_p];
	for (i = 0; i < old; i++)
		Patient[i] = help[i];
	Patient[size_p - 1] = doc;
}

void CoronaVirusCrisisManagement::new_depart(corona* doc)// make a new department
{
	int i;
	corona** help;
	help = new corona * [size_c];
	for (i = 0; i < size_c; i++) {
		help[i] = covid[i];
	}
	int old = size_c;
	size_c += 1;
	covid = new corona * [size_c];
	for (i = 0; i < old; i++)
		covid[i] = help[i];
	covid[size_c - 1] = doc;
}

//function to play the options

void CoronaVirusCrisisManagement::AddNurse()
{
	string name_of_hospital;

		int i;
		nurse* add;
		add = new nurse();
		cout << "enter the hospital name to add the nurse to the corona department:";

		cin >> name_of_hospital;


		corona* help;
		help = new corona(name_of_hospital);
		for (i = 0; i < size_c; i++) {
			if (covid[i]->get_name_of_hospital() == name_of_hospital) {

				help = covid[i];
			}
		}
		help->new_nurse(add);
		for (i = 0; i < size_c; i++) {

			if (!(workers[i]->get_id() == add->get_id())) {
				help->AddNurse(add);

				add_worker_N(add);
				help->print_corona();
			}

			if (workers[i]->get_id() == add->get_id())
				cout << "\nthe Nurse you entered already exist!\n";



		}

}

void CoronaVirusCrisisManagement::AddDoctor()
{
	string name_of_hospital;
	int j;
	doctor* add2;
	add2 = new doctor();
	cout << "enter the hospital name to add the doctor to the corona department:";

	cin >> name_of_hospital;
	corona* help2;
	help2 = new corona(name_of_hospital);
	for (j = 0; j < size_c; j++) {
		if (covid[j]->get_name_of_hospital() == name_of_hospital) {

			help2 = covid[j];
		}
	}
	help2->new_doctor(add2);
	for (j = 0; j < size_c; j++) {

		if (!(workers[j]->get_id() == add2->get_id())) {
			help2->AddDoctor(add2);

			add_worker_d(add2);
			help2->print_corona();
		}

		if (workers[j]->get_id() == add2->get_id())
			cout << "\nthe doctor you entered already exist!\n";

	}
}

void CoronaVirusCrisisManagement::AddDepartment()
{
	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "AssafHarofeh", "Soroka" };

	cout << "choose one of the following hospitals to add a new corona department: " << endl;
	cout << "1." << HospitalNames[0] << endl;
	cout << "2." << HospitalNames[1] << endl;
	cout << "3." << HospitalNames[2] << endl;
	cout << "4." << HospitalNames[3] << endl;
	cout << "5." << HospitalNames[4] << endl;

	int i,j=0;
	corona* add3;
	add3 = new corona();
	new_depart(add3);
	
	for ( i = 0; i < size_c; i++) {
		if (covid[i] == add3)
			covid[i]->print_corona();
	}
	int new_size_w;
	size_p = 0;
	new_size_w=size_w + add3->get_size_dr() + add3->get_size_nu();
	employee** help;
	help= new employee * [size_w];
	//help = workers;
	for (i = 0; i < size_w; i++) {
		help[i]=workers[i] ;
	}
	workers = new employee * [new_size_w];
	for (i = 0; i < size_w; i++) {
		workers[i] = help[i];
	}
	j = size_w;
	for (i = 0; i < add3->get_size_dr(); i++) {
		workers[j++] = add3->get_doctor()[i];

	}
	for (i = 0; i < add3->get_size_nu(); i++) {
		workers[j++] = add3->get_nurse()[i];


	}
	size_w = new_size_w;

}

void CoronaVirusCrisisManagement::PrintDepartmentDetails()
{
	cout << "enter the hospital name to show the corona department data:";
	string name_of_hospital;
	int i;
	cin >> name_of_hospital;

	corona* help4;
	help4 = new corona(name_of_hospital);
	for (i = 0; i < size_c; i++) {
		if (covid[i]->get_name_of_hospital() == name_of_hospital)
			help4 = covid[i];
	}
	help4->print_corona();
	help4->to_sick();

}

void CoronaVirusCrisisManagement::PrintDoctorsDetails()
{
	for (int i = 0; i < size_c; i++) {
		covid[i]->to_doctor();
		cout << endl;
	}

}

void CoronaVirusCrisisManagement::PrintSalary()
{
	int i;
	string id;
	employee* help;
	help = new employee();
	cout << "\nenter th ID number to get info about the person's salar:\n ";

	cin >> id;
	for (i = 0; i < size_w; i++) {
		if (workers[i]->get_id() == id) {
			help = workers[i];

	
		}
	}
	cout << "Name: "<<help->get_name() <<" "<< help->get_last_name() << endl;
	cout << "Id: "<< help->get_id()<<endl;
	cout << "the salary: "<< help->get_salary()<<endl<<endl;

}

void CoronaVirusCrisisManagement::AddPatient()
{
	string name_of_hospital;
	int j;
	sick* add2;
	add2 = new sick();
	cout << "enter the hospital name to add the Patient to the corona department:";

	cin >> name_of_hospital;
	corona* help2;
	help2 = new corona(name_of_hospital);
	for (j = 0; j < size_c; j++) {
		if (covid[j]->get_name_of_hospital() == name_of_hospital) {

			help2 = covid[j];
		}
	}
	help2->new_patient(add2);
	for (j = 0; j < size_c; j++) {

		if (!(Patient[j]->get_id() == add2->get_id())) {
			help2->AddPatient(add2);

			add_Patient_arr(add2);
			help2->print_corona();
			help2->to_sick();
		}

		else
			cout << "\nthe Patient you entered already exist!\n";

	}


}

void CoronaVirusCrisisManagement::AddCoronaTestToPatientById()
{
	int i;
	string id;
	cout << "\n Enter the patient id: ";
	cin >> id;
	sick* help;
	help = new sick();
	for (i = 0; i < size_p; i++) {
		if (Patient[i]->get_id() == id)
			help = Patient[i];
		else cout << " the patient you entered doesn't exsit!\n ";
	}
	
	bool test_case;
	cout << " enter the case of the test (negtive=1/pisitive=0)\n";
	cin >> test_case;
	if (test_case == true) {
		help->test_case();

	}
	for (int j = 0; j < size_c; j++) {

		if ((Patient[j]->get_id() == help->get_id())) {

			Patient[j]->print_sick();
		}

	}

	cout << endl;
}

void CoronaVirusCrisisManagement::Releasing()
{
	cout << "\n -----------the paitents erase process is completed-----------\n ";
	sick* help;
	help = new sick();
	int i;
	for (i = 0; i < size_p; i++) {
		if (Patient[i]->get_num_of_N_tests() >= 2) {
			Patient[i] = help;
		}
	}
	for (i = 0; i < size_p; i++) 
			covid[i]->remove_Patient(help);

}

void CoronaVirusCrisisManagement::PrintExcellenceWorker()
{
	cout << "\n ------------show the excellent workers------------ \n";

	int i;
	for (i = 0; i < size_c; i++) {
		
		covid[i]->check_excelence();
		
	}
}

void CoronaVirusCrisisManagement::PrintNurseWithSmallestSalary()
{
	cout << "\n ------------show Nurse With Smallest Salary------------ \n";
	int i;
	for (i = 0; i < size_c; i++) {
		covid[i]->nurse_lower_salary();


	}
	cout << endl;
	

}

CoronaVirusCrisisManagement::CoronaVirusCrisisManagement()//defaulte constructor
{
	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "AssafHarofeh", "Soroka" };
	cout << "choose one of the following hospitals to add a new corona department: " << endl;
	cout << "1." << HospitalNames[0] << endl;
	cout << "2." << HospitalNames[1] << endl;
	cout << "3." << HospitalNames[2] << endl;
	cout << "4." << HospitalNames[3] << endl;
	cout << "5." << HospitalNames[4] << endl;
	int i,j=0;
	size_c = 1;
	covid = new corona*[size_c];
	covid[0] = new corona();
	
	size_p = 0;
	size_w = covid[0]->get_size_dr()+covid[0]->get_size_nu();
	workers = new employee * [size_w];
	for (i = 0; i < covid[0]->get_size_dr(); i++) {
		workers[j++] = covid[0]->get_doctor()[i];

	}
	for (i = 0; i < covid[0]->get_size_nu(); i++) {
		workers[j++] = covid[0]->get_nurse()[i];
		
	}
	size_p = 0;
	Patient = new sick * [size_p];
	*Patient = new sick();

covid[0]->print_corona();
covid[0]->to_sick();


}

CoronaVirusCrisisManagement::~CoronaVirusCrisisManagement()
{
	
	delete[] workers;
	delete[] covid;
	delete[] Patient;
}


void CoronaVirusCrisisManagement::printOptions() {
	cout << "Menu: " << endl;
	cout << "1. ADD NURSE" << endl;
	cout << "2. ADD DOCTOR" << endl;
	cout << "3. ADD DEPARTMENT" << endl;
	cout << "4. PRINT DEPARTMENT DETAILS" << endl;
	cout << "5. PRINT DOCTORS DETAILS" << endl;
	cout << "6. PRINT SALARY BY ID" << endl;
	cout << "7. ADD PATIENT" << endl;
	cout << "8. ADD CORONA TEST TO PATIENT ID" << endl;
	cout << "9. RELEASING PATIENTS" << endl;
	cout << "10. PRINT EXCELLENCE WORKER" << endl;
	cout << "11. PRINT NURSE DETAILS WITH SMALLEST SALARY" << endl;
	cout << "12. EXIT" << endl;
}




void CoronaVirusCrisisManagement::Menu() {
	int option;
	bool run = true;
	while (run) {
		printOptions();
		cin >> option;
		switch (option) {
		case 1:
			AddNurse();
			break;
		case 2:
			AddDoctor();
			break;
		case 3:
			AddDepartment();
			break;
		case 4:
			PrintDepartmentDetails();
			break;
		case 5:
			PrintDoctorsDetails();
			break;
		case 6:
			PrintSalary();
			break;
		case 7:
			AddPatient();
			break;
		case 8:
			AddCoronaTestToPatientById();
			break;
		case 9:
			Releasing();
			break;
		case 10:
			PrintExcellenceWorker();
			break;
		case 11:
			PrintNurseWithSmallestSalary();
			break;
		case 12:
			exit(1);
			run = false;
			break;
		}
	}
}