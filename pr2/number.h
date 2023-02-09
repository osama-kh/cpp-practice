#pragma once
#include<iostream>
#include<string.h>
using namespace std;




class Number {// the class of number
private:

	int Number_of_digits;
	int* Num;
	bool symbol;

public:
	Number();
	Number(int* Num, int Number_of_digits, bool symbol);
	Number(const Number& other);
	~Number();



	int* get_Num()const;
	int  get_Number_of_digits()const;
	bool get_symbol()const;



	void change_symbol();
	void change_number(int* Num, int Number_of_digits);
	void print_number();
	int  sum_of_digits();
	int switch_arr2intger()const;
	bool palindrome();
	bool prime();
	bool isEqual(const Number& other);
	bool isDivided(const Number& other);

	Number Add(const Number& other);
	Number sub(const Number& other);
};