#include<iostream>
#include<string.h>
using namespace std;
#include "number.h"




int main() {
	// the enterd data from the user
	int numx[] = { 1,2,3,4,5,6 },
	numy[] = { 1,2,3,4,5,6 },
	numz[] = { 1,2,2,3,2,2,1 },
	numw[] = { 1,5 },
	numv[] = { 2,8,4,4,7 },
	numr[] = { 2,3 };

	Number num1(numx, 6, false);
	Number num2(numy, 6, true);
	Number num3(numw, 2, true);
	Number num4(numv, 5, true);
	Number num5(numr, 2, true);

	cout << endl << endl;
	// geting the enterd data
	cout << "------input------" << endl;
	cout << "Enter Number:";  num1.print_number(); cout << endl;
	cout << "Enter Digits:" << num1.get_Number_of_digits() << endl;
	// print the data
	cout << "------output------" << endl;
	cout << "The Number:"; num1.print_number(); cout << endl;
	cout << endl;
	// updating the sympol of the number and check if its prime, and the sum of digits ,palindrome and if the opjects are equal
	cout << "------input------" << endl << "update sign" << endl << endl;;

	cout << "------output------" << endl;

	cout << "The Number:";
	num1.change_symbol();
	num1.print_number(); cout << endl;

	cout << "The palindrome:";
	if (num1.palindrome() == true)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << "sum of digits:" << num1.sum_of_digits() << endl;
	cout << "Number is equal to :";

	if (num1.isEqual(num2) == true)
		cout << "True" << endl;
	else 		cout << "False" << endl;
	cout << endl;
	// change the number
	cout << "------input------" << endl;
	cout << "update Number:";
	num1.change_number(numz, 7);
	num1.print_number(); cout << endl;
	cout << endl;
	// check if the number palindrome , the sum and substract and divid of opjects 
	cout << "------output------" << endl;
	cout << "The palindrome:";
	if (num1.palindrome() == true)
		cout << "True" << endl;
	else 		cout << "False" << endl;
	cout << "sum of digits:" << num1.sum_of_digits() << endl;

	num1.print_number();
	cout << "+ ";
	num3.print_number();
	cout << " = ";
	num1.Add(num3).print_number();
	cout << endl;

	num1.print_number(); cout << " - "; num3.print_number(); cout << " = "; num1.sub(num3).print_number();	cout << endl;
	num1.print_number(); if (num1.prime() == true)
		cout << " is a prime number" << endl;
	else 		cout << " is not a prime number" << endl;

	num1.print_number(); if (num1.isDivided(num4) == true) {
		cout << "  divides completely by ";
		num4.print_number();
		cout << endl;
	}
	else {
		cout << " not divides completely by ";
		num4.print_number();
		cout << endl;
	}

	num1.print_number(); if (num1.isDivided(num5) == true) {
		cout << "  divides completely by ";
		num5.print_number();
		cout << endl;
	}
	else {
		cout << " not divides completely by ";
		num5.print_number();
		cout << endl;
	}




	int stop;
	cin >> stop;


	return 0;
}