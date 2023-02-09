#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class person
{
private:
	string name;
	string last_name;
	string id;
public:
	person();
	person(string, string, string);
	~person();
	void print_p();
	void equal(const person& other);
	person& operator =(const person& other);
	void set_name(const string);
	void set_last_name(const string);
	void set_id(const string);
	string get_name();
	string get_last_name();
	string get_id();

};

