#include "Employee.h"

// defaulte constructor
Employee::Employee() {

	string x = "unknown";
	strcpy(full_name, x);
	strcpy(Id, "000000000");
	strcpy(family_name, x);
	Salary = 0;
	hours = 0;

}

///////////////////////////////////////////////////////////////////////////////////
// constructor to update the class values
Employee::Employee(char full_name[], char Id[], char family_name[], double Salary,int hours):hours(hours) {

	try {
		if (strlen(Id) != 9 || Salary < 0) {
			throw exception();
		}

		strcpy(this->full_name, full_name);
		strcpy(this->Id, Id);
		strcpy(this->family_name, family_name);
		this->Salary = Salary;

	}

	catch (exception e) {

		if (strlen(Id) != 9) {
			cout << "The Id not true please tre again";
			Id = new char[10];
			cout <<endl<<"Enter the a Id but 9 number ";
			for (int i = 0; i < 9; i++) {
				cin >> Id[i];
			}
			Id[9] ='\0';

		}

		while (Salary < 0) {
			cout << "The salary isn't true please try again\n";
			cout <<endl<< "Enter the a salary: ";
			cin >> Salary;
		}

		strcpy(this->full_name, full_name);
		strcpy(this->Id, Id);
		strcpy(this->family_name, family_name);
		this->Salary = Salary;
	}
}

///////////////////////////////////////////////////////////////////////////////////
//Operator > 
bool Employee:: operator >(const Employee&obj)const {
	if (obj.Salary < this->Salary) {
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////
 //cout operator
ostream& operator<<(ostream&out, const  Employee&obj) {

	out << endl<<"The name is: "<<obj.full_name << endl;
	out <<"The family name is: " <<obj.family_name << endl;
	out <<"The id is: " <<obj.Id << endl;
	out << "The salary is: "<<obj.Salary << endl;
	out <<"The houss is: "<<obj.hours << endl;
	return out;
}

///////////////////////////////////////////////////////////////////////////////////
//test equation operator
bool Employee:: operator ==(const Employee&obj)const {
	for (int i = 0; i < 9; i++) {
		if (obj.Id[i] != Id[i]) {
			return false;
		}
	}
	return true;
}

