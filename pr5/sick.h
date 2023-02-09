#pragma once
#include "person.h"
class sick :public person
{
private:
	string name_of_hospital;
	int num_of_covid_test;
	int num_of_N_tests;
public:
	sick();
	sick(string name, string last_name, string id, string name_of_hospital, int num_of_covid_test, int num_of_N_tests);
	~sick();
	void test_case();
	int number_of_nigitive_tests();
	void print_sick();

	void set_name_of_hospital(const string);
	void set_num_of_covid_test(const int);
	void set_num_of_N_tests(const int);

	string get_name_of_hospital();
	int get_num_of_covid_test();
	int get_num_of_N_tests();

	void set_an_arguments(const string name, const string last_name, const string id, const string name_of_hospital, const int num_of_covid_test, const int num_of_N_tests);


};

