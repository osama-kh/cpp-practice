#pragma once
#include "person.h"

class employee :public person
{
private:
	int seniority_years;
	int salary;
	bool excellence;
public:
	employee();
	employee(string name, string last_name, string id,int seniority_years, int salary);
	~employee();

	employee& operator=(const employee& other);
	void equal_e(const employee& other);
	int get_seniority_years();
	int get_salary();
	bool get_excellence();
	void set_seniority_years(const int);
	void set_salary(const int);
	void set_excellence( bool);
	void check_excellence(bool);

	virtual void print_employee();

};

