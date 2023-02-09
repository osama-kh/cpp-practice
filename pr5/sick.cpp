#include "sick.h"
sick::sick() :person()//defaulte constructor
{
	name_of_hospital = "unknown";
	num_of_covid_test = 0;
	num_of_N_tests = 0;
}
sick::sick(string name, string last_name, string id, string name_of_hospital, int num_of_covid_test, int num_of_N_tests)
:person(name, last_name, id)
{
	set_name_of_hospital(name_of_hospital);
	set_num_of_covid_test(num_of_covid_test);
	set_num_of_N_tests(num_of_N_tests);

}
sick::~sick()
{
}

void sick::test_case()//to add a new test to the pateint
{

	num_of_covid_test += 1;
	num_of_N_tests += 1;
	

}

int sick::number_of_nigitive_tests()
{
	return num_of_N_tests;
}

void sick::print_sick()//print pateint details
{
	cout << "------ patient details ------\n";
	person::print_p();
	cout << "name of hospital: " << name_of_hospital << endl;
	cout << "number of covid tests  : " << num_of_covid_test << endl;
	cout << "number of negative: " << num_of_N_tests << endl;
}
//get and set functions
void sick::set_name_of_hospital(const string name_of_hospital)
{
	this->name_of_hospital = name_of_hospital;
}

void sick::set_num_of_covid_test(const int num_of_covid_test)
{
	this->num_of_covid_test = num_of_covid_test;
}

void sick::set_num_of_N_tests(const int num_of_N_tests)
{
	this->num_of_N_tests = num_of_N_tests;
}

string sick::get_name_of_hospital()
{
	return name_of_hospital;
}

int sick::get_num_of_covid_test()
{
	return num_of_covid_test;
}

int sick::get_num_of_N_tests()
{
	return num_of_N_tests;
}

void sick::set_an_arguments(const string name, const string last_name, const string id, const string name_of_hospital, const int num_of_covid_test, const int num_of_N_tests)
{
	set_name(name);
	set_last_name(last_name);
	set_id(id);
	set_name_of_hospital(name_of_hospital);
	set_name_of_hospital(name_of_hospital);
	set_num_of_covid_test(num_of_covid_test);
	set_num_of_N_tests(num_of_N_tests);
}
