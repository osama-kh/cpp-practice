_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;

class Employee {

private:
	char full_name[50];
	char Id[50];
	char family_name[50];
	int hours;
	double Salary;
	

public:
	Employee(char[], char[], char[],double,int);
	Employee();
	bool operator >(const Employee&)const;
	bool operator ==(const Employee&)const;
	friend ostream& operator<<(ostream&, const Employee&);

};



