#include "person.h"

person::person()//defaulte constructor
{
	string x = "unknown";
	name = x;
	last_name = x;
	id = x;
}

person::person(string name, string last_name, string id)
{
	set_name(name);
	set_last_name(last_name);
	set_id(id);
}

person::~person()
{
}

void person::print_p()//print person details
{
	//cout << "person details:\n";
	cout << "name: " << name << endl;
	cout << "last name: " << last_name << endl;
	cout << "id: " << id << endl;
}

void person::equal(const person& other)
{
	this->name = other.name;
	this->last_name = other.last_name;
	this->id = other.id;
}

person& person::operator=(const person& other)
{

	this->name = other.name;
	this->last_name = other.last_name;
	this->id = other.id;
	 
	return *this;
}
//set and get functions
void person::set_name(const string name)
{
	this->name = name;
}

void person::set_last_name(const string last_name)
{
	this->last_name = last_name;
}

void person::set_id(const string id)
{
	this->id = id;
}

string person::get_name()
{
	return name;
}

string person::get_last_name()
{
	return last_name;
}

string person::get_id()
{
	return id;
}
